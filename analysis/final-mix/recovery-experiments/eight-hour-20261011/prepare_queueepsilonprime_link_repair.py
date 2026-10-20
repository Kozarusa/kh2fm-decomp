"""Prepare an unambiguous C++ address alias; retain the failed proposal and ELF."""
from pathlib import Path
base=Path(__file__).resolve().parent
old=base/'eight_hour_001394d8_fresh_three_calls_0.cpp'
text=old.read_text();assert 'extern "C" void func_00139768();' in text
new=base/'eight_hour_001394d8_v3_cpp_helper_alias.cpp';assert not new.exists()
new.write_text(text.replace('extern "C" void func_00139768();','void func_00139768();'))
runner=base/'probe_queueepsilonprime_link_repair.py';assert not runner.exists()
runner.write_text((base/'probe_extended_constructors_v6.py').read_text().replace("json.loads((base / 'extended-constructor-v6-variants.json').read_text())","['eight_hour_001394d8_v3_cpp_helper_alias.cpp']"))
