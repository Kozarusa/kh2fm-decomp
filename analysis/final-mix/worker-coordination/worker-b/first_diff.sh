#!/bin/bash
# first_diff.sh <stem> <start> <end> : print aligned original vs compiled
# instruction listings and mark the first differing instruction.
set -u
STEM="$1"
START="$2"
END="$3"
HERE=/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b
mkdir -p "$HERE/_fd"
printf '%s %s\n' "$START" "$END" > "$HERE/_fd/$STEM.ranges"
docker run --rm --platform linux/amd64 \
  -v /mnt/c/Users/KoZa/Documents/AGENTS/Codex:/work -v /mnt/c/Users/KoZa/Documents/AGENTS/Public/tools:/work/tools -w /work \
  kh2-local/ps2-compiler:3.2-ee-040921-objdiff \
  bash /work/analysis/final-mix/worker-coordination/worker-b/objdump_orig_inner.sh "/work/analysis/final-mix/worker-coordination/worker-b/_fd/$STEM.ranges" \
  | grep -E '^[[:space:]]+[0-9a-f]+:' | sed 's/0x[0-9a-f]\{8\}//' > "$HERE/_fd/$STEM.orig"
bash "$HERE/dis_probe.sh" "$STEM" "$START" "$END" \
  | grep -E '^[[:space:]]+[0-9a-f]+:' | sed 's/0x[0-9a-f]\{8\}//; s/<func_[0-9a-f]*+0x[0-9a-f]*>//' > "$HERE/_fd/$STEM.comp"
awk 'NR==FNR{a[FNR]=$0; n=FNR; next}
     {c[FNR]=$0; m=FNR}
     END{
       n=(n>m?n:m);
       bad=0;
       for(i=1;i<=n;i++){
         x=(i<=n?a[i]:""); y=(i<=m?c[i]:"");
         # compare mnemonic operand text after the hex word
         ax=x; cy=y; sub(/^[^:]*:[^ ]* *[a-z0-9.]+ +/,"",ax); sub(/^[^:]*:[^ ]* *[a-z0-9.]+ +/,"",cy);
         if(ax!=cy){ if(!bad){printf "FIRST DIFF at %d\n", i; bad=1}
                    printf "%3d  T: %-40s\n    C: %-40s\n", i, ax, cy }
       }
       if(!bad) printf "IDENTICAL (%d instructions)\n", n
     }' "$HERE/_fd/$STEM.orig" "$HERE/_fd/$STEM.comp"