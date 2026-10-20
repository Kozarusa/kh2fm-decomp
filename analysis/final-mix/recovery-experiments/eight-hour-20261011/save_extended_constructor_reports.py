from pathlib import Path
import hashlib,json,subprocess,sys
base=Path(__file__).resolve().parent
helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py'
leases={r['address']:r for r in json.loads((base/'extended-constructor-renewed-leases.json').read_text())}
for address in ('00127f40','001c2c98','001c2ce8'):
 records=[]
 for proof in sorted(base.glob(f'eight_hour_{address}_*.verification.json')):
  data=json.loads(proof.read_text());source=proof.with_suffix('').with_suffix('.cpp')
  assert hashlib.sha256(source.read_bytes()).hexdigest()==data['source_sha256']
  row=data['rows'][0];assert not row['exact_match']
  a,b=bytes.fromhex(row['target_hex']),bytes.fromhex(row['compiled_hex'])
  records.append({'source':source.name,'source_sha256':data['source_sha256'],'proof':proof.name,'proof_sha256':hashlib.sha256(proof.read_bytes()).hexdigest(),'compiled_bytes':len(b),'target_bytes':len(a),'differing_words':sum(a[i:i+4]!=b[i:i+4] for i in range(0,max(len(a),len(b)),4))})
 assert records
 evidence=base/f'{address}-extended-constructor-evidence.json';assert not evidence.exists()
 evidence.write_text(json.dumps({'address':address,'accepted':False,'proofs':records},indent=2)+'\n')
 if address=='00127f40':
  finding='The native 120-byte constructor forwards its resource argument, reloads the header end after storing the buffer origin, and uses separate count stride and successive buffer pointers. The complete observed ABI is retained in the new proposals. Fixed-register stride and pointer lifetimes prevent one strength reduction, but neither tested profile reproduces the complete range. Next investigate the header alias after the origin store and the joint lifetime of start/end/count registers. Do not repeat the already tested opaque stride and end reload alone.'
  specialty='constructor-buffer-alias'
 else:
  finding='The best complete 76-byte proposal still swaps only the final table and mode stores. Restoring both forwarded payload arguments preserves that residual and confirms that omitted arguments are not the cause. Precise dependencies and volatile stores perturb additional preceding instructions. Next investigate canonical field aliasing across the final table and mode writes, rather than repeat argument restoration or broad memory barriers. No unsuccessful source is registered.'
  specialty='constructor-final-store-alias'
 report=base/f'{address}-extended-constructor-report.md';assert not report.exists()
 report.write_text(f'# Extended constructor investigation: {address}\n\n{finding}\n\n`{evidence.name}` binds {len(records)} complete source/proof pairs. Types and higher-level identities remain provisional. No compiler-impossibility claim is made.\n')
 result=subprocess.run([sys.executable,str(helper),'block','--address',address,'--token',leases[address]['token'],'--specialty',specialty,'--report',str(report),'--hypothesis',finding],capture_output=True,text=True,check=True)
 print(result.stdout)
