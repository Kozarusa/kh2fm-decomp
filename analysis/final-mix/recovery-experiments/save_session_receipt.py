from pathlib import Path
import hashlib,json,sys
from datetime import datetime,timezone
ex=Path(__file__).resolve().parent
root=ex.parents[2]
area=ex.parent
progress_path=ex/'primary-fourhour-progress-v1.json'
progress=json.loads(progress_path.read_text())
rows={r['address']:r for r in json.loads((area/'native-build/compiler-range-verification.json').read_text())}
accepted=[]
for address in progress['new_isolated_exact']:
 row=rows[address]
 assert row['size_status']=='equal_size'
 assert row['unmodified_compiled_symbol_match'] and row['normalized_match']
 source=root.parent/'Public/tools/kh2-reference'/row['source']
 assert source.is_file()
 accepted.append(dict(address=address,bytes=row['declared_range_size'],source=row['source'],source_sha256=hashlib.sha256(source.read_bytes()).hexdigest()))
assert len(accepted)==progress['accepted_exact']-progress['baseline_exact']
assert sum(r['bytes'] for r in accepted)==progress['new_instruction_bytes']
status=json.loads((area/'worker-coordination/primary-claim.json').read_text())
gate=root.parent/'Public'/status['baseline_gate']
phase=gate.stem.removeprefix('verify_fm_').removesuffix('_checkpoint').replace('_','-')
manifest=sorted(area.glob(phase+'-checkpoint-*.json'))[-1]
data=dict(created_utc=datetime.now(timezone.utc).isoformat(),session=json.loads((ex/'primary-fourhour-session.json').read_text()),accepted_exact=progress['accepted_exact'],session_gain=len(accepted),session_instruction_bytes=sum(r['bytes'] for r in accepted),accepted_ranges=accepted,checkpoint=str(manifest.relative_to(root)),checkpoint_sha256=hashlib.sha256(manifest.read_bytes()).hexdigest(),gate=str(gate.relative_to(root.parent)),gate_sha256=hashlib.sha256(gate.read_bytes()).hexdigest(),progress_receipt_sha256=hashlib.sha256(progress_path.read_bytes()).hexdigest(),limitation='Whole-ELF equality retains original fallback bytes. This is not a complete source rebuild.')
destination=ex/sys.argv[1]
assert destination.parent==ex and not destination.exists()
destination.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
print(f'Saved verified session receipt: {len(accepted)} exact ranges, {sum(r["bytes"] for r in accepted)} instruction bytes.')
