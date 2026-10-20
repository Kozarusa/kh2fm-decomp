from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_indexedmask.py').read_text(encoding='utf-8')
s=s.replace('indexedmask','maskpair').replace('lookupswitch','indexedmask')
s=s.replace("['001584a0']","['00158548','00159ce0']")
(ex/'register_maskpair.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_indexedmask_curated.py').read_text(encoding='utf-8')
start=runner.index('names=');end=runner.index('\nfor name',start)
(ex/'probe_maskpair_curated.py').write_text(runner[:start]+"names=['fm_primary_maskpair_recovered_00158548.cpp','fm_primary_maskpair_recovered_00159ce0.cpp']"+runner[end:],encoding='utf-8')
