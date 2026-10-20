#!/bin/bash
# Probe the given recovery sources in the shared harness and print the word diff.
# Usage: r5_probe.sh fm_worker_b_round5_001e7230_v10 [more stems ...]
set -u
EX=/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments
R5=/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/round-5
for stem in "$@"; do
  echo "########## $stem"
  python3 /mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py \
      "$EX/$stem.cpp" --summary 2>&1 | tail -20
  python3 "$R5/r5_cmp.py" "$stem" 2>&1 | tail -40
done