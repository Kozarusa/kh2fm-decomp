# Worker manual (read all of it before your first command)

You are a recovery worker for the KH2FM project: Kingdom Hearts II Final Mix, Japanese PS2 executable `SLPM_666.75`. Your job is to write C++ functions that the pinned PS2 compiler turns into exactly the original machine instructions, one function at a time, and to hand each exact result to the orchestrator through the work queue.

This manual is complete. Do not read other project documents, do not explore the folders, and do not invent steps. If something happens that this manual does not cover, take the safe action in R12 and report it. Your brief (the second file you were given) adds your WP id, directories, queue names, numbers and, for some WPs, one extra file to read. The files this manual and your brief name are the only files you read, plus the packet, earlier attempts and accepted sources that the packet points to.

## The five rules that are never broken

1. **Exact or nothing.** A target is done only when the probe prints `Exact probe matches: 1/1`. Two differing words is a failure. Never submit anything else.
2. **Write only inside your WP directory.** Never edit, move, or delete any other file. In particular never touch `Public/tools/**` (registries, layout, sources, audit scripts), the queue database, `/root/kh2fm-build` (except through the probe command), any `.md` outside your WP directory, or any earlier experiment.
3. **Never overwrite, never delete.** Do not delete any file, even your own unprobed drafts (deletes are blocked and stop your WP); a broken version simply stays, and the next one gets the next number. Every probe uses a new file name (`_v1`, `_v2`, ...). The probe rewrites `<name>.verification.json` and reuses a compiler scratch folder named after the file, so reusing a name destroys evidence.
4. **Only the commands in this manual.** This applies to every agent and model: if your tool offers another way to do something, still use these. No full builds, no `make`, no registration, no `resolve`, `pause` or `resume` on the queue, no Docker restarts, no Ghidra, no package installs, no git.
5. **Do not ask the user or the orchestrator questions.** Every decision is answered below. When stuck, block the target (R9) and continue.

## Fixed facts

| Thing | Value |
| --- | --- |
| Workspace root (run every command from here) | `C:\Users\KoZa\Documents\AGENTS` |
| Tools | `Codex\orchestration\tools\kh2w.py` (packet, diff, probe), `Public\tools\kh2-audit\recovery_queue.py` (queue) |
| Compiler | `ee-g++ 3.2-ee-040921`, flags `-O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections`, fixed. You never call it directly. |
| Calling convention (EABI) | Integer and pointer arguments in `a0 a1 a2 a3 t0 t1 t2 t3` (`$4`-`$11`), float arguments in `$f12`-`$f19`, integer return in `v0` (`$2`), float return in `$f0`. Word and float arguments use separate register banks. |
| Types (from `types.h`) | `u8 s8 u16 s16 u32 s32 u64 s64 f32`. `int` is 32-bit, `long` is 64-bit, pointers are 32-bit. Use the short names; never `long`. |
| Names | The function is `func_<address>`. A global is `D_<address>`. A called function is `func_<address>`, or `D_<address>` when the packet says it is defined in legacy assembly. Addresses are 8 lowercase hex digits. |
| Shell | Use the PowerShell tool for every command. Commands below are written for it. |

`<WP>` below means your WP id (for example `rec01`), `<WORKER>` your worker id (for example `orch1-rec01` for a Claude subagent, `cdx1-rec06` for Codex, `opc1-rec07` for opencode; the launch prompt gives it to you), `<DIR>` your WP directory as a Windows path, `<WSLDIR>` the same directory as a WSL path (both are in your brief), `<QUEUE>` a queue name from your brief, `<A>` the target address, `<TOKEN>` its lease token, and `<N>` the version number.

## R0. Set up (once)

1. Create `<DIR>\PROGRESS.md` with the first line `# <WP> progress` and a line `start <UTC time>`. Append one line to it after every step below. It is your memory if you are restarted.
2. If `<DIR>\PROGRESS.md` already exists, you are a restarted worker: read it, then go to R1 or R5 for the target it names as in progress. Your old lease may have expired. If R10 says the lease is gone, claim the same address again with `--address <A>`. If that returns no lease, the address is gone; continue with R1.

## R1. Claim one target

