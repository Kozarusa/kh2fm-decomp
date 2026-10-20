#!/bin/bash
set -u
for f in /mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/delegated/float-predicates/sa_float_*_[4-7].cpp; do
  python3 /mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py "$f" --summary > "${f%.cpp}.probe.log" 2>&1
done
