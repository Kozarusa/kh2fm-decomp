from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_flagguard.py').read_text(encoding='utf-8')
s=s.replace('flagguard','floatresult').replace('globalargument','flagguard')
s=s.replace("['00157160']","['00155658']")
(ex/'register_floatresult.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_flagguard_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_floatresult_curated.py').write_text(runner[:start]+"names=['fm_primary_floatresult_recovered_00155658.cpp']"+runner[end:],encoding='utf-8')
