# tool01 report
Status: done
Worker: orch1-tool01, model sonnet. Started 2026-10-12T17:05:11Z, ended 2026-10-12T17:06:18Z.

Files created: Codex\orchestration\tools\coverage.py, Codex\orchestration\tools\status_table.py, this report (plus PROGRESS.md in the WP directory). Both scripts are standard library only and read-only (the queue DB is opened with mode=ro).

## Commands
Run from C:\Users\KoZa\Documents\AGENTS:
```
python -I Codex\orchestration\tools\coverage.py      (exit 0)
python -I Codex\orchestration\tools\status_table.py  (exit 0)
```

## coverage.py output
## Table 1: main executable (SLPM_666.75) code coverage

| Row | Ranges | Bytes | % of declared code bytes |
| --- | ---: | ---: | ---: |
| Declared code ranges | 11,383 | 1,989,428 | 100.0% |
| Accepted C++ (exact symbol match) | 6,092 | 328,928 | 16.5% |
| Fallback (rest of layout.tsv, includes zero_padded ranges) | 5,291 | 1,660,500 | 83.5% |
| Queue fallback, priority 1 | 19 | 1,236 | 0.1% |
| Queue fallback, priority 2 | 1,594 | 144,216 | 7.2% |
| Queue fallback, priority 3 | 2,959 | 760,492 | 38.2% |
| Queue fallback, priority 4 | 715 | 754,372 | 37.9% |
| Queue fallback, state ready | 5,243 | 1,654,904 | 83.2% |
| Queue fallback, state reserved | 30 | 4,172 | 0.2% |
| Queue fallback, state submitted | 13 | 1,160 | 0.1% |
| Queue fallback, state leased | 1 | 80 | 0.0% |

Queue rows exclude targets already in state accepted; priority and state rows are fallback ranges still tracked by the queue.

## Table 2: other native inputs

| Module | Size (bytes) | Status |
| --- | ---: | --- |
| SIO2MAN.IRX | 6,641 | not in build proof |
| SIO2D.IRX | 11,289 | not in build proof |
| DBCMAN.IRX | 15,653 | not in build proof |
| PAD2/DS2O.IRX | 10,973 | not in build proof |
| MCMAN.IRX | 96,181 | not in build proof |
| MCSERV.IRX | 7,385 | not in build proof |
| LIBSD.IRX | 30,085 | not in build proof |
| LIBSSL.IRX | 91,949 | not in build proof |
| ROM_SYSMEM.IRX | 6,041 | not in build proof |
| ROM_LOADCORE.IRX | 10,433 | not in build proof |
| ROM_SIFCMD.IRX | 10,529 | not in build proof |
| ROM_SIFMAN.IRX | 6,145 | not in build proof |
| ROM_THREADMAN.IRX | 39,405 | not in build proof |
| ROM_IOMAN.IRX | 12,545 | not in build proof |
| ROM_MODLOAD.IRX | 18,565 | not in build proof |
| ROM_FILEIO.IRX | 19,661 | not in build proof |
| ROM_CDVDMAN.IRX | 85,053 | not in build proof |
| ROM_CDVDFSV.IRX | 33,429 | not in build proof |
| ROM_LOADFILE.IRX | 10,505 | not in build proof |
| ROM_TIMEMANI.IRX | 6,085 | not in build proof |
| ROM_ROMDRV.IRX | 3,881 | not in build proof |
| ROM_EESYNC.IRX | 1,545 | not in build proof |
| ROM_SYSCLIB.IRX | 10,045 | not in build proof |
| ROM_STDIO.IRX | 3,377 | not in build proof |
| ovl_gumibattle.x | 443,896 | not in build proof |
| ovl_title.x | 96,368 | not in build proof |
| ovl_shop.x | 151,632 | not in build proof |
| ovl_movie.x | 84,020 | not in build proof |
| ovl_gumimenu.x | 476,168 | not in build proof |
| VU programs (14) | 22,008 | not in build proof |

Declared code ranges are the denominator; data, tables and undiscovered code are not included.

Checks passed: accepted count == unmodified_compiled_symbol_matches (6092); 6096 verified ranges + 5287 fallback == 11383 layout rows.

## status_table.py output
| Measure | Value |
| --- | ---: |
| Complete, equal-size instruction matches | 6,092 |
| Registered C++ ranges (includes 4 padding cases) | 6,096 |
| Original-byte fallback ranges still remaining | 5,287 |
| Verified staged compiler inputs | 2,597 |
| Cumulative recovery bundles passing | see O3 step 8 |
| Switch batches passing | see O3 step 8 |

Latest checkpoint: final-mix/primary-orchaa-checkpoint-2026-10-08.json

## Input fields that differ from the brief
- Counts are newer than the brief's 2026-10-12 figures: accepted 6,092 (brief: 6,087), fallback 5,287 (brief: 5,292). The checks use the file values, not the literals, and both pass (6,096 verified ranges + 5,287 = 11,383 layout rows).
- compiler-range-verification.json has 6,096 items (brief: 6,091), equal to cpp_range_count. Table 1 "Fallback" is declared minus accepted = 5,291, which is the 5,287 original-byte fallback plus the 4 zero_padded C++ ranges; the row label says so.
- Queue targets in state accepted are skipped in the priority/state rows. The queue has one extra state, leased (1 range, 80 bytes), shown as its own row. Queue not-accepted total is 5,287 (5,243+30+13+1) which equals original_fallback_range_count.
- The latest checkpoint is named primary-orchaa-checkpoint-2026-10-08.json (hard-coded date); it has active_exact_matches 6,092, source_inputs_checked 2,597. Registered ranges, fallback and staged inputs come from native-build-verification.json (cpp_range_count, original_fallback_range_count, source_input_files_verified_against_workspace). status_table.py fails if checkpoint matches and build-proof matches disagree (they agree).
- native-inputs.json also contains SLPM_666.75; Table 2 omits it (it is Table 1). It includes five ovl_*.x overlays with status extracted_boundaries_unverified; Table 2 shows them as "not in build proof".
