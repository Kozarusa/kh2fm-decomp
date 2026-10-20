#!/bin/bash
# cmd.exe-safe launcher: bash r5_probe_win.sh <stem> [more stems ...]
set -u
cd /mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/round-5 || exit 1
bash r5_probe.sh "$@"