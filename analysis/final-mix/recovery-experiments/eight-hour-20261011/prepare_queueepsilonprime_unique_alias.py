from pathlib import Path
base=Path(__file__).resolve().parent
text=(base/'eight_hour_001394d8_fresh_three_calls_0.cpp').read_text()
text=text.replace('extern "C" void func_00139768();','// A distinct absolute-address alias avoids the legacy assembly symbol collision.\nextern "C" void native_helper_00139768() asm("D_00139768");').replace(' func_00139768();',' native_helper_00139768();')
source=base/'eight_hour_001394d8_v4_unique_helper_alias.cpp';assert not source.exists();source.write_text(text)
runner=base/'probe_queueepsilonprime_unique_alias.py';assert not runner.exists();runner.write_text((base/'probe_extended_constructors_v6.py').read_text().replace("json.loads((base / 'extended-constructor-v6-variants.json').read_text())","['eight_hour_001394d8_v4_unique_helper_alias.cpp']"))
