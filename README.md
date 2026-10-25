# Kingdom Hearts II Final Mix (JP) Decomp: recovery workspace

Research and recovery workspace for the Japanese PlayStation 2 release of Kingdom Hearts II Final Mix. The goal is C++ that the pinned original-era compiler turns into exactly the instructions of the main executable, `SLPM_666.75`.

It targets the same executable as [GovanifY/kh2](https://github.com/GovanifY/kh2) and builds on its layout and symbol approach. This repository holds the analysis data around that work; the accepted source tree itself is on the `fm-source` branch.

- SLPM\_666.75 sha256: `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`
- Compiler: `kh2-local/ps2-compiler:3.2-ee-040921-objdiff`, flags `-O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections`

## Status

![Progress map](docs/progress.svg)

*Declared code of `SLPM_666.75` by 64 KiB address block. Each small cell is one function range sized by bytes; green is accepted C++, grey is still original-byte fallback.*

<!-- progress:start -->
| Measure | Value |
| --- | ---: |
| Functions matching the original instruction for instruction | 8,067 |
| Declared code ranges | 11,383 |
| Accepted share of declared code bytes | 30.6% (609,468 of 1,989,428) |
| Original-byte fallback ranges remaining | 3,316 (includes 4 zero-padded ranges) |
<!-- progress:end -->

All 2,503 game scripts (733 AI, 727 area, 1,043 event) rebuild byte-exact.

Whole-ELF equality holds, but the build starts from the original ELF and swaps in the registered C++ ranges, so this is not yet a source-only rebuild. Data and tables, IOP modules, overlays and vector-unit programs are not covered, and the byte share above is not a whole-game completion figure. Types, names, boundaries and runtime behavior are provisional.

## How it is run

Recovery is a queue of fallback ranges. A worker claims one address, writes C++ in an isolated directory, and proves it with the pinned compiler. Nothing counts until the full chain passes:

1. The compiled range equals the original range byte for byte.
2. The definition is curated and independently re-probed.
3. It is registered and built in full, ending in `MATCHED!`, with provenance and objdiff checks.
4. A checkpoint is saved and its gate passes.

The accepted C++ lives on the `fm-source` branch (a fork of [GovanifY/kh2](https://github.com/GovanifY/kh2) with the Final Mix ranges registered).

## Repository layout

| Path | Contents |
| --- | --- |
| [GLOSSARY.md](GLOSSARY.md) | Project terms |
| `analysis/final-mix/` | Core analysis data for the Japanese Final Mix executable: function list, exports, overlay layout, ISO file list, build environment, summaries |
| `docs/` | Generated progress figure |

The accepted source tree, build tooling and verifier live on the `fm-source` branch. Working notes, orchestration files, experiment logs and checkpoints are not tracked.

## Setup

You supply the game. Put `SLPM_666.75`, extracted from your own copy of the disc, in the shared reference checkout. Building needs Docker, WSL (`Ubuntu-24.04`) and Python 3. Builds run inside WSL at `/root/kh2fm-build`, never under `/mnt/c`. The accepted-snapshot, binary and Ghidra trees are not tracked here (see `.gitignore`).

## Disclaimer

This project is for research, preservation and interoperability. It does not include the game, its disc image or its executable, and you must own a legal copy to use it. Kingdom Hearts is a trademark of its respective owners; this project is not affiliated with or endorsed by them.

## License

No license has been chosen for this repository yet. The shared `kh2-reference` tree it builds on is MIT-licensed by its original author.
