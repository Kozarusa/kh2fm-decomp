from pathlib import Path
import hashlib,json,subprocess,sys
base=Path(__file__).resolve().parent;helper=base.parents[4]/'Public/tools/kh2-audit/recovery_queue.py';leases={r['address']:r for r in json.loads((base/'fresh-scalar-wrapper-leases.json').read_text())}
for address in ('002eff58','0030df00'):
 records=[]
 for path in sorted(base.glob(f'eight_hour_{address}_*.verification.json')):
  source=path.with_suffix('').with_suffix('.cpp');proof=json.loads(path.read_text());assert hashlib.sha256(source.read_bytes()).hexdigest()==proof['source_sha256']
  row=proof['rows'][0];assert not row['exact_match'];a,b=bytes.fromhex(row['target_hex']),bytes.fromhex(row['compiled_hex'])
  records.append({'source':source.name,'source_sha256':proof['source_sha256'],'proof':path.name,'proof_sha256':hashlib.sha256(path.read_bytes()).hexdigest(),'compiled_bytes':len(b),'target_bytes':len(a),'differing_words':sum(a[i:i+4]!=b[i:i+4] for i in range(0,max(len(a),len(b)),4))})
 if address=='002eff58':
  finding='The scalar predicate adds floats at object offsets 272 and 276, multiplies by the global at 00376224, and compares with offset 28. An opaque address reproduces the full 56-byte range length. The best register proposal differs only in the order of the global float load and addition, and the multiply/comparison destination register. Later lifetime markers, arithmetic primitives, and expression evaluation variants perturb more words. Next investigate a native floating expression representation that keeps the factor live in f0 and the accumulated result in f1 without moving the first object load. No unsuccessful source is registered.';specialty='float-predicate-lifetimes'
 else:
  finding='The native SDK wrapper stores -1 at 00366180, calls 002fde18 with 01e38e68, zero, and four, then returns zero. Typed bindings reproduce the initial high-address and -1 constants in v0 and v1 and all call/return instructions. The best four-word residual places the callback high-address calculation too late around the return-address save and global store. A dependency on the callback value or an emitted address primitive hoists operations before the stack adjustment and does not resolve the range. Next investigate joint callback/prologue scheduling rather than repeat fixed constants, broad barriers, or value dependencies.';specialty='sdk-callback-prologue'
 evidence=base/f'{address}-scalar-wrapper-evidence.json';assert not evidence.exists();evidence.write_text(json.dumps({'address':address,'accepted':False,'proofs':records},indent=2)+'\n')
 report=base/f'{address}-scalar-wrapper-report.md';assert not report.exists();report.write_text(f'# Scalar wrapper investigation: {address}\n\n{finding}\n\n`{evidence.name}` binds {len(records)} complete source/proof pairs. Types and high-level identities remain provisional; no compiler-impossibility claim is made.\n')
 result=subprocess.run([sys.executable,str(helper),'block','--address',address,'--token',leases[address]['token'],'--specialty',specialty,'--report',str(report),'--hypothesis',finding],capture_output=True,text=True,check=True);print(result.stdout)
