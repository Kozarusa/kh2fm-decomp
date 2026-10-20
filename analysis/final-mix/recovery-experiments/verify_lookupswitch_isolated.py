from pathlib import Path
import hashlib,json,struct,sys
ex=Path('/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments')
name,receipt_name=sys.argv[1:3]
source=ex/(name+'.cpp')
proof=json.loads(source.with_suffix('.verification.json').read_text())
assert proof['source_sha256']==hashlib.sha256(source.read_bytes()).hexdigest()
assert {r['address'] for r in proof['rows']}=={'00155ee8','00155fc0'}
assert all(r['exact_match'] and r['compiled_size']==r['target_size'] for r in proof['rows'])
linked=Path('/root/kh2fm-build/recovery-experiments')/name/'probe.elf'
elf=linked.read_bytes()
original=Path('/root/kh2fm-build/SLPM_666.75').read_bytes()
assert hashlib.sha256(original).hexdigest()=='d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87'
header=struct.unpack_from('<16sHHIIIIIHHHHHH',elf)
sections=[struct.unpack_from('<10I',elf,header[6]+i*header[11]) for i in range(header[12])]
names_section=sections[header[13]]
names=elf[names_section[4]:names_section[4]+names_section[5]]
by_name={names[s[0]:].split(b'\0',1)[0].decode():s for s in sections}
rows=[]
for address,function in [('0036b2c4','00155ee8'),('0036b2ec','00155fc0')]:
 section=by_name[f'.data.fm_switch_table_{function}']
 assert section[5]>=20
 generated=elf[section[4]:section[4]+20]
 offset=int(address,16)-0x100000+0x1000
 target=original[offset:offset+20]
 assert generated==target,(address,generated.hex(),target.hex())
 rows.append(dict(address=address,function=function,bytes=20,exact_match=True,hex=target.hex(),targets=[f'{v:08x}' for v in struct.unpack('<5I',target)]))
receipt=ex/receipt_name
assert not receipt.exists()
receipt.write_text(json.dumps(dict(source=source.name,source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),code_proof_sha256=hashlib.sha256(source.with_suffix('.verification.json').read_bytes()).hexdigest(),linked_elf_sha256=hashlib.sha256(elf).hexdigest(),tables=rows,limitations=['This isolated proof does not prove full build acceptance, data integration, or runtime behavior.']),indent=2)+'\n')
print('Isolated lookup proof: 2 exact code ranges; 40/40 generated table bytes exact.',flush=True)
