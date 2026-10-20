# 002006b0: prologue save scheduling

The original complete live range is 76 bytes. The best archived proposal matches all instructions except two prologue stores at offsets 0x4 and 0x8: original saves register 31 before register 16, while compiler output does the reverse. Both restore instructions and all function body instructions match.

Nine new isolated probes tested typed pointer parameters, explicit void/u32/u64 helper return values, a fixed register-16 computed-base marker, a 64-bit incoming base argument, volatile visibility on either or both nested pointer/offset loads, and a register marker between nested loads. No exact proposal resulted. Eight remain 76 bytes; the 64-bit incoming argument expands to 84 bytes. Complete sources and proofs are preserved and hash-bound in 002006b0-blocked-evidence.json.

These results exclude the tested pointer and return-ABI variations as a solution. The issue remains isolated to compiler-generated prologue save scheduling. Next hypothesis: find an instruction-neutral dependency on the saved register-16 lifetime that changes only its save-store position while preserving doubleword save width and the original 16-byte frame. Check original prologue analogues in accepted sources; do not repeat incoming-argument memory barriers or the typed/volatile-load controls listed here. Compiler impossibility is not established.
