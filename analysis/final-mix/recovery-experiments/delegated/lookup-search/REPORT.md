# Lookup and sentinel-search recovery report

No proposal in this directory is a complete exact match. Nothing was registered, synchronized, or integrated. The accepted baseline and acceptance gates were not modified.

## Evidence and method

The isolated prober was `Public/tools/kh2-audit/probe_fm_source.py`, run through WSL Ubuntu-24.04 as root. It compiled and linked each unique stem under `/root/kh2fm-build/recovery-experiments/` with the pinned image and unchanged flags. Every completed proof independently re-read the original ELF and asserted its SHA-256: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`. No range override was used.

The original-byte inputs were the historical freshfamily and mediumcontrol verification files and the independently re-extracted bytes in these new proofs. `primary-fourhour-blockers.md` was read before reconstruction. The first sandboxed WSL invocation returned Wsl/Service/E_ACCESSDENIED. Escalated WSL was available. A shell-loop argument attempt failed the prober workspace assertion before compilation; the subsequent explicit-argument Python driver succeeded.

## Instruction-derived findings

### 00114438 and 00114490

Both targets have 88-byte live boundaries, despite 84-byte Ghidra bodies. Their instructions are identical except for the relative-table/count offsets: 0xa4/0xa0 versus 0xb4/0xb0. The original loads the root into $14, initializes $2 to zero in the root-null branch delay slot, loads the relative offset into $15 and count into $13, and initializes index $12. The base addition writes $10 in the nonpositive-count branch delay slot. Count is transported into $11. Each iteration shifts index into $15, adds offset and base into item $13, increments index, loads the item key into $15, and compares with argument $5. The mismatch branch has the index/count comparison in its delay slot. Success returns item through $2. An internal zero word precedes the loop continuation branch; the final return preserves the initial zero result.

A success-path empty volatile memory marker reproduces separate success and failure returns. This is a meaningful improvement over the earlier shared-return proposals. v5 also reproduces early zero-result initialization and the operand order of the item address addition. Its remaining changes are the base-add delay slot and internal zero-word placement, with the corresponding branch distances. Natural C base arithmetic in v3/v4 instead calculates into $15 and moves into $10; the fixed output asm in v5 writes $10 directly but is not scheduled into the original branch delay slot. The marker does not establish that the compiler cannot reproduce the target.

The next useful hypothesis is to express the base arithmetic as a compiler-recognized fixed-register operation while preserving the early zero-result lifetime. Blind branch-hint changes are low information: v0 and v1 produced identical code. No explicit instruction padding or raw branch assembly was introduced.

### 00124c48

The original initializes a result pointer in $2 using root $14 and relative offset $15. The first key is loaded into $12 and checked against a -1 sentinel. The first sentinel branch is branch-likely and zeroes the result only on the taken path. A separate sentinel occupies $11 for the loop. Each miss computes pointer+16 into $13 in the key-comparison delay slot, loads the length from pointer+4 into $15, shifts it by four, adds it to $13 to produce the next pointer in $2, then loads the next key into $14. The loop branch compares $14 against $11 and copies $14 into $12 in its delay slot. This confirms that the arithmetic is pointer + 16 + (length << 4), consistent with the original decompiler expression; treating the 16 as an absolute address would be incorrect.

The reconstructed variants pin the first and subsequent keys separately and express the pointer+16 arithmetic before length loading. All four compile to 112 bytes against 92, with extra pointer/result copies, a non-likely initial sentinel branch, and changed return control flow. A volatile result-pointer marker and an expected initial sentinel did not alter the compiled bytes. The existing mediumcontrol_v1_00124c48_1 proof remains the equal-size 92-byte baseline, but it has the wrong first/next-key transport and changes where pointer+16 is computed. Stronger fixed-key constraints worsen allocation rather than solving the branch layout. A useful next hypothesis is a narrowly scoped initializer that ends the root register lifetime before the loop, plus a first-key check whose only taken-path effect is result zeroing.

## Exact target bytes

### 00114438
Size: 88 bytes. Range SHA-256: `dad5f7d6325d328c01c4eb7a39b41da460e02ef1b9a5c989d3eaee17fe22ea35`.

`08008e8c1200c0112d100000a400cf8d2d600000a000cd8d0d00a0192150cf012d58a001c0790c002168ea0101008c250000af8d0400e5152a708b010800e0032d10a00100000000f7ffc015c0790c000800e00300000000`

### 00114490
Size: 88 bytes. Range SHA-256: `21a2ba893bb7d48421e451d18f6f4a961b135cffccc5480c6431d1d9ae3db419`.

`08008e8c1200c0112d100000b400cf8d2d600000b000cd8d0d00a0192150cf012d58a001c0790c002168ea0101008c250000af8d0400e5152a708b010800e0032d10a00100000000f7ffc015c0790c000800e00300000000`

### 00124c48
Size: 92 bytes. Range SHA-256: `3aa17ecddf147d8d3c514bd976f6cdfb909f41d0d760af145a0d261e2d9698a4`.

`04008e8c0c00cf8d0300e0112d1000000800cf8d2110cf010d004010ffff0f2400004c8c0b008f512d100000ffff0b240800851110004d2404004f8c00790f002110af0100004e8cf9ffcb152d60c0012d1000000800e00300000000`

## Probe inventory

| Source stem | Compiled/target bytes | Exact | Source SHA-256 | Proof SHA-256 |
|---|---:|---|---|---|
| sa_lookup_sentinel_v0_00124c48 | 112/92 | False | `a02b9f36ce747d9cb90532e52464845c6cd636700fe6f28f32a90e29cde66fce` | `dba2433385c37e96df2260e8f701dc4041af8c457a0b9a621a14be4fe61cafb6` |
| sa_lookup_sentinel_v1_00124c48 | 112/92 | False | `190d2da54fb54a849f44e532fa859dc25e95a20f6d3ddde0d9e3e82cd9cae033` | `61a09586b3ca68f74af3ff15358d15ba8c36fda0c172293e564673f6aeaf8b7e` |
| sa_lookup_sentinel_v2_00124c48 | 112/92 | False | `9813f06852f24f2dd5dfd0f713245f6a81c8168770ab1c65f5634126c0106fea` | `f28057fb1d8b84039b749ccd4acbda5cbfbc2e97467464acb109241f4f1c8725` |
| sa_lookup_sentinel_v3_00124c48 | 112/92 | False | `63bcab106759e5b15f1b06257cc21ba4293a36c126339567c3f47fdbc6162961` | `182f5f0409aeef338f013b1534b1a2e1bb472809cb38fc41983ed445d50e64fa` |
| sa_lookup_table_v0_00114438 | 88/88 | False | `1c1bcc289bc5dc879b3c8163b4978cc1c62a9047e712efe7296afcea0ff076ba` | `d279b9c73d4aa349e99ce9363b4491ec2f52659a48b621aa5c7f97386635f507` |
| sa_lookup_table_v0_00114490 | 88/88 | False | `258467b24d25087dcacdfbb583526060411d37b5898d2f29a20b267c9196cf10` | `a97fbe07666ba7e98022b2bbcc9efd14a8220b5dd27b559d728c367b4b7513c1` |
| sa_lookup_table_v1_00114438 | 88/88 | False | `ba567ceb2e7d47abed37d8f13cf92acde1a8b6e01939f69933b6b87b6a5fda04` | `d80292fd48bd6ea7dc694f800e0f6e4b25b2035271e4d94c67e3cfc729eec3b7` |
| sa_lookup_table_v1_00114490 | 88/88 | False | `2a0066d4dff91fecb73ec2f31ac87411a15862b0284c38cdc6a8fc3f2fe8bf5f` | `8ea5b72ae035e24c7d475d01b711e772fcc8be123234fe10bc26721478c06582` |
| sa_lookup_table_v2_00114438 | 92/88 | False | `b8f0826e37cb817a96a8146c8f2a32858d01449741678eafda50806f75f23e96` | `ab5e31223cf6000a8d44719029d2af7c793dfed3b684c96f56e803172494eee8` |
| sa_lookup_table_v2_00114490 | 92/88 | False | `ece60ec5149e7c82f4185476b4845d4d875dfb9a1fd0367a7a52a123065d175e` | `0861d12e5e3719f8ce8ac102ff3a88267c0943b01449b57e105e1ee372e92513` |
| sa_lookup_table_v3_00114438 | 88/88 | False | `71f6f992ab983766bbf055041c93ec8db8e5d94ae01fec120333f96c3e625fb0` | `40ed52160e62cd92b98b899da13958643637ad73ad8a4a7bd6219d3f0a3003c5` |
| sa_lookup_table_v3_00114490 | 88/88 | False | `d0dfd728c8f96a4fad1b003cc2d27db107bacc4c54a2655b32c60cd02a939abc` | `0c40f42ab681e3deec10a08d0eb7f0bdab01f81b3988139d23a27cb90a2d28ec` |
| sa_lookup_table_v4_00114438 | 88/88 | False | `de9f8a9eb1e9fe46b52bb0bca551b3f0c4ba359f5f6768e8a90222db94f456de` | `605724fa161f9308d8cc954eaf8ba7d4ffef7665d125135046de0a67de4bdf7e` |
| sa_lookup_table_v4_00114490 | 88/88 | False | `beab7f5dd7508e07b9b0d9a67b3f27624129b1fca5c094c4e3eee7008e72c4e9` | `575c3a71a8c42836d68194ac7b43c549a7db18c152002c2f65920bbc2a0cd892` |
| sa_lookup_table_v5_00114438 | 88/88 | False | `e47c1d75df2f3498625ad45b7eff57dca632e7df435abb9446ae51fdceaf54d7` | `62d4782890e9f9d8c0ffda0af87d1ebefed080cf82a522ac1a9e4ec109eb0102` |
| sa_lookup_table_v5_00114490 | 88/88 | False | `5fdc1d74d97f29a0645e62e3e4688e3faa72fbea232c36d4016b060e140ffcce` | `fb38a80af58c2e49bab2fa9c48947359e3bdafe2a56f196c3146763cb12b7cb4` |

## Remaining word differences for nearest new table proposal

Word offsets are relative to the start of the range. Bytes are little endian. The full compared byte strings remain in each proof.

### 00114438
Compiled: `08008e8c1200c0112d100000a400cf8d2d600000a000cd8d0d00a019000000002150cf012d58a001c0790c002168ea0101008c250000af8d0300e5152a708b010800e0032d10a001f8ffc015c0790c000800e00300000000`

| Offset | Compiled word bytes | Target word bytes |
|---:|---|---|
| 0x1c | `00000000` | `2150cf01` |
| 0x20 | `2150cf01` | `2d58a001` |
| 0x24 | `2d58a001` | `c0790c00` |
| 0x28 | `c0790c00` | `2168ea01` |
| 0x2c | `2168ea01` | `01008c25` |
| 0x30 | `01008c25` | `0000af8d` |
| 0x34 | `0000af8d` | `0400e515` |
| 0x38 | `0300e515` | `2a708b01` |
| 0x3c | `2a708b01` | `0800e003` |
| 0x40 | `0800e003` | `2d10a001` |
| 0x44 | `2d10a001` | `00000000` |
| 0x48 | `f8ffc015` | `f7ffc015` |

### 00114490
Compiled: `08008e8c1200c0112d100000b400cf8d2d600000b000cd8d0d00a019000000002150cf012d58a001c0790c002168ea0101008c250000af8d0300e5152a708b010800e0032d10a001f8ffc015c0790c000800e00300000000`

| Offset | Compiled word bytes | Target word bytes |
|---:|---|---|
| 0x1c | `00000000` | `2150cf01` |
| 0x20 | `2150cf01` | `2d58a001` |
| 0x24 | `2d58a001` | `c0790c00` |
| 0x28 | `c0790c00` | `2168ea01` |
| 0x2c | `2168ea01` | `01008c25` |
| 0x30 | `01008c25` | `0000af8d` |
| 0x34 | `0000af8d` | `0400e515` |
| 0x38 | `0300e515` | `2a708b01` |
| 0x3c | `2a708b01` | `0800e003` |
| 0x40 | `0800e003` | `2d10a001` |
| 0x44 | `2d10a001` | `00000000` |
| 0x48 | `f8ffc015` | `f7ffc015` |

## Registration decision

Do not register any source from this directory. The proofs show no complete exact range. No compiler-impossibility claim is justified. The next investigations should address the specific scheduling and lifetime issues above instead of repeating hint or marker variants.
