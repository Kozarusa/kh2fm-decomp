#!/bin/sh
# Worker B: dump raw bytes for FM address ranges (objdump -s), reads ranges
# from the file given as $1.
while read -r start end || [ -n "$start" ]; do
    [ -z "$start" ] && continue
    echo "##### $start $end"
    /opt/ps2/gcc/bin/ee-objdump -s \
        --start-address="0x$start" --stop-address="0x$end" \
        /work/tools/kh2-reference/SLPM_666.75
done < "$1"