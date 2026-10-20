"""Build round-4/claim.json: worker-b round 4 record (5 exact, 5 assigned targets
still pending, 4 self-selected unresolved).

Runs under BOTH Windows python and WSL python3. ROOT is derived from __file__
rather than hardcoded, because a Windows-style root joined onto a POSIX path
silently produces a path that does not exist under WSL.
"""
import json, hashlib, os

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                   *[".."] * 5))


def sha(rel):
    try:
        return hashlib.sha256(open(os.path.join(ROOT, rel), "rb").read()).hexdigest()
    except OSError:
        return None


solved = {
    "00150de0": {"bytes": 28,
                 "mechanism": "Six-parameter signature: the stored value is the incoming $t1 (6th u32 arg) and the tail call passes -1 as that 6th argument. Ghidra mis-called it in_t1_lo."},
    "0017dec0": {"bytes": 36,
                 "mechanism": "Both globals addressed through one pointer so GCC CSEs the second address into addiu t6,t7,1320 + sw zero,4(t6); inline-asm absolute symbol definitions pin them at 0x1c60528/0x1c6052c."},
    "00229d40": {"bytes": 40,
                 "mechanism": "cvt.s.w $f12,$f12 requires a genuine int->float cast of a loaded int, and the fifth argument must be a float parameter."},
    "002e8290": {"bytes": 40,
                 "mechanism": "Binding the global to a u32 local first makes GCC hoist lui t7,0x36 and keep a0 as the load base, delaying move a0,t6 to the last slot before the jump."},
}
for addr, info in solved.items():
    src = "analysis/final-mix/recovery-experiments/fm_worker_b_round4_%s_solved.cpp" % addr
    # the probe harness writes <stem>.verification.json, i.e. it drops the .cpp suffix
    proof = src[:-4] + ".verification.json"
    row = json.load(open(os.path.join(ROOT, proof)))["rows"][0]
    info["source"] = src
    info["source_sha256"] = sha(src)
    info["proof"] = proof
    info["exact_match"] = row["exact_match"]
    info["boundary_agreement"] = row["boundary_agreement"]
    info["compiled_size"] = row["compiled_size"]
    info["target_size"] = row["target_size"]
    assert row["exact_match"] and row["boundary_agreement"], addr

unresolved = {
    "0030f690": {"bytes": 16, "diff": "16 vs 20 bytes",
                 "blocker": "GCC always materialises a 16-byte ra-only frame around the sibling call; the original is frameless. Rejected: callee __attribute__((noreturn)) (forces a real jal, 24 B), caller __attribute__((noreturn)) (28 B), returning the callee u32 (32 B), __builtin_unreachable() (link failure), long params (36 B), static helper indirection (32 B), literal arg (24 B)."},
    "0030a300": {"bytes": 12, "diff": "12 vs 20 bytes",
                 "blocker": "Same frameless-sibling-call blocker as 0030f690. The absolute-symbol lui v0,0x36 / lw a0,24940(v0) otherwise matches (GCC picks t7 instead of v0)."},
    "002f1e00": {"bytes": 24, "diff": "lui+lw vs gp-relative lw",
                 "blocker": "Environment-limited, not source-limited. The target uses lw a0,-7456(gp) to reach an absolute symbol at 0xffffe2e0, i.e. gp-relative small data. The probe harness linker script defines only func_<8hex>/D_<8hex> and never _gp, so GCC always falls back to lui a0,0x2f / lw a0,0x1e20(a0). Reproducing it needs the real linker script. The target implies gp == 0 (0xffffe2e0 + 7456 == 0)."},
    "001ac700": {"bytes": 40, "diff": "1 word",
                 "blocker": "Target emits lw a1,128(t6) BEFORE ld ra,0(sp); all 35 variants emit ld ra first. Every other word matches (li t7,4 / sd ra / move t6,a0 / sw t7,112(a0) / li a0,34 / j 0x1991a8 / addiu sp). Rejected: load bound to a local before or after the store, volatile store or load, asm volatile memory barrier (36 B), asm(\"\") with +r / +m constraints, comma-expression assignment, u32*/long/s32 param types, struct with u32 array, u32* local, reversed statement order (52 B), register u32 x asm(\"$t6\") (compile failure)."},
}

