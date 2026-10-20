#!/bin/bash
# grep_filter.sh <file-with-stem:start:end lines> [grep-pattern]
set -u
LIST="$1"
PAT="${2:-^}"
WS=/mnt/c/Users/KoZa/Documents/AGENTS/Codex
while read -r spec || [ -n "$spec" ]; do
  [ -z "$spec" ] && continue
  STEM="${spec%%:*}"
  RANGE="${spec#*:}"
  START="${RANGE%%:*}"
  END="${RANGE#*:}"
  echo "===== $STEM ($START-$END)"
  bash "$WS/analysis/final-mix/worker-coordination/worker-b/dis_probe.sh" "$STEM" "$START" "$END" | grep -E "$PAT"
done < "$LIST"