```
python Public\tools\kh2-audit\recovery_queue.py claim --worker <WORKER> --queue <QUEUE> --count 1
```

Use the queues your brief lists, in order. Move to the next queue only when the current one returns no lease.

- The output is JSON. Copy `address`, `token`, `attempts` and `blocker` into PROGRESS.md as `claim <N> of <K>: <A> token <TOKEN> attempts <n>`, where N counts every claim you have made in this WP, including ones you later blocked. Before each claim, count the `claim` lines already in PROGRESS.md; if that count equals K, do not claim.
- `"leases": []` with `"paused": true`: the orchestrator is integrating. Write your WP report (R11) with "stopped: queue paused" and stop.
- `"leases": []` without `paused`: that queue is empty. Try the next queue in your brief. When all are empty, write your WP report.
- Stop claiming when you have claimed the number of targets your brief gives (K). Then write the WP report.

## R2. Build the target packet

```
python -I Codex\orchestration\tools\kh2w.py packet <A> <DIR>
```

Read `<DIR>\<A>-packet.md` completely. It contains the range and size, decoded global addresses, callees with registry names and legacy-assembly flags, accepted sources that call the same functions, Ghidra pseudocode, and every earlier attempt. If `blocker` in the claim was not null, also read the report file it names. You must not repeat a change that report says already failed.

The `; = D_xxxxxxxx` annotations are computed in instruction order. After a branch target they can be missing. To compute one by hand: address = (`lui` value << 16) + the signed decimal offset printed by objdump.

## R3. Decide whether to attempt the target

Block immediately, without probing (R9, zero versions), when the packet shows any of these:

| Condition | Specialty for R9 |
| --- | --- |
| The range contains no `jr ra` and does not end with `j`/`jal`+delay slot (a range whose `jr ra` is in the middle and that ends with a `b` back into the range is a normal function with loop blocks placed after the epilogue: attempt it; a range with no `jr ra` whose last instruction is a `b` back into the range is a never-returning loop: attempt it with `while (1)`), or contains words objdump prints as `.word`/unknown, or the Ghidra signature is for a different size, or the range is all zeros | `boundary-review` |
| More than 128 bytes and your brief says "general, sonnet" | Release instead: `recovery_queue.py release --address <A> --token <TOKEN>`, and note `released: size` in PROGRESS |
| `syscall`, `eret`, `di`, `ei`, `mtc0`/`mfc0`, or `sync.p` appears and no accepted source in the packet shows the same instruction | `privileged-instructions` |
| A `break` trap appears (`__builtin_trap` emits `teq`, not `break`) | Fix every other difference first with the normal R7 budget. When the trap is the only difference left, replace `__builtin_trap()` with exactly `asm volatile("break 0"); // why: original traps with break, __builtin_trap emits teq` (use the code the original shows). That one line is the only allowed instruction asm for traps (orchestrator ruling 2026-10-13, precedent queueomega 00308dc0 `break 7`). |
| VU macro instructions (`vadd`, `vmul`, `lqc2`, `sqc2`, `qmtc2`, `qmfc2`, `cfc2`, `ctc2`, `$vf` registers) and no accepted sibling with a similar sequence | `vu-macro` |

Everything else: attempt it.

## R4. Write version 1

File name: `<DIR>\orch1_<WP>_<A>_v1.cpp`.

**Start from the best earlier attempt when one exists.** If the packet's "Earlier attempts" lists a non-exact version with 6 or fewer differing words, your version 1 is a copy of that source file. Change only these things: the file name, the include line (make it exactly `#include "../common/types.h"`), anything R4 rules 1, 2 and 7 forbid, and its `D_` names, which you check against the packet. Then probe it and continue at R6. Also read that attempt's report or blocker file if the packet lists one, so you skip changes already tried.

Otherwise use this layout exactly:

```cpp
#include "../common/types.h"
// Every typedef, union and extern declaration goes here, before the function.
extern "C" s32 D_0032b984;                 // a global read or written by the function
extern "C" u8 D_0033cb80[];                // a global whose address is passed or indexed
extern "C" s32 func_00103b38();            // a called function
extern "C" void func_00102080(u8*);

void func_00105de0(s32 value) {
    // body
}
```