extra = {
    "0014b950": {"bytes": 88, "differing_words": 6,
                 "blocker": "Not yet probed: pinned compiler unavailable (Docker down). All six differing words are in the 64-bit shift/or group. Target ends with or a2,a2,a3 / or a1,a1,t0 / or a1,a1,a2; compiled emits or a2,a2,t0 / or a1,a1,a3 / or a1,a1,a2. The or operands are crossed, so the two 32-bit halves are combined in the opposite association order from the registered source's | chain.",
                 "caveat": "The R5900 64-bit shift words (function codes 0x38-0x3f) have a different operand field order from vanilla MIPS and were NOT verified against the pinned ee-objdump, so r4_decode.py prints them as (unverified R5900 shift fields). This affects only this target.",
                 "next": "fm_worker_b_round4_0014b950_v01/_v02 (or-pairs grouped into named s64 locals)."},
    "00109e30": {"bytes": 92, "differing_words": 6,
                 "blocker": "Not yet probed. Target uses andi a0,a0,0x00ff then beq a0,zero, and places sd ra,8(sp) before the branch; compiled sign-extends with sll/sra (a char parameter) and branches bne. Target's fall-through is the non-zero call func_00133f80, with func_00133f60 out-of-line at offset 76.",
                 "next": "fm_worker_b_round4_00109e30_v01 (u8 parameter, non-zero arm inline), _v02 (u8 parameter, Ghidra polarity)."},
    "00242500": {"bytes": 92, "differing_words": 6,
                 "blocker": "Not yet probed: pinned compiler unavailable (Docker down). Target branches beq v0,zero to an out-of-line arm at offset 72; the inline arm calls func_001058e8, loads lw t7,0x2440(v0), adds s0, then falls into a SHARED tail (offset 44) that calls func_001058e8 again, stores and reloads. The out-of-line arm calls func_001058e8, builds the constant with lui t7,0x3c0f + ori t7,t7,0x423f and branches back into that shared tail. The registered source duplicates the store and the final call in both arms, which is why its layout is inverted. Fix: compute the value per arm, share the store/return tail.",
                 "correction": "An earlier hand-read claimed the store was sb (byte). It is sw (opcode 0x2b) on both sides; there is no byte-typed global.",
                 "next": "fm_worker_b_round4_00242500_v01 (per-arm value, shared tail)."},
    "001ac310": {"bytes": 104, "differing_words": 6,
                 "blocker": "Not yet probed. Target stores at 0x148(s1)/0x14c(s1) where s1 = a0+12; compiled stores the same effective addresses (0x154(s0)/0x158(s0)) through s0. Fix: address them through the same param_1+3 pointer already passed to the callees (puVar1[0x52] = param_1[1]; puVar1[0x53] = param_1[2]). The target also loads param_1[2] before param_1[1] and interleaves ld ra,16(sp) between the loads and the stores.",
                 "next": "fm_worker_b_round4_001ac310_v02 (pointer arithmetic), _v03 (values pre-bound to locals to force the reversed load order)."},
    "001e7230": {"bytes": 104, "differing_words": 6,
                 "blocker": "Not yet probed. Target computes andi t6,a1,0x0003 into t6 at both loop entries and never destroys a1; compiled overwrites a1 (andi a1,a1,0x3, addiu a1,a1,-1, beq a1,t7, bne a1,t7).",
                 "next": "fm_worker_b_round4_001e7230_v01 (separate int local for the masked remainder instead of assigning back to param_2)."},
    "001576e8": {"bytes": 112, "differing_words": 6,
                 "blocker": "Not yet probed. Three identical repetitions of jal func_00155d58 / jal func_00138c10; in every one the target emits mov a1,v0 BEFORE addiu a0,s0,<offset> and the compiled code does the opposite. Nothing else differs.",
                 "next": "fm_worker_b_round4_001576e8_v01 (plain u32 parameter arithmetic), _v02 (typed-pointer cast)."},
}

