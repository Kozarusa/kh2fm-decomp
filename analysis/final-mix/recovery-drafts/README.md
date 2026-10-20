# Deferred native recovery

Eight initializer definitions remain unmatched: 00104210, 00161410, 001995f8,
001ba060, 001c7ab8, 001c8e00, 001d6850, 00241f20. Complete experimental source
and its 6/14 proof are archived here. Six exact definitions remain active.
Original registry aliases were retained.

Matrix 0011d500 remains unmatched. Archived source is the closest 220-byte
variant: beq/nop guard instead of original beql/addu delay slot. Archived JSON
describes a later 228-byte experiment, not this source. Neither unmatched
draft contributes to the passing compiler checkpoint.

October 7 continuation: matrix `0011d500` is now recovered in
`tools/kh2-reference/src/anon/fm_primary_matrix_recovered.cpp`, relative to the
workspace. Both `fm_primary_matrix_v1.cpp` and its independently re-probed
curated source match the complete 220-byte original range. Full native build,
provenance, objdiff and the matrix bundle passed. The archived mismatched draft
and its historical proof remain unchanged; they are not the accepted source.
