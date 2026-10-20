import json, struct
# Scan the disc for frameless tail-call wrappers (no 0x27bd prologue, contain a j),
# then check how many are already recovered vs unregistered.
ISO=r"C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/SLPM_666.75"
START=0x100000; OFF=0x1000
layout={}
for line in open(r"C:/Users/KoZa/Documents/AGENTS/Public/tools/kh2-reference/layout.tsv",encoding="utf-8",errors="replace"):
    if line.startswith("#") or not line.strip(): continue
    p=line.split()
    if len(p[0])!=8: continue
    try: layout[int(p[0],16)]=int(p[2])
    except ValueError: pass
reg=set()
try:
    for row in json.load(open("analysis/final-mix/native-build/compiler-range-verification.json",encoding="utf-8",errors="replace")):
        if row.get("unmodified_compiled_symbol_match"): reg.add(int(row["address"],16))
except Exception as e:
    print("verify load failed:",e)
blob=open(ISO,"rb").read()
hits=[]; bad=0
for addr,size in layout.items():
    if size!=12 and size!=16: continue
    o=addr-START+OFF
    if o<0 or o+size>len(blob): bad+=1; continue
    ws=[int.from_bytes(blob[o+i:o+i+4],"little") for i in range(0,size,4)]
    if 0x27bd0000 <= (ws[0] & 0xffff0000): continue
    if not any((w & 0xfc000000)==0x08000000 for w in ws): continue
    hits.append((addr,size,addr in reg))
un=[h for h in hits if not h[2]]
print("frameless j-leaf ranges (12/16B):",len(hits))
print("  recovered:",len(hits)-len(un))
print("  UNREGISTERED:",len(un))
for a,s,r in sorted(un)[:40]:
    print("   %08x %d"%(a,s))