claim = {
    "worker_id": "worker-b",
    "round": 4,
    "role": "cooperating worker, fourth isolated recovery batch",
    "written": "after round-3 closed at 3/8 exact and the user authorised continuing (m00748 'go ahead')",
    "assignment_source": "analysis/final-mix/worker-coordination/worker-b/round-4/INSTRUCTIONS.md plus the standing brief instruction to claim further disjoint unregistered ranges",
    "assigned_addresses": ["0014b950", "00109e30", "00242500", "001ac310", "001e7230", "001576e8"],
    "self_selected_addresses": ["0030f690", "0030a300", "002f1e00", "00150de0", "002e8290", "00229d40", "001ac700", "0017dec0"],
    "self_selection_rationale": "The round-4 INSTRUCTIONS packet had not been read when batch1 was picked. pick_targets.py screens all 11,383 layout ranges for those absent from compiler-range-verification.json, excludes every address claimed by the primary or by worker-b rounds 1-3, reads the ORIGINAL BYTES out of tools/kh2-reference/SLPM_666.75, rejects non-zero stack frames and lui-prefixed ranges, and ranks branchless leaves first by size. 1,493 candidates survived screening; the eight smallest leaf bodies were taken.",
    "reserved_by_others": {
        "primary": ["00132850", "00154558", "001565c0", "0016b518", "00171690", "00172078", "00172368", "00172440", "00173808", "0017c0a0", "001814b8", "0018db38", "001b0148", "001c0a80", "002006b0", "00242a28", "00281f90", "0029e2f8", "002c1950", "002cff50", "002ddbb8", "002e8038", "002eb068", "002eb778", "002eb9d8", "002ec9d0", "00307f68"],
        "worker_b_round_1_initializers": ["00104210", "001c7ab8", "001d6850", "00241f20"],
        "worker_b_round_2_resolved": ["0017ee68", "00180c88", "0019c0f8", "002bc2e8"],
        "worker_b_round_2_deferred": ["002f3bb8", "00310620"],
        "worker_b_round_3_resolved": ["0028af90", "002d5c20", "002f8870"],
        "worker_b_round_3_unresolved": ["00100338", "001003b0", "00152598", "001c8a90", "0028ac98", "00308da0", "00101d38"],
    },
    "evidence": {
        "assigned_packet": "analysis/final-mix/worker-coordination/worker-b/round-4/targets.json",
        "self_selected_targets": "analysis/final-mix/worker-coordination/worker-b/round-4/batch1.targets.json",
        "assigned_range_hashes": "analysis/final-mix/worker-coordination/worker-b/round-4/assigned.targets.json",
        "self_selected_disassembly": "analysis/final-mix/worker-coordination/worker-b/round-4/r4_orig_disasm.txt",
        "offline_diff_report": "analysis/final-mix/worker-coordination/worker-b/round-4/assigned_diff.txt",
        "original_elf_sha256": "d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87",
        "note": "All eight self-selected original_range_sha256 values were recomputed from tools/kh2-reference/SLPM_666.75 and matched. The six assigned range hashes come from the packet and are reproduced in assigned.targets.json.",
    },
    "shared_resource_use": {
        "wsl_stage": "/root/kh2fm-build",
        "usage": "isolated probe_fm_source.py scratch directories named fm_worker_b_round4_* only",
        "not_done": ["no full build", "no staged input synchronisation", "no docker restart", "no Ghidra project mutation", "no edit to functions.tsv, layout.tsv, main.jsonl, compiler-range-verification.json, src/anon, manifests or HANDOFF.md"],
    },
    "toolchain_blocker": {
        "state": "RESOLVED. Docker returned during round 4 and the queued variants were probed. Note the Windows service com.docker.service still reports STOPPED/1077, which is misleading: from inside WSL /var/run/docker.sock is present, the docker CLI is on PATH, and 'docker run --rm kh2-local/ps2-compiler:3.2-ee-040921-objdiff /bin/true' exits 0.",
        "restart_attempted": False,
        "handling": "I never attempted a start or restart, at any point. The remaining harness blocker was the stale WORKSPACE constant, which I worked around privately rather than by editing the primary's shared tool: worker-b/probe_fm_source_local.py is a copy of probe_fm_source.py differing only in that one constant, diffed against the original and regression-tested against a known-exact source (fm_worker_b_round4_00229d40_solved.cpp -> 'Exact probe matches: 1/1').",
        "reproduction": "wsl -d Ubuntu-24.04 -u root -- bash /mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/round-4/r4_probe_assigned.sh   (bg_run uses cmd.exe, so the MSYS_NO_PATHCONV prefix used in the interactive bash tool is NOT needed and in fact breaks)",
    },
    "001576e8_solved": {
        "bytes": 112, "different_words_in_baseline": 6,
        "mechanism": "All six differing words were the relative order of 'mov a1,v0' and 'addiu a0,s0,<offset>' in three identical repetitions. Fix: write the inner call INLINE in the outer call's argument list with the address argument written FIRST -- the round-2 0017ee68 mechanism generalised. Nesting the other way round (v03, v05) still ordered the address first and missed; the typed-pointer spellings (v01, v02) reintroduced the s0 base the original never forms. '(int)param_1 + 0x1a30' makes the offsets byte offsets off the same base register, which is what yields addiu a0,s0,0x1a30 rather than a scaled-index load.",
        "source": "analysis/final-mix/recovery-experiments/fm_worker_b_round4_001576e8_solved.cpp",
        "proof": "analysis/final-mix/recovery-experiments/fm_worker_b_round4_001576e8_solved.verification.json",
        "status": "exact_match true, boundary_agreement true",
    },
    "round4_result": {
        "exact": solved,
        "unresolved_self_selected": unresolved,
        "assigned_pending_probe": extra,
        "exact_count": 5,
        "unresolved_self_selected_count": 4,
        "assigned_pending_count": 5,
        "probes_run_round4": 138,
        "queued_variants_not_yet_probed": [],
        "queued_variants_probed_after_docker_returned": 27 + 15,
        "decoder_caveat": "r4_decode.py does not decode the R5900 64-bit shift family (fn 0x38-0x3f); it prints (unverified R5900 shift fields). This affects the 0014b950 diagnosis only.",
        "measured_not_guessed": {
            "question": "Which arm does the pinned GCC leave inline for an if/else, and does inverting == 0 / != 0 in the source swap it? This is the whole fix for 00109e30 and 00242500.",
            "method": "No compiler needed. For every function the primary already recovered byte-exactly, the original bytes on the disc are exactly what the source must reproduce, so the original instruction stream was decoded straight out of SLPM_666.75 and the branch target's position relative to the function was measured. Script: round-4/census_polarity.py; output: round-4/polarity_census.txt.",
            "corpus": {"exact_rows_with_source_path": 5201, "exact_rows_with_readable_source": 5481},
            "result": {"conditional_branches_found": 1564, "branch_target_inside_function": 1564, "branch_target_outside_function": 0},
            "conclusion": "1,564 of 1,564, zero exceptions. This compiler never swaps the arms: the then block is always the fall-through and the else block is always emitted out of line at the branch target. Inverting == 0 <-> != 0 therefore deterministically swaps which arm is inline, and no second lever is required.",
            "negative_result_1": "The corpus cannot answer the polarity question directly: 4,658 of 5,201 exact functions have no if/else at all, and the remaining 61 that do never spell an explicit == 0 / != 0 test. The recovered set is overwhelmingly straight-line leaf wrappers, so no directly comparable function exists.",
            "negative_result_2": "The first version of the script read the ELF as big-endian and reported 4,247 of 4,249 branch targets outside their own function. The disc is little-endian on disk while ee-objdump prints big-endian words; fixed, the figure became 1,564/1,564 inside. be32() now carries a comment saying so.",
        },
        "note": "00100338/001003b0/00101d38 from round 3 are also closed as compiler-flag-limited (exception cleanup stubs under -fno-exceptions); see round-3/REPORT.md.",
    },
    "environment_anomaly": {
        "status": "RESOLVED -- it was a relocation, not data loss",
        "migration_2026_10_08": {
            "project_root": {"was": "C:/Users/KoZa/Documents/ChatGPT", "now": "C:/Users/KoZa/Documents/AGENTS/Codex"},
            "tools_root": {"was": "C:/Users/KoZa/Documents/ChatGPT/tools", "now": "C:/Users/KoZa/Documents/AGENTS/Public/tools"},
            "cause": "The project tree and the tools tree were moved out of Documents/ChatGPT. I had read the half-finished state as the tools/ tree having been deleted, and raised it as an incident before the move was announced.",
            "data_loss": "none -- all 11 solved sources re-verified against their proofs (every source_sha256 matches, every row exact_match and boundary_agreement true), plus all round-2/3/4 reports, claims, tools and 26 queued variants.",
        },
        "outstanding_blocker": {
            "who": "primary",
            "what": "probe_fm_source.py still hardcodes WORKSPACE = Path('/mnt/c/Users/KoZa/Documents/ChatGPT'), asserts source.is_relative_to(WORKSPACE) and reads main.jsonl through the same constant.",
            "impact": "Every probe of a source under AGENTS/Codex is rejected by that assert until the constant is changed to /mnt/c/Users/KoZa/Documents/AGENTS/Codex.",
            "fix": "one line in the primary's tool; not edited by worker B",
            "also": "WORKER_BRIEF.md still references the old ChatGPT root (3 references, 0 mentions of AGENTS).",
        },
        "worker_b_migration_done": {
            "list_files": "103 absolute path references rewritten from the old root to the new one across round-2/r2_list_*.txt, round-4/r4_list_all.txt and round-4/r4_list_v2.txt; all 43 round-4 list entries re-verified to resolve to files that exist.",
            "runner": "r4_probe_assigned.sh takes sources from AGENTS/Codex and the harness from AGENTS/Public/tools/kh2-audit/, with a preflight grep that warns if the harness WORKSPACE constant is still stale instead of failing 26 probes one at a time.",
            "tools": "Patched to the two new roots: round2/r3/r4_dump_orig.py (ELF now read from AGENTS/Public/tools/kh2-reference, and the disassembly container now mounts BOTH roots so the inner helper's /work/tools/kh2-reference/SLPM_666.75 path still resolves), census_polarity.py, pick_targets.py x2, make_targets.py, r2_grid.py, round2_mine_stride16.py, r2_probe_batch.sh, r4_scan_frameless.py (no longer cwd-dependent), r2_gen*.py, r4_assigned_v2.py, objdump_orig.sh, make_claim.py.",
        },
    },
}

out = os.path.join(ROOT, "analysis/final-mix/worker-coordination/worker-b/round-4/claim.json")
with open(out, "w") as fh:
    json.dump(claim, fh, indent=1)
print("wrote", out, os.path.getsize(out), "bytes")