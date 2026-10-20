#!/bin/bash
# probe_glob.sh <dir> <glob> : probe every matching source, print verdicts.
set -u
DIR="$1"
GLOB="$2"
WS=/mnt/c/Users/KoZa/Documents/AGENTS/Codex
for f in "$DIR"/$GLOB; do
  [ -e "$f" ] || continue
  echo "--- $(basename "$f")"
  python3 "$WS/tools/kh2-audit/probe_fm_source.py" "$f" --summary
done