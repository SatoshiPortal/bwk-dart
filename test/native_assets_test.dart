import 'package:bwk_dart/bwk_dart.dart';
import 'package:bwk_dart/src/generated/frb_generated.dart';
import 'package:flutter_test/flutter_test.dart';

void main() {
  test('loads the hook-built library without a path override', () async {
    await LibBwk.init();
    final address = await deriveSpAddressFromSeed(
      seed: List<int>.filled(64, 0),
      network: SpNetwork.signet,
    );
    expect(address.startsWith('tsp1'), isTrue);
    BwkCore.dispose();
  });
}
