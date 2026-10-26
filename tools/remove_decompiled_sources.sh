#!/bin/sh
# Remove all decompiled C/C++/asm source text from the working tree, keeping tooling, the layout
# tables and pool-placements.json (which store addresses/sizes/hashes only, no code).
# Usage: sh tools/remove_decompiled_sources.sh   (then review `git status` and commit)
# History still contains the files; see tools/REMOVING_SOURCES.md for purging it.
set -e
cd "$(dirname "$0")/.."
git rm -r -q --ignore-unmatch src nonmatchings
rm -rf src nonmatchings out
echo "Decompiled sources removed from the working tree. Review with: git status"
