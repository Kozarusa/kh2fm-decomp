from pathlib import Path
out=Path('Codex/analysis/final-mix/recovery-experiments/delegated/global-copy')
ex=out.parents[1]
a=(ex/'fm_primary_globalcopy_v3_00158ac8_1.cpp').read_text().replace(': "$8");', ': "$8", "$13");')
(out/'sa_copy_ac8_clobber13.cpp').write_text(a)
