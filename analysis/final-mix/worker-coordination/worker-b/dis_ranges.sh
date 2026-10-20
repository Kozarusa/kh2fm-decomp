#!/bin/sh
# Worker B helper: disassemble original FM ranges with the pinned toolchain's
# ee-objdump. Reads "<start> <end>" lines from the file given as $1.
# Mount C:\Users\KoZa\Documents\ChatGPT at /work.
while read -r start end; do
    [ -z "$start" ] && continue
    echo "##### $start $end"
    /opt/ps2/gcc/bin/ee-objdump -d \
        --start-address="0x$start" --stop-address="0x$end" \
        /work/tools/kh2-reference/SLPM_666.75 | tail -n +7
done < "$1"