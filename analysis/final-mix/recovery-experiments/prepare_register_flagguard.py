from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_globalargument.py').read_text(encoding='utf-8')
s=s.replace('globalargument','flagguard').replace('bytewrapper','globalargument')
s=s.replace("['0014f578']","['00157160']")
(ex/'register_flagguard.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_globalargument_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_flagguard_curated.py').write_text(runner[:start]+"names=['fm_primary_flagguard_recovered_00157160.cpp']"+runner[end:],encoding='utf-8')
