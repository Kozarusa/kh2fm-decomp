#!/bin/sh
# Worker B: generate + probe every source variant, print compact verdict table.
# Run inside WSL root (probe_fm_source.py drives docker itself).
set -u
WB=/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b
VAR=$WB/variants
mkdir -p "$VAR"
python3 "$WB/gen_variants.py" "$VAR" > /dev/null
for f in "$VAR"/v*.cpp; do
    base=$(basename "$f" .cpp)
    out=$(python3 /mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py "$f" 2>&1)
    line=$(printf '%s' "$out" | grep -Ei '001c8e00' | head -1)
    printf '%-32s %s\n' "$base" "$line"
    printf '%s\n' "$out" | grep -iE 'Error|Traceback' | head -3
done