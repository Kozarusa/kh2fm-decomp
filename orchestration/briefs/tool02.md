# tool02: show zero words in kh2w.py packets and diffs (tooling only)

| Field | Value |
| --- | --- |
| WP | tool02 |
| Model | sonnet |
| Worker id | orch1-tool02 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\tool02` |
| Files you may change | `C:\Users\KoZa\Documents\AGENTS\Codex\orchestration\tools\kh2w.py` (one function, below) |
| Files you may create | files inside your WP directory only (`PROGRESS.md`, `tool02-REPORT.md`, test packets) |
| Depends on | nothing; runs while no other worker uses kh2w.py |
| Review | the orchestrator re-runs the two test commands (RECIPES O2 step 7) |

You do not do recovery work, do not claim or touch queue targets, do not probe. You may run `kh2w.py packet` and `kh2w.py diff` (they only read the stage through Docker, read-only).

## Problem

`kh2w.py`'s `objdump()` calls `ee-objdump -d` without `-z`. objdump then silently skips runs of all-zero words. A zero word is the MIPS `nop` encoding, so packets and diffs hide real `nop` instructions inside function ranges (found on `00146730`, words `0014675c`-`0014676c`, and `00165968`, words `00165980`-`00165990`). The byte comparison in the probe is not affected; only the human-readable listing is.

## Steps

1. R0 (your own `PROGRESS.md` in the WP directory).
2. Make a backup copy of `kh2w.py` as `<WP directory>\kh2w.py.orig` before changing anything.
3. In `objdump()` add the flag `-z` (disassemble zero words) to the ee-objdump command, right after `-d`. Change nothing else in the file.
4. Test 1: `python -I Codex\orchestration\tools\kh2w.py packet 00146730 <WP directory>`. The listing must now contain lines for `0014675c`, `00146760`, `00146764`, `00146768`, `0014676c`, each `00000000  nop`.
5. Test 2: `python -I Codex\orchestration\tools\kh2w.py diff Codex\analysis\final-mix\recovery-experiments\fm_primary_orchaj_recovered_00146730.verification.json <WP directory>\00146730.diff.txt`. It must still print `Differing words: 0`, and the diff file must show the five nop lines on both sides.
6. Test 3 (no regression): run the same diff on `Codex\analysis\final-mix\recovery-experiments\fm_primary_orchau_recovered_00161030.verification.json`; it must still print `Differing words: 0`.
7. Write `tool02-REPORT.md` with the exact one-line change (before and after), the three commands and their key output lines, and confirm no other file changed. Reply with its contents.

## Done when

The three tests pass, `kh2w.py` differs from `kh2w.py.orig` only by the added `-z`, and nothing outside `kh2w.py` and your WP directory changed.
