#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
// EXTRA BEGIN
typedef struct DartCObject *WireSyncRust2DartDco;
typedef struct WireSyncRust2DartSse {
  uint8_t *ptr;
  int32_t len;
} WireSyncRust2DartSse;

typedef int64_t DartPort;
typedef bool (*DartPostCObjectFnType)(DartPort port_id, void *message);
void store_dart_post_cobject(DartPostCObjectFnType ptr);
// EXTRA END
typedef struct _Dart_Handle* Dart_Handle;

typedef struct wire_cst_list_prim_u_8_strict {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_strict;

typedef struct wire_cst_sp_header_checkpoint {
  uint32_t height;
  struct wire_cst_list_prim_u_8_strict *hash;
} wire_cst_sp_header_checkpoint;

typedef struct wire_cst_unified_coin_view {
  int32_t source;
  struct wire_cst_list_prim_u_8_strict *outpoint;
  uint64_t amount_sat;
  uint32_t *height;
  int32_t status;
} wire_cst_unified_coin_view;

typedef struct wire_cst_list_unified_coin_view {
  struct wire_cst_unified_coin_view *ptr;
  int32_t len;
} wire_cst_list_unified_coin_view;

typedef struct wire_cst_RecipientView_Sp {
  struct wire_cst_list_prim_u_8_strict *address;
  uint64_t amount_sat;
  uint32_t *label;
  bool is_max;
} wire_cst_RecipientView_Sp;

typedef struct wire_cst_RecipientView_Standard {
  struct wire_cst_list_prim_u_8_strict *address;
  uint64_t amount_sat;
  bool is_max;
} wire_cst_RecipientView_Standard;

typedef union RecipientViewKind {
  struct wire_cst_RecipientView_Sp Sp;
  struct wire_cst_RecipientView_Standard Standard;
} RecipientViewKind;

typedef struct wire_cst_recipient_view {
  int32_t tag;
  union RecipientViewKind kind;
} wire_cst_recipient_view;

typedef struct wire_cst_list_recipient_view {
  struct wire_cst_recipient_view *ptr;
  int32_t len;
} wire_cst_list_recipient_view;

typedef struct wire_cst_tx_simulation {
  struct wire_cst_list_unified_coin_view *inputs;
  struct wire_cst_list_recipient_view *outputs;
  uint64_t fee_sat;
  uint64_t change_sat;
  uint64_t *change_dust_threshold;
} wire_cst_tx_simulation;

typedef struct wire_cst_list_prim_u_8_loose {
  uint8_t *ptr;
  int32_t len;
} wire_cst_list_prim_u_8_loose;

typedef struct wire_cst_sp_coin_view {
  struct wire_cst_list_prim_u_8_strict *outpoint;
  uint64_t amount_sat;
  uint32_t *height;
  bool is_spendable;
  struct wire_cst_list_prim_u_8_strict *label;
} wire_cst_sp_coin_view;

typedef struct wire_cst_list_sp_coin_view {
  struct wire_cst_sp_coin_view *ptr;
  int32_t len;
} wire_cst_list_sp_coin_view;

typedef struct wire_cst_sp_payment_view {
  struct wire_cst_list_prim_u_8_strict *txid;
  int32_t direction;
  int32_t status;
  uint64_t amount_sat;
  uint64_t *fee_sat;
  uint32_t *height;
  uint64_t *timestamp;
  struct wire_cst_list_prim_u_8_strict *label;
} wire_cst_sp_payment_view;

typedef struct wire_cst_list_sp_payment_view {
  struct wire_cst_sp_payment_view *ptr;
  int32_t len;
} wire_cst_list_sp_payment_view;

typedef struct wire_cst_regtest_defaults {
  bool is_ok;
  struct wire_cst_list_prim_u_8_strict *error;
  struct wire_cst_list_prim_u_8_strict *blindbit_url;
  struct wire_cst_list_prim_u_8_strict *p2p_node;
  struct wire_cst_list_prim_u_8_strict *electrum_url;
} wire_cst_regtest_defaults;

typedef struct wire_cst_sp_balance_view {
  uint64_t confirmed_sat;
  uint64_t total_unified_sat;
  uint32_t *last_scanned_height;
} wire_cst_sp_balance_view;

typedef struct wire_cst_SpError_SimulationDrifted {
  struct wire_cst_list_prim_u_8_strict *detail;
} wire_cst_SpError_SimulationDrifted;

typedef struct wire_cst_SpError_Other {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_SpError_Other;

typedef union SpErrorKind {
  struct wire_cst_SpError_SimulationDrifted SimulationDrifted;
  struct wire_cst_SpError_Other Other;
} SpErrorKind;

typedef struct wire_cst_sp_error {
  int32_t tag;
  union SpErrorKind kind;
} wire_cst_sp_error;

typedef struct wire_cst_SpNotification_ScanStarted {
  uint32_t from;
  uint32_t to;
} wire_cst_SpNotification_ScanStarted;

typedef struct wire_cst_SpNotification_ScanReceiveProgress {
  uint32_t current;
  uint32_t end;
} wire_cst_SpNotification_ScanReceiveProgress;

typedef struct wire_cst_SpNotification_ScanStopped {
  uint32_t *last_scanned;
  uint32_t *last_spend;
} wire_cst_SpNotification_ScanStopped;

typedef struct wire_cst_SpNotification_ScanFailed {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_SpNotification_ScanFailed;

typedef struct wire_cst_SpNotification_NewOutput {
  struct wire_cst_list_prim_u_8_strict *outpoint;
  uint64_t amount_sat;
} wire_cst_SpNotification_NewOutput;

typedef struct wire_cst_SpNotification_OutputSpent {
  struct wire_cst_list_prim_u_8_strict *outpoint;
} wire_cst_SpNotification_OutputSpent;

typedef struct wire_cst_SpNotification_Broadcasted {
  struct wire_cst_list_prim_u_8_strict *txid;
} wire_cst_SpNotification_Broadcasted;

typedef struct wire_cst_SpNotification_BroadcastFailed {
  struct wire_cst_list_prim_u_8_strict *message;
} wire_cst_SpNotification_BroadcastFailed;

typedef struct wire_cst_SpNotification_ElectrumTx {
  int32_t kind;
  struct wire_cst_list_prim_u_8_strict *txid;
  uint64_t amount_sat;
  uint32_t *height;
} wire_cst_SpNotification_ElectrumTx;

typedef struct wire_cst_SpNotification_ScanSpendProgress {
  uint32_t current;
  uint32_t end;
} wire_cst_SpNotification_ScanSpendProgress;

typedef struct wire_cst_SpNotification_HeaderProgressStarted {
  int32_t phase;
  uint32_t start;
  uint32_t end;
} wire_cst_SpNotification_HeaderProgressStarted;

typedef struct wire_cst_SpNotification_HeaderProgress {
  int32_t phase;
  uint32_t current;
  uint32_t end;
} wire_cst_SpNotification_HeaderProgress;

typedef struct wire_cst_SpNotification_HeaderProgressCompleted {
  int32_t phase;
} wire_cst_SpNotification_HeaderProgressCompleted;

typedef struct wire_cst_SpNotification_HeaderProgressFailed {
  int32_t phase;
} wire_cst_SpNotification_HeaderProgressFailed;

typedef struct wire_cst_SpNotification_Reorg {
  uint32_t fork_height;
} wire_cst_SpNotification_Reorg;

typedef union SpNotificationKind {
  struct wire_cst_SpNotification_ScanStarted ScanStarted;
  struct wire_cst_SpNotification_ScanReceiveProgress ScanReceiveProgress;
  struct wire_cst_SpNotification_ScanStopped ScanStopped;
  struct wire_cst_SpNotification_ScanFailed ScanFailed;
  struct wire_cst_SpNotification_NewOutput NewOutput;
  struct wire_cst_SpNotification_OutputSpent OutputSpent;
  struct wire_cst_SpNotification_Broadcasted Broadcasted;
  struct wire_cst_SpNotification_BroadcastFailed BroadcastFailed;
  struct wire_cst_SpNotification_ElectrumTx ElectrumTx;
  struct wire_cst_SpNotification_ScanSpendProgress ScanSpendProgress;
  struct wire_cst_SpNotification_HeaderProgressStarted HeaderProgressStarted;
  struct wire_cst_SpNotification_HeaderProgress HeaderProgress;
  struct wire_cst_SpNotification_HeaderProgressCompleted HeaderProgressCompleted;
  struct wire_cst_SpNotification_HeaderProgressFailed HeaderProgressFailed;
  struct wire_cst_SpNotification_Reorg Reorg;
} SpNotificationKind;

typedef struct wire_cst_sp_notification {
  int32_t tag;
  union SpNotificationKind kind;
} wire_cst_sp_notification;

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_backend_online(uintptr_t that);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_block_height(uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_broadcast(int64_t port_,
                                                                       uintptr_t that,
                                                                       struct wire_cst_list_prim_u_8_strict *tx_hex);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_clear_scan_state(int64_t port_,
                                                                              uintptr_t that);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_coins(uintptr_t that);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_confirmed_balance(uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_create_from_mnemonic(int64_t port_,
                                                                                  struct wire_cst_list_prim_u_8_strict *name,
                                                                                  int32_t network,
                                                                                  struct wire_cst_list_prim_u_8_strict *mnemonic,
                                                                                  struct wire_cst_list_prim_u_8_strict *blindbit_url,
                                                                                  struct wire_cst_list_prim_u_8_strict *electrum_url,
                                                                                  struct wire_cst_list_prim_u_8_strict *data_dir,
                                                                                  uint32_t *birthday_height,
                                                                                  uint64_t *dust_limit,
                                                                                  struct wire_cst_sp_header_checkpoint *header_checkpoint);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_create_from_mnemonic_with_scan_runtime(int64_t port_,
                                                                                                    struct wire_cst_list_prim_u_8_strict *name,
                                                                                                    int32_t network,
                                                                                                    struct wire_cst_list_prim_u_8_strict *mnemonic,
                                                                                                    struct wire_cst_list_prim_u_8_strict *blindbit_url,
                                                                                                    struct wire_cst_list_prim_u_8_strict *electrum_url,
                                                                                                    struct wire_cst_list_prim_u_8_strict *data_dir,
                                                                                                    uint32_t *birthday_height,
                                                                                                    uint64_t *dust_limit,
                                                                                                    uint32_t *fetch_concurrency_factor,
                                                                                                    uint32_t *match_concurrency_factor,
                                                                                                    struct wire_cst_sp_header_checkpoint *header_checkpoint);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_dispose(int64_t port_, uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_finalize_psbt(int64_t port_,
                                                                           uintptr_t that,
                                                                           struct wire_cst_tx_simulation *simulation);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_init(uintptr_t that,
                                                                                  struct wire_cst_list_prim_u_8_strict *sink);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_is_scanning(uintptr_t that);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_last_scanned_height(uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_load(int64_t port_,
                                                                  struct wire_cst_list_prim_u_8_strict *name,
                                                                  struct wire_cst_list_prim_u_8_strict *data_dir,
                                                                  struct wire_cst_sp_header_checkpoint *header_checkpoint);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_min_birthday_height(uintptr_t that);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_name(uintptr_t that);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_network(uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_new_taproot_address(int64_t port_,
                                                                                 uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_prepare_psbt(int64_t port_,
                                                                          uintptr_t that,
                                                                          struct wire_cst_list_recipient_view *recipients,
                                                                          uint64_t feerate_sat_vb,
                                                                          uint64_t *change_dust_threshold);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_restamp_missing_timestamps(uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_restart_electrum(int64_t port_,
                                                                              uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_scan_once(int64_t port_,
                                                                       uintptr_t that,
                                                                       uint32_t *start_height);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_set_blindbit_url(uintptr_t that,
                                                                                              struct wire_cst_list_prim_u_8_strict *url);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_set_electrum_url(uintptr_t that,
                                                                                              struct wire_cst_list_prim_u_8_strict *url);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_sign_psbt(int64_t port_,
                                                                       uintptr_t that,
                                                                       struct wire_cst_list_prim_u_8_loose *psbt);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_sp_address(uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_start_electrum(int64_t port_,
                                                                            uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_stop_scan(int64_t port_,
                                                                       uintptr_t that);

WireSyncRust2DartDco frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_unified_balance(uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_unified_coins(int64_t port_,
                                                                           uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_unified_history(int64_t port_,
                                                                             uintptr_t that);

void frbgen_bwk_dart_wire__crate__api__regtest__get_regtest_defaults(int64_t port_);

void frbgen_bwk_dart_wire__crate__api__sp_account__test_blindbit_url(int64_t port_,
                                                                     struct wire_cst_list_prim_u_8_strict *url);

void frbgen_bwk_dart_wire__crate__api__sp_account__test_electrum_url(int64_t port_,
                                                                     struct wire_cst_list_prim_u_8_strict *url);

void frbgen_bwk_dart_wire__crate__api__sp_account__validate_recipient_address(int64_t port_,
                                                                              struct wire_cst_list_prim_u_8_strict *address,
                                                                              int32_t network);

void frbgen_bwk_dart_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSpAccount(const void *ptr);

void frbgen_bwk_dart_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSpAccount(const void *ptr);

struct wire_cst_sp_header_checkpoint *frbgen_bwk_dart_cst_new_box_autoadd_sp_header_checkpoint(void);

struct wire_cst_tx_simulation *frbgen_bwk_dart_cst_new_box_autoadd_tx_simulation(void);

uint32_t *frbgen_bwk_dart_cst_new_box_autoadd_u_32(uint32_t value);

uint64_t *frbgen_bwk_dart_cst_new_box_autoadd_u_64(uint64_t value);

struct wire_cst_list_prim_u_8_loose *frbgen_bwk_dart_cst_new_list_prim_u_8_loose(int32_t len);

struct wire_cst_list_prim_u_8_strict *frbgen_bwk_dart_cst_new_list_prim_u_8_strict(int32_t len);

struct wire_cst_list_recipient_view *frbgen_bwk_dart_cst_new_list_recipient_view(int32_t len);

struct wire_cst_list_sp_coin_view *frbgen_bwk_dart_cst_new_list_sp_coin_view(int32_t len);

struct wire_cst_list_sp_payment_view *frbgen_bwk_dart_cst_new_list_sp_payment_view(int32_t len);

struct wire_cst_list_unified_coin_view *frbgen_bwk_dart_cst_new_list_unified_coin_view(int32_t len);
static int64_t dummy_method_to_enforce_bundling(void) {
    int64_t dummy_var = 0;
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_box_autoadd_sp_header_checkpoint);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_box_autoadd_tx_simulation);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_box_autoadd_u_32);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_box_autoadd_u_64);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_list_prim_u_8_loose);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_list_prim_u_8_strict);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_list_recipient_view);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_list_sp_coin_view);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_list_sp_payment_view);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_cst_new_list_unified_coin_view);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_rust_arc_decrement_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSpAccount);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_rust_arc_increment_strong_count_RustOpaque_flutter_rust_bridgefor_generatedRustAutoOpaqueInnerSpAccount);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__regtest__get_regtest_defaults);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_backend_online);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_block_height);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_broadcast);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_clear_scan_state);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_coins);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_confirmed_balance);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_create_from_mnemonic);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_create_from_mnemonic_with_scan_runtime);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_dispose);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_finalize_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_init);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_is_scanning);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_last_scanned_height);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_load);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_min_birthday_height);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_name);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_network);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_new_taproot_address);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_prepare_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_restamp_missing_timestamps);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_restart_electrum);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_scan_once);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_set_blindbit_url);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_set_electrum_url);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_sign_psbt);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_sp_address);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_start_electrum);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_stop_scan);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_unified_balance);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_unified_coins);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__SpAccount_unified_history);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__test_blindbit_url);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__test_electrum_url);
    dummy_var ^= ((int64_t) (void*) frbgen_bwk_dart_wire__crate__api__sp_account__validate_recipient_address);
    dummy_var ^= ((int64_t) (void*) store_dart_post_cobject);
    return dummy_var;
}
