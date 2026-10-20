#!/bin/bash
# dis_probe.sh <stem> <start> <end> : disassemble a compiled probe range.
# The probe harness renames symbols to func_<addr>, so the disassembly is
# readable with plain objdump.
set -u
STEM="$1"
START="$2"
END="$3"
WS=/mnt/c/Users/KoZa/Documents/AGENTS/Codex
ELF="/root/kh2fm-build/recovery-experiments/$STEM/probe.elf"
docker run --rm --platform linux/amd64 \
  -v /root/kh2fm-build:/root/kh2fm-build \
  -v /mnt/c/Users/KoZa/Documents/AGENTS/Codex:/work -v /mnt/c/Users/KoZa/Documents/AGENTS/Public/tools:/work/tools -w /work \
  kh2-local/ps2-compiler:3.2-ee-040921-objdiff bash -c \
  "/opt/ps2/gcc/bin/ee-objdump -d --start-address=0x$START --stop-address=0x$END $ELF"