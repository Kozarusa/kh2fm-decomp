#!/bin/sh
# Worker B: side-by-side disassembly of the original FM ranges and each compiled
# probe ELF for the given variant stems. Ranges come from a file "<stem> <start>
# <end>" per line, passed as $1.
set -u
IMG=kh2-local/ps2-compiler:3.2-ee-040921-objdiff
while read -r stem start end || [ -n "$stem" ]; do
    [ -z "$stem" ] && continue
    echo "########## $stem  $start..$end"
    echo "--- original"
    /opt/ps2/gcc/bin/ee-objdump -d --start-address="0x$start" --stop-address="0x$end" \
        /work/tools/kh2-reference/SLPM_666.75 2>/dev/null | tail -n +7
    echo "--- compiled"
    /opt/ps2/gcc/bin/ee-objdump -d --start-address="0x$start" --stop-address="0x$end" \
        "/work/recovery-experiments/$stem/probe.elf" 2>/dev/null | tail -n +7
done < "$1"