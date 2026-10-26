# Removing the decompiled sources

All decompiled text lives in exactly two top-level directories:

* `src/`          (matched functions, one or more per file, plus a few hand-written `.s` files)
* `nonmatchings/` (unmatched drafts)

Everything else in the repository is tooling or metadata: `Makefile`, `kh2.ld`, `tools/`, `functions.tsv`,
`layout.tsv`, `pool-placements.json` (addresses, sizes and hashes only) and docs. The game executable
`SLPM_666.75` is git-ignored and never committed.

## Remove from the current tree

    sh tools/remove_decompiled_sources.sh
    git commit -am "Remove decompiled sources"

## Purge from history as well (rewrites history; force push required)

    pip install git-filter-repo
    git filter-repo --path src --path nonmatchings --invert-paths
    git push --force <remote> HEAD:<branch>

Do the purge on a fresh clone and keep a backup branch first. Anyone who already cloned or forked the
repository keeps their copy, so a purge only limits future access.