Rules for version 1:

1. **Exactly one function**, named `func_<A>`, and nothing after its closing brace. The curation step drops declarations placed after a function, and that later fails the batch.
2. **Includes:** only `#include "../common/types.h"`, plus `#include "../kn/fvector.hpp"` when you use its vector type. Write them exactly like that; the probe rewrites these two paths.
3. **Signature from the instructions, not from Ghidra.**
   - Count parameters from which argument registers are read before being written: `a0`.. then `t0`..; floats from `$f12`...
   - An entry `andi aN,aN,0xff` means that parameter is `u8`; `0xffff` means `u16`.
   - The return type follows `v0` (integer or pointer) or `$f0` (`f32`). A function that leaves a callee's `v0` untouched and returns returns that value: write `return func_x(...)`.
   - Use `void` only if `v0` and `$f0` are never set on any path and no callee result flows out.
4. **Globals:** take every address from the packet's `D_` annotations. Pick the type from the access: `lb` s8, `lbu` u8, `lh` s16, `lhu` u16, `lw`/`sw` s32 or u32 (or a pointer), `ld`/`sd` s64, `lwc1`/`swc1` f32, `lq`/`sq` Quad (see C14). If the address is only formed (`lui`+`addiu`) and passed or indexed, declare an array `u8 D_x[]`.
5. **Callees:** if the packet lists an accepted source that already calls the function, copy that declaration exactly. Otherwise write one from the argument registers set before the `jal`. If the packet flags it as legacy assembly, declare it as `extern "C" <ret> D_<callee>(<args>);` and call `D_<callee>(...)`.
6. **Body:** mirror the original block order. Write conditions so the first block in the original is the first block in your code. Write early returns where the original jumps to the epilogue. Write stores in the same order as the original.
7. **No Ghidra names** (`param_1`, `iVar1`, `uVar2`, `DAT_`, `FUN_`, `undefined4`). Use plain names: `value`, `object`, `index`, `count`, `result`, `flag`, `pointer`.
8. **No assembly in version 1**, except VU macro instructions or privileged instructions the compiler cannot produce. For those, copy the pattern from the accepted sibling named in the packet.

## R5. Probe

Before every probe, renew the lease (R10). Then:

```
python -I Codex\orchestration\tools\kh2w.py probe <DIR>\orch1_<WP>_<A>_v<N>.cpp
```

This runs the project's probe through shared slots (at most 3 probes run at once across all agents; it waits up to 15 minutes for a free slot). It refuses a file name whose `.verification.json` already exists: that means you reused a version name, so copy the source to the next version name and probe that. It prints `Exact probe matches: <x>/1` and `Detailed proof: ...`.

- `Exact probe matches: 1/1`: go to R8.
- `Exact probe matches: 0/1`: go to R6.
- A compiler error (`error:` lines, non-zero exit, no "Exact probe matches" line): read the first error and fix the source in a new version. A compile error counts as a version. Common causes: a declaration missing or after the function, a type not in `types.h`, or a symbolic register name such as `"$t7"` (use `"$15"`).
- `docker`/`wsl` errors: run the same command once more. If it fails again, release the target (`recovery_queue.py release --address <A> --token <TOKEN>`), write the WP report with "stopped: environment failure" plus the error text, and stop.

## R6. Read the difference and pick one change

```
python -I Codex\orchestration\tools\kh2w.py diff <DIR>\orch1_<WP>_<A>_v<N>.verification.json <DIR>\orch1_<WP>_<A>_v<N>.diff.txt
```

Lines starting `!!` differ. Read the first differing line and the lines around it. Find the first matching row in the cookbook below (C1 is checked first, then C2, and so on) and make **exactly one** change, the first one listed in that row that you have not tried on this target. Write the next version (`_v<N+1>`), then probe again (R5). One change per version, so every effect can be attributed.

Append to PROGRESS.md: `v<N>: <differing words> words, first diff at <index>: <cookbook id> -> next: <change>`.

### Cookbook (symptom in the diff, then changes to try in order)

