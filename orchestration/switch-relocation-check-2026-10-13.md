# Read-only switch relocation check

The existing attempts for 001e35f0 (rec121 v1) and 001e3590 (rec122 v1) each differ in exactly two of 24 instruction words, at offsets 0x10 and 0x14. The differing words materialize the compiler-generated switch table base. Neither is presently an exact recovery.

Evidence inspected on 2026-10-13:

- `kh2w.py diff` independently recounted both existing verification files: equal 96-byte sizes, two differing words, all other instructions identical.
- `readelf -S -r` on the existing Linux-stage `orch1_rec121_001e35f0_v1/probe.o` shows a 0x34-byte `.rodata` table, R_MIPS_HI16 and R_MIPS_LO16 text relocations targeting `.rodata`, and 13 R_MIPS_32 table-entry relocations targeting the function's text section.
- `readelf -S` on its existing `probe.elf` shows `.rodata` linked at address 0. Thus the zero operands are resolved relocations to an incorrectly placed table, not missing relocation processing.
- `Public/tools/kh2-audit/probe_fm_source.py` generates fixed addresses for function text and explicit D_/func_ references, but supplies no placement for compiler-generated `.rodata`.
- `Public/tools/kh2-reference/kh2.ld` places generic `.cxx_rodata` after the extra `.cxx_text` region beginning at 0x00400000. `tools/build_elf.py` generates fixed-address sections for function text only. The full build therefore does not automatically bind these tables to 0x0036eb28 and 0x0036eaf8.

No source, compiler flags, linker, layout, build helper or accepted artifact was changed. No probe or full build was run for these two targets. Do not send recovery workers back to the same source-shape problem.

Next step is a tooling design for mapping each compiler-generated switch table to its original address, proving both table entries and complete function ranges without patched instruction bytes. Modifying the probe/linker/build helpers requires the user's explicit O8 approval. This remains roadmap phase 5 work, not a currently accepted match.
