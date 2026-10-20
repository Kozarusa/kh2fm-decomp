# Round 27 — worker B (isolated) — 3 of 6 recovered

Six 76-byte targets claimed, all verified against the original ELF
(`d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`) with
per-range sha256 and start/end/size agreement against `/root/kh2fm-build/layout.tsv`.
Three match the original byte for byte at equal size. Three do not, and their
residuals are recorded below rather than papered over.

No build was run, no stage was synchronized, no shared output was touched, no
executable bytes were patched, no container was restarted, and no historical
proof was rewritten. Everything here is a proposal in
`analysis/final-mix/recovery-experiments/`.

Two claims in an earlier revision of this report were wrong and are corrected
below: the list of "not started" addresses, and the reading of
`compiler-status.json`. Neither error changed any recovered byte — all three
matches are unaffected — but both were stated as verified when they were not.

## Recovered — complete, equal-size, byte-exact

| address | source | size | probe |
|---|---|---|---|
| 001145b0 | `fm_worker_b_round27_001145b0_v04.cpp` | 76 | 76/76 exact |
| 00158450 | `fm_worker_b_round27_00158450_v04.cpp` | 76 | 76/76 exact |
| 001584f8 | `fm_worker_b_round27_001584f8_v04.cpp` | 76 | 76/76 exact |

Each has a `.verification.json` written by the pinned probe harness, pinning the
source sha256 and recording `exact_match: true` against the original range.

### 001145b0 — linear search over a 7-entry short table

```c
extern "C" u32 func_00114738(void);
extern "C" s16 D_00345d30[8];

s32 func_001145b0(s32 param_1)
{
  s16 *psVar3 = D_00345d30;
  s32 iVar2 = 0;
  do {
    s16 sVar1 = *psVar3;
    if (sVar1 == param_1) return iVar2;
    psVar3 = psVar3 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return func_00114738() + 7;
}
```

Two things were needed and both were non-obvious:

1. **The loop must be `do`/`while`, not `while (1)`.** `while (1)` with an
   internal `break` costs a redundant `beq`/`bne` pair — 96/76. Loading before
   advancing and testing the counter afterwards gives the target's exact
   `lh`/`bne`/`addiu` triple.
2. **The parameter is `s32`, not `s16`.** With an `s16` parameter GCC emits two
   spurious prologue words, `sll a0,a0,16` and `srl a0,a0,0`, re-normalising the
   incoming value as if it had only 16 significant bits (84/76). Declaring the
   parameter `s32` removes both words; the `beq t7,a0` comparison against the
   sign-extended `lh` is then a plain register compare. This is a real finding
   about this compiler, not a quirk of this function: **for a sign-extended
   halfword comparison the parameter must be typed at the width the comparison
   actually happens at.**

### 00158450 / 001584f8 — bitmap word test against a global table

```c
extern "C" u32 func_00242d58(void);
extern "C" u64 D_0034a970[8];

int func_00158450(u64 *param_1)
{
  u32 iVar1 = func_00242d58();
  u64 uVar2 = *param_1;
  u64 uVar3 = D_0034a970[iVar1];
  return (uVar2 & uVar3) != 0;
}
```

`001584f8` is the same shape with `func_00242ce8` and index `iVar1 + 2`.

The load-scale and 64-bit-shift sequence (`dsll`/`dsra` via `ld v0,0(s0)`)
only appears when the two operands are **named 64-bit temporaries**. Writing the
expression inline made GCC synthesise `move v0,s5` and additionally emit a dead
`ld t6,0(t7)` — 72/76.

The table address needed the rounding rule described below: `D_0035a970`
compiles to `lui 0x36`, and the original wants `lui 0x35`, so the table is at
`0x34a970`. The *low* half is unchanged either way, so the decoded address is
identical; only the `lui` immediate differs.

## Attempted, not recovered

| address | best | measured | residual |
|---|---|---|---|
| 00143348 | v13 | 76/76, 2 words | `ld ra,24(sp)` sits after both stores instead of between the `lhu` and the first `sh` |
| 0014a138 | v04 | 76/76, 3 words | 4th-argument constant uses `ori` where the original uses `addiu` |
| 00160ac0 | v05 | 76/76, 2 words | same constant form, plus the `move a1,zero` placement |

### Correction to the "not started" list

An earlier revision of this section listed all thirteen round-25 unstarted
addresses. **That was wrong**, and the error was mine rather than a race:
`round-25/REPORT.md` was written at 06:41, but `round-25/claim.json` was
rewritten at 09:38 and worker B had already written sources at 09:37 for
`00310130, 003102e0, 003103f8, 00310560, 00103500, 001bdcd0, 0023d260, 002421e8`
(`fm_worker_b_round25_*`), with primary separately having started `0014db78`
(`fm_primary_fourwordfresh_*`). My existence check was applied only to the nine
addresses I was considering for this batch; I never re-ran it against the pool I
was reporting as untouched. The report was stale by roughly three hours when this
round began at 10:15.

Still genuinely without any source, as of 11:25:

- round 23, held back this round: 002f3a70, 00308018, 00310048
- round 24: 00224cf0, 003015a8, 00307f90
- round 25: 00316d18, 00192818, 00192940, 00194980

**Process fix:** the next picker must test for the existence of a source per
address, not per report. A report is only as current as its mtime, and
`claim.json` in this project is routinely rewritten after the report it
accompanies.

### 00143348 — where the epilogue restore goes

Thirteen variants were tried: plain C, a memory barrier before the stores,
before the second read, between the stores, a register barrier on the stored
value, a `volatile` out-parameter slot, and the two stores written as volatile
inline asm with and without a memory clobber. All shapes reach 76/76 and the
right store order; none places `ld ra,24(sp)` where the original has it.

What was learned, so the next attempt does not repeat it:

