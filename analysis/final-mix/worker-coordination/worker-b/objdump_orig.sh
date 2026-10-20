#!/bin/bash
# objdump_orig.sh <file-with-"start end" lines> : disassemble ORIGINAL FM ranges via docker.
set -u
LIST="$1"
IMAGE=kh2-local/ps2-compiler:3.2-ee-040921-objdiff
docker run --rm --platform linux/amd64 -v /mnt/c/Users/KoZa/Documents/AGENTS/Codex:/work -v /mnt/c/Users/KoZa/Documents/AGENTS/Public/tools:/work/tools -w /work "$IMAGE" bash /work/analysis/final-mix/worker-coordination/worker-b/objdump_orig_inner.sh "$LIST"