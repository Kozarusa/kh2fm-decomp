from pathlib import Path
import csv,json,sys,hashlib
ex=Path(__file__).resolve().parent
root=ex.parents[2]
reference=root.parent/'Public/tools/kh2-reference'
sys.path.insert(0,str(reference/'tools'))
from common import addr_to_file_offset
original=(reference/'SLPM_666.75').read_bytes()
assert hashlib.sha256(original).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
layout=list(csv.DictReader((x for x in (reference/'layout.tsv').read_text().splitlines() if not x.startswith('#')),delimiter='\t'))
accepted={r['address'] for r in json.loads((root/'analysis/final-mix/native-build/compiler-range-verification.json').read_text())}
controls={}
for address in ['001337f0','00133980']:
 row=json.loads((ex/f'fm_primary_packetalias_recovered_{address}.verification.json').read_text())['rows'][0]
 controls[address]=[int.from_bytes(bytes.fromhex(row['target_hex'])[i:i+4],'little') for i in range(0,row['target_size'],4)]
hits=[]
for row in layout:
 size=int(row['size'],0)
 if size not in [80,88]:
  continue
 offset=addr_to_file_offset(int(row['addr'],16))
 code=original[offset:offset+size]
 words=[int.from_bytes(code[i:i+4],'little') for i in range(0,size,4)]
 for control,expected in controls.items():
  if len(words)!=len(expected):
   continue
  variable={1,8} if control=='001337f0' else {6}
  if all((w&0xffff0000)==(e&0xffff0000) if i in variable else w==e for i,(w,e) in enumerate(zip(words,expected))):
   hits.append(dict(address=row['addr'],bytes=size,template=control,accepted=row['addr'] in accepted,variable_words={str(i):f'{words[i]:08x}' for i in sorted(variable)}))
assert {'001337f0','00133980'} <= {r['address'] for r in hits}
(ex/'primary-packetalias-machine-census-v1.json').write_text(json.dumps(dict(positive_controls=list(controls),original_sha256=hashlib.sha256(original).hexdigest(),hits=hits),indent=2)+'\n',encoding='utf-8')
print(json.dumps(hits,indent=2))
