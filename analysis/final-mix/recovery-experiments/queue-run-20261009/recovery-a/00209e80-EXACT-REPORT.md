# Exact isolated recovery 00209e80

Worker C identified an archive byte-offset bug: the second indirection must load offset4, not offset1. A signed offset local plus pointer table temporary recovers original scratch registers. Empty return-address clobber at the end pins original save ordering without emitting instructions.

Complete compiled size and bytes equal the live declared original range (76 bytes). Source signatures and meanings remain provisional. Primary independent curation/re-probe and full acceptance remain required.

Source SHA256: 5aab6afb65f637556ecbb0fda1d2995c882f3fb4e3871398119d1e649ddc8781
Proof SHA256: 70b7e990a52dec9d8511543eed766501f632dba56904a0f0873e77f836d7d733
Original range SHA256: ac0697c21c4faaa2f39050f9e8461531448db41ec3d0b41164d84f8d92045821
