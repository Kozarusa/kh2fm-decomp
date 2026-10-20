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
print(layout[0].keys())
template=json.loads((ex/'fm_primary_callbackreturn_v2_001050d8_1.verification.json').read_text())['rows'][0]
target=bytes.fromhex(template['target_hex'])
expected=[int.from_bytes(target[i:i+4],'little') for i in range(0,52,4)]
hits=[]
for row in layout:
 address=int(row['addr'],16)
 if int(row['size'],0)!=52:
  continue
 offset=addr_to_file_offset(address)
 code=original[offset:offset+52]
 words=[int.from_bytes(code[i:i+4],'little') for i in range(0,52,4)]
 if all((w&0xffff0000)==(e&0xffff0000) if i in [3,5] else w==e for i,(w,e) in enumerate(zip(words,expected))):
  low=words[5]&65535
  hits.append(dict(address=f'{address:08x}',layout=row,global_address=f'{((words[3]&65535)<<16)+(low if low<32768 else low-65536):08x}'))
(ex/'primary-callbackreturn-machine-census-v1.json').write_text(json.dumps(dict(positive_control='001050d8',original_sha256=hashlib.sha256(original).hexdigest(),hits=hits),indent=2)+'\n',encoding='utf-8')
print(json.dumps(hits,indent=2))
