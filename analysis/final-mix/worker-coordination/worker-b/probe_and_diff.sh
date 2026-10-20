#!/usr/bin/env bash
# Worker B probe wrapper: compile/probe one isolated source in the shared Linux
# stage, then print a per-address side-by-side instruction diff of compiled
# output against the original bytes.
#
#   ./probe_and_diff.sh fm_worker_b_initializers_v2 [RangeOverride.json]
#
# Writes <source>.probe.log next to the source and prints the summary.
set -euo pipefail
WS=/mnt/c/Users/KoZa/Documents/AGENTS/Codex
NAME=$1
OVERRIDE=${2:-}
SRC="$WS/analysis/final-mix/recovery-experiments/$NAME.cpp"
ARGS=("$SRC")
[ -n "$OVERRIDE" ] && ARGS+=("$WS/$OVERRIDE")
python3 "$WS/tools/kh2-audit/probe_fm_source.py" "${ARGS[@]}"
python3 "$WS/analysis/final-mix/worker-coordination/worker-b/show_diff.py" "$SRC"