Every 8-digit address in the Evidence column is an accepted, exact source you can open read-only and copy from: `Public\tools\kh2-reference\src\anon\*<address>*.cpp` (for example `fm_primary_queunuprime_recovered_00194830.cpp`). The SDK frame-pointer pattern (C19) is in `fm_primary_queuekappaprime_recovered_002b6b84.cpp`. Copy patterns, not whole functions.

| Id | Symptom | Changes to try, in order | Evidence |
| --- | --- | --- | --- |
| C1 | Compiled size differs by 8 or more bytes, or whole blocks are missing or extra | (a) Re-read the original top to bottom and check every parameter, return and callee argument against R4.3. (b) Check that every original path (each `jr ra` and each branch target) exists in your code. (c) Add the missing float arguments or float return (C4). | most fresh-size failures |
| C2 | `lb`/`lbu` or `lh`/`lhu` differ | Flip the signedness of that variable or global type (`s8`/`u8`, `s16`/`u16`). | README one-word batch |
| C3 | Original starts with `andi aN,aN,0xff` and compiled does not (or the reverse) | (a) Make that parameter `u8` (or make it `u32` to remove the mask). (b) Keep `u32` and write `(value & 0xff)` where it is used. | 00106a18 accepted; 00160488 note |
| C4 | `lwc1`/`mov.s`/`$f` registers in original only, or a float result in `$f0` | (a) Return `f32`. (b) Add `f32` parameters for `$f12`... (c) In callee declarations, put all word parameters first and float parameters after. | 001142e0, 002cba50, medium vector rationale |
| C5 | An address differs by exactly 0x10000 in one `lui`, or the low halves differ | You decoded a low half as unsigned. Recompute it from the packet annotation (signed) and fix the `D_` name. | callbackaddress batch |
| C6 | Original `xori t,t,K` + `beqz`/`beqzl`, compiled `li t,K` + `beq`/`beql` (or the reverse) | Rewrite `x != K` as an early `if ((x ^ K) == 0) return;` (or the reverse). | selftest 00105de0: 12 to 8 words |
| C7 | Branch sense flipped (`beqz` vs `bnez`) or the two blocks after a branch swapped | (a) Negate the condition and swap the if/else bodies. (b) Turn `if (a \|\| b)` into two separate `if` statements, or the reverse. (c) Change an early `return` into an if/else, or the reverse. | 00106a18 (4 words to exact), 00188fe0 |
| C8 | `movn`/`movz` in compiled, branch or branch-likely in original (or the reverse) | (a) Keep the temporary and the result in separate variables. (b) Write the condition the other way round. (c) Make the conditional read `volatile`. | 0018dbd8 note, 001585a0 |
| C9 | Compiled loads early (into a delay slot or before the branch); original loads only on one path | Read the value through a `volatile` pointer or variable at the place the original loads it. | medium vector rationale |
| C10 | Same instructions, stores in a different order | (a) Reorder the source statements to the original store order. (b) Rotate the order of independent zero stores. (c) Make the stores `volatile`. (d) Add `asm volatile("" ::: "memory");` between two stores. Add the comment `// why: keeps store order`. | 00132270, 002d96d8 |
| -- | Asm that emits an instruction (for example `asm("xori %0,%1,0" ...)`, `asm("addu ...")`) | Never write one. The only allowed asm is empty (`asm("" : "+r"(x))`, `asm volatile("" ::: "memory")`) plus three precedent cases: an lq/sq copy primitive after a plain copy has failed, VU macro asm with an accepted sibling holding the same sequence, and a single `break` trap line as the last difference (see the break row). A version that needs any other instruction-emitting asm is a block, not a fix. | rec94 001bfd60 (xori, not submitted) |
| C11 | Same instructions, different registers only (`t6` vs `t7`, `a1` vs `a2`) | (a) Reorder statements that compute the values. (b) Introduce or remove a temporary variable. (c) Bind the value with `register T name asm("$15") = ...;` using the original register number (`t5`=13, `t6`=14, `t7`=15, `a0`=4, `a1`=5, `v0`=2, `s0`=16, `fp`=30). (d) Add `asm("" : "+r"(name));` after the assignment. Write a `// why:` comment for (c) and (d), on the same line or the line directly above each binding or guard. One comment above a group of bindings covers only the first one, so give every binding line its own comment. To read a value the caller leaves in a non-argument register (for example v0), never read an uninitialised binding (undefined behaviour); bind it and define it with an empty output asm: `register u8* entry asm("$2"); asm("" : "=r"(entry)); // why: caller leaves the value in v0`. | queuexiprime 00138140, 2,573 accepted uses |
| C12 | Compiled saves an extra `s` register or uses a bigger frame | (a) Do not bind locals to `s` registers. (b) Keep the value you return in its own variable and pass a separate copy to the callee. (c) Remove `volatile` from locals. | 0017c8f0, 001b6f48 |
| C13 | Original ends with `j func` (tail call) and compiled uses `jal` plus its own return, or the reverse | Make the call the very last statement with nothing after it. If the original returns the callee's result, write `return func_x(...);`. | ABI (example original: 00105da8) |
| C14 | `lq`/`sq` 16-byte moves | Add `typedef unsigned int Quad __attribute__((mode(TI)));` at the top and copy `Quad` values. Make a conditional quad read `volatile` (C9). | queuexiprime vector batch |
| C15 | `sllv`/`srlv`/`srav` with a variable count, compiled adds a mask | Use a one-instruction primitive with a `// why: native shift wraps the count` comment, copied from the `00194830` accepted source. | queunuprime |
| C16 | `cvt.w.s`/`cvt.s.w` differs from the compiled conversion | Copy the CVT primitive pattern from the `0016df28` accepted source. | queunuprime |
| C17 | The call target is wrong only in the full build (orchestrator tells you), or the packet flags a legacy callee | Declare and call `D_<callee>` instead of `func_<callee>`. | queueepsilonprime |
| C18 | Mixed byte/half/word writes through one cursor, and compiled drops a reload | Access the memory through one union type that has the u8, u16 and u32 members. | 00133938 |
| C19 | Original sets and restores a frame pointer (`daddu ...,$29`, `$30`) around an SDK gateway call | Copy the frame-transport pattern from an accepted SDK wrapper source (packet sibling list, or 002b6b84). | 002b6b84, sdk-wrapper rationale |
| C20 | 64-bit instructions (`daddu` on values, `dsll`, `dsra`, `ld`/`sd` of data, not of saved registers) | Use `s64`/`u64` for that value. `move` encoded as `daddu rd,rs,zero` and `sd`/`ld` of saved registers in the prologue are normal and need nothing. | ABI |
| C21 | 30 or more words differ and none of C1-C20 explains the first one | Rewrite from scratch, mirroring every original block in order (R4.6). This counts as one change. | |

