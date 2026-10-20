set -e
T=/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/round-15
O=$T/r15_orig_disasm.txt
: > $O
while read a b; do
  echo "##### $a $b" >> $O
  docker run --rm --platform linux/amd64 -v /root/kh2fm-build:/work -w /work \
    kh2-local/ps2-compiler:3.2-ee-040921-objdiff \
    /opt/ps2/gcc/bin/ee-objdump -d --start-address=0x$a --stop-address=0x$b \
    /work/SLPM_666.75 >> $O 2>&1
done < $T/r15_ranges.txt
grep -c '^#####' $O