- With no barrier GCC keeps the epilogue pair together after both stores.
- With a memory barrier **before** both stores the `lhu` and both `sh` stay
  adjacent, but GCC still sinks `ld ra` to the end.
- With a memory barrier **between** the stores GCC does hoist `ld ra`, but only
  to the top of the region after the barrier — i.e. immediately before the
  *second* store. That is one store too late; the original has it before the
  first.
- The register barrier (`asm volatile ("" : "+r"(uVar1))`) changes nothing here.
  Round 24's use of it to move a load does not generalise.

I do not have a source that reproduces this. The residual is two words and it is
purely an epilogue placement, so the class is worth keeping open rather than
parking — but I am not claiming it as solved.

### 0014a138 / 00160ac0 — integer-mode versus address-mode constant form

Both functions fail on the same thing, and it is a compiler behaviour worth
recording for the whole project.

For the **fourth** argument the original emits

```
lui   a3,0x15
addiu a3,a3,0xa0a0          # 0014a138
```

whereas GCC — under every spelling tried — emits

```
lui   a3,0x14
ori   a3,a3,0xa0a0
```

Both denote 0x14a0a0. The difference is which of GCC's two constant expansions
runs. Integer mode **rounds** the page (`(V + 0x8000) >> 16`, giving 0x15) and
then needs a negative immediate, so it must use `addiu`. Address mode
**truncates** the page (`V >> 16`, giving 0x14) and uses `ori`. The third
argument, 300000, uses `ori` in the original *and* in every compile, which fits:
that one really is an address-mode constant in the original source too.

So the original passed the fourth argument as a plain integer and the third as a
pointer, and nothing in the C spelling available to me changes how GCC expands an
argument constant. Tried and measured, all producing **byte-identical** output:
declaring the fourth parameter `u32`, `int`, signed `int`, or `void*`; passing the
literal directly; passing it through a named temporary of type `u32` and of type
`int`. All five produced the same object file.

For 00160ac0 the form difference also drags a scheduling difference with it: the
original has `addiu a3,a3,0x9e0` before the argument load and `move a1,zero` in
the `jal` delay slot, while GCC puts `move a1,zero` early and `ori a3,a3,0x9e0`
in the delay slot. Reordering the source arguments did not change it either.

My reading is that this class needs a source-level lever nobody has found yet, or
an explicit decision from primary about whether inline-asm constant
materialisation is in scope for recovery sources at all. I did not use one.

## Standing findings — corrections and additions

1. **Round 25's standing item 1 is stale.** `probe_fm_source.py` now reads
   `WORKSPACE = /mnt/c/Users/KoZa/Documents/AGENTS/Codex` and takes the reference
   ELF from `/root/kh2fm-build/SLPM_666.75`, asserting its sha256 in-process.
   The retired `Documents/ChatGPT` root is no longer involved.
2. **Docker Desktop on this host rejects `/mnt/c/...` bind sources.** The mount
   comes up empty and the inner script is reported missing
   (`objdump_orig_inner.sh: No such file or directory`). Helper scripts must bind
   `C:/Users/...` and must run with `MSYS_NO_PATHCONV=1`.
3. **The probe harness only auto-defines `D_([0-9a-f]{8})` and `func_([0-9a-f]{8})`.**
   A global named `DAT_0033b96c` fails to link with
   `undefined reference to 'DAT_0033b96c'`. Recovery globals must be `D_xxxxxxxx`.
4. **Page rounding confirmed and now bounded.** A constant materialised in
   integer mode gets `lui = (V + 0x8000) >> 16`: 0x33b96c → 0x34, 0x32b96c → 0x33,
   0x358800 → 0x36, 0x348800 → 0x35, 0x35a970 → 0x36, 0x34a970 → 0x35. A constant
   materialised as a **call argument** gets the truncating address-mode form
   instead (`V >> 16` with `ori`). Decoding a `lui`/`ori` or `lui`/`addiu` pair
   into an address is therefore only safe when the form is already known — for an
   argument pair the low half plus the truncating high half is the correct read.
5. **Sources need a trailing newline** or the probe emits
   `warning: no newline at end of file`.
6. **`compiler-status.json` does not say primary is idle.** It reads
   `"state": "isolated-probes"`, `"phase": "workerbacklog-independent-curation"`,
   and `"Primary is independently probing 118 delivered worker proposals."` An
   earlier revision of this report recorded it as `idle` and used that to justify
   the overlap check. The file's mtime is 04:44, so it already said this when it
   was read. Verify the status file's *contents*, not a remembered summary.
7. **`primary-claim.json` is no longer a usable exclusion list.** It lists 11
   addresses and has an mtime of 04:44, while primary has since produced 118
   `fm_primary_workerbacklog_recovered_*.cpp` sources and a
   `primary-workerbacklog-audit-v1.json` backlog audit. Overlap must be checked
   against the audit and the produced sources directly. For this batch I did:
   none of the six appears in the audit, and none has a
   `fm_primary_*` source, so there is no collision with primary.
8. **Primary was writing concurrently with this round.** Its checkpoint file
   landed at 11:21 and 118 recovered sources at 11:22, while this round was
   finishing. The recovery-experiments directory grew from 6202 to 6642 files
   during the round, so file counts taken early in a round do not describe the
   workspace at the end of it.

## Assessment of the batch

Three of six, all from the same frame class, with two of the three recovered by
one-line type corrections rather than by structural reconstruction. That is a
better rate than round 25's 0 of 3 and round 24's 5 of 16, and it suggests the
picker should not skip targets whose bodies already look close to a natural C
spelling. The two failures share one root cause that is now documented, so
0014a138 and 00160ac0 should be requeued as a single question rather than two.
00143348 is one scheduler question, not two, and should be requeued as such.