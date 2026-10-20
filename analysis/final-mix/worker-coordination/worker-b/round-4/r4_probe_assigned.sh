#!/bin/bash
# Probe the six ASSIGNED round-4 targets once Docker is available.
#
# Runs every queued variant of the six assigned targets. The default run list is
# round-4/r4_list_all.txt (all 27 variants across both passes);
# round-4/r4_list_v2.txt holds the 16 refined second-pass variants alone.
# Pass one or more list files as arguments to restrict it, e.g.
#
#   bash r4_probe_assigned.sh /mnt/c/.../r4_list_v2.txt
set -u
WS=/mnt/c/Users/KoZa/Documents/AGENTS/Codex
HERE=$WS/analysis/final-mix/worker-coordination/worker-b/round-4

# PATH MIGRATION 2026-10-08. The project moved out of
# /mnt/c/Users/KoZa/Documents/ChatGPT into AGENTS/Codex, and tools/ into AGENTS/Public.
# All worker-b sources, reports and queued variants live under $WS now.
#
# BLOCKER (2026-10-08, WORKED AROUND): probe_fm_source.py still hardcodes
#   WORKSPACE = Path('/mnt/c/Users/KoZa/Documents/ChatGPT')
# and asserts `source.is_relative_to(WORKSPACE)`, so it rejects every source under $WS.
# It also reads main.jsonl via the same constant. One-line fix in the primary's tool.
#
# I did not edit the shared tool. Instead I made a private copy with only that constant
# changed (worker-b/probe_fm_source_local.py), diffed it against the original to confirm the
# single-line delta, and regression-tested it: probing a known-exact source
# (fm_worker_b_round4_00229d40_solved.cpp) still reports "Exact probe matches: 1/1".
# When the primary's fix lands, point PROBE back at the shared tool.
PROBE=/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/probe_fm_source_local.py
[ -f "$PROBE" ] || { echo "FATAL: harness not found at $PROBE"; exit 1; }

# Preflight: warn if the local copy is missing or diverges from the shared tool by more
# than the WORKSPACE constant.
SHARED=/mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py
if [ -f "$SHARED" ]; then
  n=$(diff <(sed "s#$WS#WSROOT#g" "$PROBE") <(sed "s#/mnt/c/Users/KoZa/Documents/ChatGPT#WSROOT#g" "$SHARED") | grep -c '^[<>]')
  [ "$n" -gt 2 ] && echo "WARNING: local harness differs from the shared tool in $n lines (expected 2)."
else
  echo "NOTE: shared harness not found at $SHARED; using the local copy only."
fi

LISTS=("$@")
if [ ${#LISTS[@]} -eq 0 ]; then
  LISTS=("$HERE/r4_list_all.txt")
  [ -f "$HERE/r4_list_assigned.txt" ] && LISTS=("$HERE/r4_list_v2.txt")
fi

for L in "${LISTS[@]}"; do
  echo "===== $L"
  while read -r f; do
    [ -f "$f" ] || { echo "missing $f"; continue; }
    name=$(basename "$f" .cpp)
    out=$(python3 "$PROBE" "$f" --summary 2>&1 | tail -1)
    printf '%-46s %s\n' "$name" "$out"
  done < "$L"
done