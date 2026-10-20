# 0028d140 blocked
- Range: 0028d140, 72 bytes. Versions tried: 0. Best: none; differing words and compiled bytes unavailable (target 72 bytes).
- First difference of the best version: unavailable; no source drafted or probed.
- Changes tried: none. Original sole exit tail-jumps to 0028d188 after calling 00239700. Packet-named fm_primary_queuebeta_recovered_0015d730.cpp declares 00239700 as u64 (...); fm_float_memory_recovered.cpp defines 0028d188 as void(u8*) while writing f0.
- Why it stops here: conservative R12 ABI block; literal R4.3 outgoing callee result transport conflicts with exact packet-named void callee signature under R4.5. Accepted void does not waive R4.3.
- Next hypothesis: resolve the outgoing tail-callee return contract while preserving the packet-named declaration exactly.
- Specialty: abi-layout.
