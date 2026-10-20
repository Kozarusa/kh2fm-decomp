from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_floatresult.py').read_text(encoding='utf-8')
s=s.replace('floatresult','indexedmask').replace('flagguard','lookupswitch')
s=s.replace("['00155658']","['001584a0']")
(ex/'register_indexedmask.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_floatresult_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_indexedmask_curated.py').write_text(runner[:start]+"names=['fm_primary_indexedmask_recovered_001584a0.cpp']"+runner[end:],encoding='utf-8')
