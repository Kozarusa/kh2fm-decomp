#!/bin/sh
# Worker B: probe every generated variant, print a compact verdict per function.
# Usage: run_variants2.sh <generator.py> <variants-subdir> [glob-prefix]
set -u
WB=/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b
PROBE=/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py
VAR=$WB/$2
PFX=${3:-w}
mkdir -p "$VAR"
python3 "$WB/$1" "$VAR" > /dev/null
for f in "$VAR"/$PFX*.cpp; do
    base=$(basename "$f" .cpp)
    out=$(python3 "$PROBE" "$f" 2>&1)
    printf '=== %s  %s\n' "$base" "$(printf '%s' "$out" | grep -Eo 'Exact probe matches: [0-9]+/[0-9]+' | head -1)"
    printf '%s\n' "$out" | grep -oE '^func_[0-9a-f]{8} (MATCH|[0-9]+/[0-9]+ bytes)' | head -5
    printf '%s\n' "$out" | grep -iE 'Traceback|Error:' | head -3
done