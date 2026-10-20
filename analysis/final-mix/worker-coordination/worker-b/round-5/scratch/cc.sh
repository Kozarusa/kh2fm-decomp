#!/bin/bash
# Local scratch experiments (round 5, Worker B). Not part of any probe or proof.
# Runs inside the pinned image against files in this directory only.
set -u
FLAGS="-O2 -g0 -x c++ -fno-exceptions -fno-rtti -fpermissive -ffunction-sections"
for f in "$@"; do
  echo "===== $f"
  /opt/ps2/gcc/bin/ee-g++ $FLAGS -c "$f" -o "${f%.cpp}.o" || continue
  /opt/ps2/gcc/bin/ee-objdump -d "${f%.cpp}.o" | grep -E '^[[:space:]]+[0-9a-f]+:'
done
