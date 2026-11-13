import 'package:bwk_dart/bwk_dart.dart';
import 'package:material_ui/material_ui.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await LibBwk.init();
  final address = await deriveSpAddressFromSeed(
    seed: List<int>.filled(64, 0),
    network: SpNetwork.regtest,
  );
  runApp(MaterialApp(
    home: Scaffold(
      appBar: AppBar(title: const Text('Silent Payments example')),
      body: Center(child: SelectableText(address)),
    ),
  ));
}
