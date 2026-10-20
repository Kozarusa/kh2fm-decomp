from pathlib import Path
ex=Path(__file__).resolve().parent
s=(ex/'register_mediumcall.py').read_text(encoding='utf-8')
s=s.replace('mediumcall','tablelookup').replace('callbackreturn','mediumcall')
s=s.replace("['00123d40']","['00132f38']")
(ex/'register_tablelookup.py').write_text(s,encoding='utf-8')
runner=(ex/'probe_mediumcall_curated.py').read_text(encoding='utf-8').replace('mediumcall_recovered_00123d40','tablelookup_recovered_00132f38')
(ex/'probe_tablelookup_curated.py').write_text(runner,encoding='utf-8')
