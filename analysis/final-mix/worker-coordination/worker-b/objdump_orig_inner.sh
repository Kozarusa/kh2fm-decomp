#!/bin/bash
set -u
LIST="$1"
SRC=/work/tools/kh2-reference/SLPM_666.75
while read -r start end || [ -n "$start" ]; do
  [ -z "$start" ] && continue
  echo "##### $start $end"
  /opt/ps2/gcc/bin/ee-objdump -d --start-address=0x"$start" --stop-address=0x"$end" "$SRC" \
    | grep -E '^[[:space:]]+[0-9a-f]+:'
done < "$LIST"