import json,re,sqlite3,sys,struct,hashlib
from pathlib import Path
root=Path(__file__).resolve().parents[6]
a=sys.argv[1]
db=sqlite3.connect('file:'+str(root/'Codex/analysis/final-mix/worker-coordination/recovery-queue.sqlite3')+'?mode=ro',uri=True)
row=db.execute('select metadata,state,queue,blocker from targets where address=?',(a,)).fetchone()
meta=json.loads(row[0]);print(json.dumps({'metadata':meta,'state':row[1],'queue':row[2],'blocker':row[3]},indent=2))
proposal=meta.get('best_proposal')
if proposal:
 source=root/'Codex'/proposal['source'];s=source.read_text()
 m=re.search(r'\b[\w *]+ func_'+a+r'\([^;]*?\)\s*\{',s)
 if m:
  i=s.index('{',m.start());d=1;j=i+1
  while d:d+=(s[j]=='{')-(s[j]=='}');j+=1
  body=s[m.start():j];print(body)
  terms=re.findall(r'(?:func|D)_[0-9a-f]{8}',body)
  print('\n'.join(x for x in s.splitlines() if x.startswith('extern') and any(t in x for t in terms)))
 data=json.loads((root/'Codex'/proposal['proof']).read_text());r=next(x for x in data['rows'] if x['address']==a);b,c=r['compiled_hex'],r['target_hex']
 print('Prior differing words:',[(j//8,b[j:j+8],c[j:j+8]) for j in range(0,min(len(b),len(c)),8) if b[j:j+8]!=c[j:j+8]])
elf=(root/'Public/tools/kh2-reference/SLPM_666.75').read_bytes();assert hashlib.sha256(elf).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
off=int(a,16)-0x100000+0x1000;raw=elf[off:off+meta['bytes']]
print('Original words:',[f'{w:08x}' for w in struct.unpack('<'+str(len(raw)//4)+'I',raw)])
