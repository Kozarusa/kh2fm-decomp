#!/bin/bash
# fd_list.sh : read "stem:start:end" lines from stdin file arg, diff each.
set -u
LIST="$1"
MAX="${2:-10}"
H=/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b
while read -r spec || [ -n "$spec" ]; do
  [ -z "$spec" ] && continue
  STEM="${spec%%:*}"; R="${spec#*:}"; S="${R%%:*}"; E="${R#*:}"
  echo "##### $STEM"
  bash "$H/first_diff.sh" "$STEM" "$S" "$E" 2>&1 | grep -v 'no symbols' | head -"$MAX"
done < "$LIST"