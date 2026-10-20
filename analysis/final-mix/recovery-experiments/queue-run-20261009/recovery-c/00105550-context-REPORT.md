# 00105550 incoming architectural context save

Full104-byte original contains twelve quadword stores: gp,sp,fp,ra,s0-s7; followed by f20-f31 single-precision stores. Ends jr ra with return0 in delay slot. This saves incoming register state, including upper128-bit GPR lanes, which native pseudocode cannot express faithfully via ordinary local variables. Caller/prototype and SDK runtime-source evidence is needed before a justified architectural wrapper. No speculative compiler source probe performed. Full original words and SHA256 are saved below.

```json
{
  "start": "00105550",
  "end": "001055b8",
  "bytes": 104,
  "range_sha256": "e71094b6053e2a4eea7507b13e75e902c6186c5e97b0c1129b64eb01c9e04ad6",
  "words": [
    "dfb00000",
    "dfb10008",
    "0040282d",
    "dfbf0010",
    "0804e304",
    "27bd0020",
    "27bdffe0",
    "ffb10008",
    "ffb00000",
    "ffb20010",
    "ffbf0018",
    "908f0020",
    "11e0001e",
    "0080882d",
    "8c920030",
    "240f0001",
    "564f001b",
    "dfb00000",
    "0c04f5fc",
    "00000000",
    "904f15a0",
    "11e00015",
    "24040001",
    "0c04f768",
    "a04015a0",
    "14400017"
  ],
  "elf_sha256": "d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87"
}
```
