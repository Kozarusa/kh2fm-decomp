# Exact isolated recovery 0020e548

The archived pseudocode omitted four explicit final helper arguments. Original conditional delay-slot move a0,t7 carries the loaded field at object+4, not the object pointer. The diagnostic failure branch ends in an exit-backed noreturn helper. Canonical source passes field, byte at offset9, halfword at offset0 and incoming wait value to the final tail call. No register or memory inline assembly is required.

Complete compiled size and bytes equal the live declared original range (68 bytes). Source signatures and meanings remain provisional. Primary independent curation/re-probe and full acceptance remain required.

Source SHA256: 5b165ec5196e2808d4bd1e23d7f94fb9cfcb7648167826696258d99ce9a387d6
Proof SHA256: ccf30b3f06d242f828a96d09b387b6d1f2592862e52597266984dd003027f7c9
Original range SHA256: da738ecba064c638111ecf60dde9b3cf6986d40c044f3f8e78501cb0640ed94c