## R7. Budget: when to stop trying

- sonnet workers: at most **8 versions** per target. opus workers: at most **12**.
- Stop earlier when **3 consecutive versions** do not beat the best differing-word count so far. Count from the version that set the best: if v1 is best and v2, v3 and v4 do not beat it, v4 is your last version (do not write v5). A compile error counts as a version that did not beat the best. After each version, write one line in your notes before deciding the next step: `<address> v<N>: <W> words; best v<B> <BW> words; streak <S>` (S is the number of versions in a row since the best that did not beat it). When S reaches 3, stop. Only a lower differing-word count is an improvement: a gain in compiled size or a later first difference with the same or a higher word count still adds 1 to S. Your blocked report names v<B> as the best.
- When the budget ends, go to R9. A near miss is still blocked, never submitted.

## R8. Submit an exact match

1. Renew the lease (R10).
2. Check the source against the review rules: one function, nothing after it, no Ghidra names, a `// why:` comment on or just above every line with emitted assembly or a register binding, no symbolic register names, no `.word`.
   - If a rule fails, fix it in a new version and probe again. The fix must still be exact.
3. Submit:

```
python Public\tools\kh2-audit\recovery_queue.py submit --address <A> --token <TOKEN> --source <DIR>\orch1_<WP>_<A>_v<N>.cpp --proof <DIR>\orch1_<WP>_<A>_v<N>.verification.json
```

4. Write `<DIR>\<A>-REPORT.md`:

