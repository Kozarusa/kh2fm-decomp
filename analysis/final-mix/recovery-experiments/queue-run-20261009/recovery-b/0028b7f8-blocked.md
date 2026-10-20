# 0028b7f8: vtable-store/prologue scheduling

The original complete live range is 56 bytes. Archived volatile-vtable source swaps the register31 save and initial vtable store, while all other instructions match. Prior sources already test before/after broad memory barriers and link-register clobbers.

Four new 56-byte probes tested a pointer-valued volatile store, constrained table-address lifetime plus memory clobber, an assembly store with full memory clobber, and an exact memory-output assembly store. None match. The exact memory-output store variant fixes the original register31-save/vtable-store ordering but moves the register16 save ahead of the low table-address addiu. Its only differing offsets are 0x08 and 0x0c. Other variants retain original mismatches or alter store scheduling. Complete proof/source/original-range hashes are preserved in 0028b7f8-blocked-evidence.json.

Next hypothesis: start from tablestoreprecise and constrain native high/low table-address lifetime so the low addiu precedes the register16 save without reordering the register31 save and store. Retain exact memory outputs rather than another full memory clobber. No compiler impossibility is established.
