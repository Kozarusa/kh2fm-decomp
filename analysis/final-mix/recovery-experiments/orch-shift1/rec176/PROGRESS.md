# rec176 progress
start 2026-10-18T02:17:24Z
claim-attempt 1 of 6
claim 1 of 6: 00294480 token 6af906661fc34072bff089dec2857ff8 attempts 1 blocker null
00294480 R4.3: a0 pointer; all exits return v0 normalized result. R4.5 declarations copied from packet accepted 001d7940. v1 fresh baseline.
00294480 v1: 1 words; best v1 1 words; streak 0. First diff19 slt/sltu. v2 baseline orch1_rec176_00294480_v1.cpp; single C11(d) guard at signed callee-result comparison; declaration unchanged.
00294480 v2: 0 words; best v2 0 words; streak 0. R8 audit passed: one function, numeric bindings none, one explained empty guard, R4.3 normalized return all paths, R4.5 exact declarations. submitted 00294480 v2
claim-attempt 2 of 6
claim 2 of 6: 00294550 token 19d8b6c10ab54f2aae741aab084f7861 attempts 1 blocker null
blocked 00294550 -> abi-layout; R4.3 mixed untouched entry and callee result exits; zero versions
claim-attempt 3 of 6
claim 3 of 6: 00294e48 token fbc49656a6b34ee5aeac52e936fbf4dd attempts 1 blocker null
00294e48 R4.3 no params; outgoing v0 on both paths, return s64 retains LoadDataIsFlushing s64 and LoadDataSetText u32 result. R4.5 copied accepted signatures 00292630,00293fc0,002908f0. v1 fresh baseline.
00294e48 v1: 8 words; best v1 8 words; streak 0. C1 full path/signature audit: unsigned u32 to s64 requires absent zero extension; conservative mixed-width ABI block.
blocked 00294e48 -> abi-layout
claim-attempt 4 of 6
claim 4 of 6: 00295228 token 3cdf41718a5c47dba526fd17414af0c3 attempts 1 blocker null
00295228 R4.3 a0 u32; v0 signed byte all exits. R4.5 accepted 002956c0 signatures copied. Unsigned shift and address transport defined. v1 fresh baseline.
00295228 v1: 0 words; best v1 0 words; streak 0. R8 audit passed; signed return all exits, exact accepted callee declarations, no asm, unsigned defined arithmetic. submitted 00295228 v1
claim-attempt 5 of 6
claim 5 of 6: 00295810 token 00ab57ad42924b2cbc9b09bd05878af6 attempts 1 blocker null
blocked 00295810 -> abi-layout; R4.3 mixed untouched entry and callee result exits; zero versions
claim-attempt 6 of 6
claim 6 of 6: 00296b08 token ab782ed5571a4b239a5ec6c371b4e38a attempts 1 blocker null
blocked 00296b08 -> abi-layout; R4.3 mixed untouched entry and callee result exits; zero versions. K6 claim-attempt limit reached.
R11 WP-REPORT.md written; done 2026-10-18T02:20:29Z
Reviewer correction: 00294480 v1-to-v2 combined an initialized s32 result temporary (C11(b)) and an empty guard (C11(d)); original entry named only guard. No isolated temporary or guard effect is established. Final source semantics independently approved; 00295228 unaffected. Future temporary/guard experiments must separate controls. Documentation only; recovery remains closed.
