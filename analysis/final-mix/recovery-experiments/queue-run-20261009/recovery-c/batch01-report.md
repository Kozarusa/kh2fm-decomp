# Recovery C batch 1

Both complete live layout ranges are submitted for primary review: 0014dc08 (60 bytes) and 0014dc48 (96 bytes). Neither shared registry nor compiler stage was changed by this worker. Independent curation, reprobe and full acceptance remain primary responsibilities.

For 0014dc08, original-range comparisons located only the saved-register epilogue mismatch in the prior grouped assembly proposal. Canonical typed stores with empty compiler memory barriers between consecutive stores preserve the entire original store order and allow the original return-address restoration scheduling. Variants 8, 9, 10 and 11 all match. Variant 10 retains normal typed stores and memory barriers.

For 0014dc48, the same method preserves original seven-argument width transport and the original saved-register restoration order. Variants 1, 2, 3 and 8 match. Variant 1 uses only typed stores and empty memory barriers. All failed variants and compiler logs remain alongside the exact proofs.

The batch01-evidence.json binds submitted source and proof files. Each proof contains all original and compiled range bytes, complete size, boundary agreement and source SHA256. Live layout was inspected before experiments; boundaries are 0014dc08–0014dc44 and 0014dc48–0014dca8. The existing probe asserts the full original executable SHA256 before comparing every byte.
