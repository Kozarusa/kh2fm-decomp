#!/bin/bash
# Probe a whole directory of variant sources and print the verdicts.
set -u
DIR="$1"
WS=/mnt/c/Users/KoZa/Documents/AGENTS/Codex
for f in "$DIR"/*.cpp; do
  echo "--- $(basename "$f")"
  python3 "$WS/tools/kh2-audit/probe_fm_source.py" "$f" --summary
done