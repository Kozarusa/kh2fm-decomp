from pathlib import Path
import json,hashlib,subprocess,sys
base=Path(__file__).resolve().parent;helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py'
leases={r['address']:r for r in json.loads((base/'fresh56-leases.json').read_text())}
for address in ('00137c50','00262730','0027d450'):
 records=[]
 for path in sorted(base.glob(f'eight_hour_{address}_*.verification.json')):
  source=path.with_suffix('').with_suffix('.cpp');proof=json.loads(path.read_text());assert hashlib.sha256(source.read_bytes()).hexdigest()==proof['source_sha256']
  row=proof['rows'][0];assert not row['exact_match'];a,b=bytes.fromhex(row['target_hex']),bytes.fromhex(row['compiled_hex'])
  records.append({'source':source.name,'source_sha256':proof['source_sha256'],'proof':path.name,'proof_sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'compiled_bytes':len(b),'target_bytes':len(a),'differing_words':sum(a[i:i+4]!=b[i:i+4] for i in range(0,max(len(a),len(b)),4))})
 if address=='00137c50':
  finding='The complete 56-byte initialization proposal has six independent word stores and a final direct helper call. Reversing equivalent source-store groups reduces the mismatch to three stores while preserving the prologue, constants, argument preparation, tail jump, and stack restore. Narrow field dependencies and volatile commit markers perturb other scheduling; none is accepted. Next examine aggregate field typing or a store group representation that keeps the already correct prologue and moves only the last zero and two intermediate stores. Do not repeat the recorded store permutations or memory commit markers.';specialty='initialization-store-groups'
 else:
  finding='The original 56-byte wrapper calls a global object getter, a membership helper, then a tail dispatch with its constant identifier. The getter returns a native word, not a 64-bit arithmetic value. A typed empty pre-call definition of the saved register reproduces every instruction except the order of the two prologue saves (return address and s0). An untyped register clobber instead triggers 128-bit spills and a larger frame; fixed-register markers after the call do not resolve the residual. Next investigate typed prologue save ordering with a genuine live input or ABI-supported frame representation. Do not repeat untyped clobbers or widen the arithmetic just to force a spill.';specialty='wrapper-prologue-save-order'
 evidence=base/f'{address}-fresh56-evidence.json';assert not evidence.exists();evidence.write_text(json.dumps({'address':address,'accepted':False,'proofs':records},indent=2)+'\n')
 report=base/f'{address}-fresh56-report.md';assert not report.exists();report.write_text(f'# Fresh wrapper investigation: {address}\n\n{finding}\n\n`{evidence.name}` binds {len(records)} complete proposals and original-range comparisons. No unsuccessful source is registered. No compiler-impossibility claim is made.\n')
 result=subprocess.run([sys.executable,str(helper),'block','--address',address,'--token',leases[address]['token'],'--specialty',specialty,'--report',str(report),'--hypothesis',finding],capture_output=True,text=True,check=True);print(result.stdout)
