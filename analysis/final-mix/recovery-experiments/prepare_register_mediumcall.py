from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_callbackreturn.py').read_text(encoding='utf-8')
s=s.replace('callbackreturn','mediumcall').replace('callbackaddress','callbackreturn')
s=s.replace("['001050d8','0016c7a0','0016fac8','00288be8','0028cc08']","['00123d40']")
(ex/'register_mediumcall.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_callbackreturn_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_mediumcall_curated.py').write_text(runner[:start]+"names=['fm_primary_mediumcall_recovered_00123d40.cpp']"+runner[end:],encoding='utf-8')