```
# <A> submitted
- Range: <A>, <bytes> bytes. Source: orch1_<WP>_<A>_v<N>.cpp (exact). Versions tried: <N>.
- Changes that mattered: <cookbook ids and one line each>.
- Emitted assembly or register bindings: <none | list with the reason for each>.
- Provisional: names and types are inferred from instructions only.
```

5. PROGRESS line: `submitted <A> v<N>`. Go to R1.

## R9. Block a target

1. Write `<DIR>\<A>-BLOCKED.md` (it must not be empty):

```
# <A> blocked
- Range: <A>, <bytes> bytes. Versions tried: <N>. Best: v<B> with <D> differing words (<compiled>/<target> bytes).
- First difference of the best version: <copy the first !! line from its .diff.txt>.
- Changes tried: <cookbook ids, one line each, with the word count after each>.
- Why it stops here: <budget reached | no improvement for 3 versions | R3 condition>.
- Next hypothesis: <the next cookbook change not tried, or the R3 reason>.
```

2. Choose the specialty from this table, using the symptom of the best version's first difference:

| Symptom | Specialty |
| --- | --- |
| Only register numbers differ (C11) | `register-allocation` |
| Store or load order (C9, C10) | `store-order` |
| Branch sense, block order, branch-likely, conditional moves (C6, C7, C8) | `branch-layout` |
| Frame size, saved registers, prologue or epilogue order (C12) | `prologue-epilogue` |
| Float arguments, results or conversions (C4, C16) | `float-transport` |
| Structures, varargs, stack arguments, frame pointer (C18, C19) | `abi-layout` |
| `lui`/`addiu` placement or address materialization (C5) | `address-materialization` |
| R3 VU condition | `vu-macro` |
| R3 boundary condition | `boundary-review` |
| R3 privileged condition | `privileged-instructions` |
| 30+ words differ, structure unclear (C21) | `large-control-flow` |

3. Block:

```
python Public\tools\kh2-audit\recovery_queue.py block --address <A> --token <TOKEN> --specialty <specialty> --report <DIR>\<A>-BLOCKED.md --hypothesis "<the next hypothesis line>"
```

4. PROGRESS line: `blocked <A> -> <specialty>`. Go to R1.

## R10. Keep the lease alive

```
python Public\tools\kh2-audit\recovery_queue.py heartbeat --address <A> --token <TOKEN>
```

Run it before every probe, before submit and block, and whenever more than 5 minutes have passed since the last one. A lease lasts 15 minutes.

If any queue command answers `Missing, expired, or superseded lease`, you no longer own the target. Stop working on it, keep your files, write `lost lease <A>` in PROGRESS, and go to R1.

## R11. The WP report (your final answer)

Write `<DIR>\WP-REPORT.md`, then reply with exactly the same text. Format:

```
# <WP> report
Status: done | partial | stopped: <reason>
Worker: <WORKER>, model <model>. Started <UTC>, ended <UTC>.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| <A> | <n> | submitted / blocked:<specialty> / released / lost lease | <n> | 0 or <D> | orch1_<WP>_<A>_v<N>.cpp |

The File column names the submitted version, or for a blocked target the best version (the one with the fewest differing words, the earliest on a tie), never simply the last version written.

Totals: <s> submitted, <b> blocked, <r> released.
Problems: <none | each problem in one line>.
Exact next step (only if partial or stopped): <one sentence>.
```

Never claim a result the queue does not show. The orchestrator checks every line.

## R12. Stop conditions and safe actions

| Situation | Action |
| --- | --- |
| The orchestrator sends "STOP" | Finish the probe that is running. If the current target is exact, submit it (R8). Otherwise block it (R9) if it has at least one version, or release it if it has none. Then write the WP report with "stopped: orchestrator". |
| Claim says paused | Write the WP report with "stopped: queue paused". |
| A permission prompt is denied, or a command is blocked | Do not retry it. Release the current target, write the WP report with "stopped: permission" and the command text. |
| Environment failure twice (R5) | Release the target and write the WP report with "stopped: environment failure". |
| You notice you edited a file outside `<DIR>` | Say so in the report under Problems with the exact path. Do not try to undo it yourself. |
| Anything not covered here | Do the most conservative of: block the target with your evidence, or release it. Then continue with R1. |
