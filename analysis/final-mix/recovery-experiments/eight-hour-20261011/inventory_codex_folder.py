"""Inventory all child directories without following links outside the requested folder."""
from pathlib import Path
import collections,json,os,time
base=Path(__file__).resolve().parent;root=base.parents[3]
rows=[];extensions=collections.Counter();errors=[];started=time.time()
for current,children,files in os.walk(root,followlinks=False,onerror=lambda e:errors.append(str(e))):
 path=Path(current)
 children[:]=[name for name in children if not (path/name).is_symlink() and not (hasattr(Path,'is_junction') and (path/name).is_junction())]
 size=0;count=0
 for name in files:
  file=path/name
  try:size+=file.stat().st_size;count+=1;extensions[file.suffix.lower() or '(none)']+=1
  except OSError as error:errors.append(str(error))
 rows.append({'directory':path.relative_to(root).as_posix(),'direct_files':count,'direct_bytes':size,'child_directories':len(children)})
rollup={}
for row in rows:
 parts=Path(row['directory']).parts
 for depth in range(0,min(len(parts),3)+1):
  key='/'.join(parts[:depth]) if depth else '.'
  bucket=rollup.setdefault(key,{'files':0,'bytes':0,'directories':0})
  bucket['files']+=row['direct_files'];bucket['bytes']+=row['direct_bytes'];bucket['directories']+=1
receipt={'root':str(root),'scope':'All reachable child directories; symbolic links and directory junctions are not followed. Snapshot during ongoing recovery.','elapsed_seconds':time.time()-started,'directory_count':len(rows),'file_count':sum(r['direct_files'] for r in rows),'total_bytes':sum(r['direct_bytes'] for r in rows),'extensions':dict(extensions.most_common()),'rollup_to_depth_three':rollup,'directories':rows,'errors':errors}
out=base/'codex-folder-inventory.json';assert not out.exists();out.write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps({k:receipt[k] for k in ('directory_count','file_count','total_bytes','elapsed_seconds','errors')},indent=2))
print(json.dumps({k:v for k,v in rollup.items() if k.count('/')<=1},indent=2))
