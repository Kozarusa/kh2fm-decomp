#!/bin/bash
# r2_probe_batch.sh <list-file> [<list-file> ...]
#
# Round-2 helper: probe every source listed (one workspace-relative .cpp path per
# line, LF only) by running tools/kh2-audit/probe_fm_source.py from the shared
# Linux stage, then print the exact-match count per probed source. The probe
# harness itself owns the pinned-container invocation; this wrapper only
# sequences it and never mutates shared project outputs.
set -u
for LIST in "$@"; do
  while read -r SRC || [ -n "$SRC" ]; do
    case "$SRC" in ""|\#*) continue ;; esac
    OUT=$(python3 /mnt/c/Users/KoZa/Documents/AGENTS/Public/tools/kh2-audit/probe_fm_source.py "$SRC" --summary 2>&1)
    RC=$?
    printf '%s rc=%s %s\n' "$SRC" "$RC" "$(printf '%s\n' "$OUT" | grep -E 'Exact probe matches' | tail -1)"
    if [ "$RC" != 0 ]; then
      printf '%s\n' "$OUT" | tail -5
    fi
  done < "$LIST"
done
