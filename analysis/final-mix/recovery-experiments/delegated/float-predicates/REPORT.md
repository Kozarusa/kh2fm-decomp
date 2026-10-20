# Float predicate recovery report

## Accepted proposal for independent integration: 00148638

`sa_float_flag_8.cpp` compiles to 84 bytes and matches all 84 original bytes. `sa_float_flag_9.cpp` independently reaches the same exact bytes but adds an unnecessary fixed-register declaration for the next threshold; variant 8 is the preferred proposal.

The source retains the C++ predicate chain and ordered strict `threshold < value` comparisons. NaN comparisons remain false, including a NaN incoming value; the final fallback writes zero. The sole emitted inline instruction is `lwc1` for the middle threshold at base+0x3c, with its output fixed to `$f1`. The `cc` clobber constrains scheduling around the floating branch; it does not insert a floating comparison or replace any C++ branch. Preloading the next threshold at base+0x40 in C++ lets that load fill the first `bc1t` delay slot. The original also executes that load in the ordinary, non-likely branch delay slot. No additional memory access is introduced relative to the target.

An explicit middle load with `cc` alone produced 88 bytes, inserting a nop after the first branch and loading the next threshold afterward. The C++ preload removes that nop and restores both the original middle-load position and the first branch displacement. All remaining code, registers, comparisons, constants, branch displacements and store instructions match.

## Unresolved: 0010f6f8

The original is 76 bytes. Historical freshfamily_v3 sources reach 76 bytes but use `slt $15,$14,$15`, followed by `beqz $15`, a nop delay, and result one after the branch. The target instead uses `slt $14,$14,$15`, `bnez $14`, result one in the delay, and result zero in fallthrough. The preliminary guards, float load/conversion/multiplication and integer extraction agree.

New C++ branch/lifetime tests produce 72, 80 or 84 bytes. An explicitly emitted signed `slt` with read/write bound register `$14` reproduces the comparison destination and branch direction, but the compiler moves result one before the comparison and leaves a nop delay: 80 bytes, not 76. Result and condition lifetime constraints did not change that placement. These variants are evidence only, not integration proposals. No complete branch or function was replaced by assembly.

This evidence does not establish compiler impossibility. The remaining narrow hypothesis is a source dependency that makes result one available for the branch delay while preserving the signed comparison destination, without preventing delay-slot scheduling or adding a move.

## Reproducibility and scope

All probes use `Public/tools/kh2-audit/probe_fm_source.py`, the pinned image `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`, and its unchanged flags: `-O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections`. The probe verifies original ELF SHA-256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`. No range override was used. Both live boundaries agree with pseudocode sizes. The proofs include complete compiled and target hex plus source SHA-256.

No registration, synchronization, full build, live status/gate/claim change, compiler change or write outside this delegated directory occurred. Root owns independent acceptance and integration. A first runner invocation failed because Windows line endings reached bash; line endings were repaired before probes. WSL required sandbox escalation; approved isolated compiler runs completed.

## Probe inventory

| Source | Compiled/target bytes | Exact | SHA-256 |
|---|---:|---|---|
| sa_float_bound_0.cpp | 84/76 | False | 136da36379789546084f845351dd0c594f61b6de61aecb51e480199b8fa48275 |
| sa_float_bound_1.cpp | 72/76 | False | 7f334e49ba79842fa388b0c12b1cd5a7b3e998cb991abf58ec5aa0cfdf4d0f0b |
| sa_float_bound_2.cpp | 72/76 | False | 0b5213007238183fdc6facf172fa7e0824804647ad5695e94f52988954711b46 |
| sa_float_bound_3.cpp | 72/76 | False | a4d27d1efa0267f50f4cd18b21ceac675804682d63e8191a834d4a771f8f57c4 |
| sa_float_bound_4.cpp | 80/76 | False | 3852c50dcbbc54a0fafbc982d521d1d2973b61ebc71d8782ac10c4428ef9855c |
| sa_float_bound_5.cpp | 80/76 | False | dc2959c3bebf9a4c3a0eaf4aba6e4891140c7d3ca84a7f3421dd353caf2407c5 |
| sa_float_bound_6.cpp | 72/76 | False | 9046414f5af3fb6723248ad4afa35cd110046e92639965e61cdc0f29cae263e4 |
| sa_float_bound_7.cpp | 80/76 | False | c4a3126d16b88da7d98153ebe83afe82ae37715a7d2c657acf6ed1610443687f |
| sa_float_bound_8.cpp | 80/76 | False | ec9a268d64b388d49bfb1744946c4c44a41f12c2a7654fa2b8027e00a1bd3cdb |
| sa_float_bound_9.cpp | 80/76 | False | a08b728dd289ac34b3ce8e5d8dc2cb3af4ceb55d290261f613d68bfac79d6ae0 |
| sa_float_flag_0.cpp | 96/84 | False | aa6d4806efaeaa4809dea29dd7dac8c0095a989c7ffafdc274f1a7d5ff9c926c |
| sa_float_flag_1.cpp | 96/84 | False | 7846f9c8c337cf2e54fbe9035436f5e43b28b11ddb0636174b231f383b412ffa |
| sa_float_flag_2.cpp | 92/84 | False | 1ce46a6f6b53e6db7eb6219e5daaad30552c10c22ef4b392ea692a58396a2cf0 |
| sa_float_flag_3.cpp | 92/84 | False | 47e0d46b5dff9b33c08b68034ebfa5d90e35b44f6cdb6530a960d6be85b00775 |
| sa_float_flag_4.cpp | 88/84 | False | e6fb393fbcad80a28d75b1b5e227de57d4b6ef2fee69c705ac32dfbfc6f4a675 |
| sa_float_flag_5.cpp | 84/84 | False | 02a25002857e84cf75063596fa4e2bcb7cedd995966b5487102038cdaa6c6894 |
| sa_float_flag_6.cpp | 88/84 | False | 9ae2df125a6c7b5211ecec78d29d1d7924c7fefcdb283adb480fd62b424a58cd |
| sa_float_flag_7.cpp | 88/84 | False | d408203ec09c3407d9839d94a57b8b97e05492a190b4361073ad3ef6b2849bc6 |
| sa_float_flag_8.cpp | 84/84 | True | 4186e22334868fad634159110475a35e7991ff33075b87deb162b6fd8f9d9c9f |
| sa_float_flag_9.cpp | 84/84 | True | 1453356dd7baa1970d806e4606e74174925dea0852345336752db2e2c394b77e |

Every listed source has a sibling `.verification.json` and `.probe.log`. `run.sh`, `run2.sh`, and `run3.sh` preserve the batched probe invocations.