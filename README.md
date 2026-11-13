# dart_bwk

A Dart/Flutter capability package exposing **Silent Payments** (BIP352) over the Rust
[`bwk`](https://github.com/pythcoiner/bwk) (Bitcoin Wallet Kit) crates, via
[`flutter_rust_bridge`](https://github.com/fzyzcjy/flutter_rust_bridge).

The Rust crate wraps `bwk-sp` / `bwk` / `bwk-tx` and surfaces a Silent Payments 
account API.

## How it is consumed

This package is aggregated by
[`bull_sdk`](https://github.com/SatoshiPortal/bull_sdk) alongside
the other capabilities (`lwk`, `boltz`, `ark`, `bbqr`, …). Apps depend on
`bull_sdk` and import
the SP bindings through its barrel:

```dart
import 'package:bull_sdk/bwk.dart';
```

The single generated `BullSdk` entrypoint initializes all capabilities, including
this one:

```dart
await BullSdk.init();
```

When built under the `bull_sdk` feature (`features = ["bull_sdk"]`), this crate's own
`frb_generated` module is cfg'd out and `bull_sdk`'s codegen owns the bindings. The
standalone
config (`flutter_rust_bridge.yaml`, entrypoint `BwkCore`) exists only for building
this crate in
isolation.

## Silent Payments from a BIP39 seed

`SpAccount.createFromSeed` and `createFromSeedWithScanRuntime` accept the 64 bytes of a BIP39 seed. Derive that seed with the mnemonic's language and passphrase before calling the bridge. The seed selects both the BIP352 account and its default taproot sub-account; English words without a passphrase retain the mnemonic constructor's account.

Recreate the account with the same seed and data directory when reopening it: signer material is not persisted. Before reopening, await `dispose()` and, only after it succeeds, await `release()` to consume the handle and release its resources. Do not reuse a released handle. If disposal fails, retain the handle and retry rather than reopening the account. The Rust bridge wipes its input copy on return; callers own their copies, and this does not guarantee erasure of every Dart or bridge allocation.

`deriveSpAddressFromSeed` derives the public account-0 address without opening storage. A caller can verify the expected identity before opening existing account data; seed input remains inside the custody boundary.

The aggregate SDK generates its Dart surface from this crate's Rust API. Standalone Dart and Rust bridge sources are versioned so Git consumers can build without running code generation inside their dependency cache. Regenerate them with flutter_rust_bridge_codegen 2.13.0 when the Rust API changes.

## Invariant: scan is user-triggered only

Silent Payments scanning never auto-starts. The rust-side checks live in 
`scripts/audit-sp-invariant.sh` and `rust/tests/{no_auto_scan_in_rust,no_continuous_in_dart}.rs`:
exactly one `start_scan()` call site (inside `scan_once()`), zero `scan_blocks()`
calls, and no continuous-scan mode in the generated Dart. The `continuous-scan`
cargo feature is guarded by a `compile_error!`.

## Layout

- `rust/src/api/` — the FFI surface: `sp_account.rs`, `types.rs`, `regtest.rs`.
- `rust/tests/` — invariant + regtest integration tests (`SP_NETWORK_TESTS=1`-gated).
- `scripts/audit-sp-invariant.sh` — rust-side no-autoscan audit.

## Build (standalone)

Flutter 3.50 / Dart 3.14 or later builds the Rust library through `hook/build.dart` and Native Assets. Android, Apple and desktop consumers no longer run CargoKit or download precompiled native binaries. Call `LibBwk.init()` to initialize the generated bridge using the registered Native Assets code asset. Apple packaging still requires verification with a full Xcode build.

```bash
cd rust
cargo build --features bull_sdk   # how the aggregator builds it
cargo test  --features bull_sdk
```
