# Separate structured startup assembly review candidates

These two artifacts are not C++ semantic recoveries and were not submitted through the normal C++ review queue. They require a separate primary assembly acceptance path. No registry, staged shared source, full build or checkpoint was changed.

## 00100228: 116-byte BSS clear utility

Incoming cursor is v0, incoming exclusive end is v1. The helper byte-clears until 16-byte alignment, quadword-clears until the rounded-down end, then byte-clears the tail. It advances v0 to the original end and uses a0 as scratch. It has no stack frame. Complete original identity/bytes/instruction words are preserved in 00100228-original.json; the pinned EE disassembler was used over the complete range with `-z` so nop words were not elided.

The `.S` source reconstructs textual instructions, local labels, exact delay slots and explicit nops; it embeds no original byte array or `.word` directives. A separate CPP global-assembly harness reproduced the full original range. An independent direct `ee-as` and `ee-ld` reassembly then reproduced all 116 bytes again. The export uses a C++-compatible symbol name only to avoid the existing probe linker's absolute-address alias collision; this does not make it a C++ semantic recovery. The first colliding-symbol harness and its empty proof are preserved as a failed experiment.

## 001002a0: 8-byte startup tail-jump thunk

The original is a direct tail jump to 0030f468 followed by its nop delay slot. It preserves all incoming registers and the original caller link register. Canonical void and integer C++ wrappers compile to 20 bytes, and the attempted `__builtin_unreachable` control is unsupported by the pinned compiler. Those failed files/logs remain preserved. The structured `.S` source reconstructs the jump by symbol and the explicit delay slot, with no embedded bytes. CPP harness and independent direct assembler/linker proofs both match all eight original bytes.

startup-assembly-receipt.json binds both structured sources and direct proofs. The direct proofs include pinned image, source hash, original ELF hash, complete original range hash, complete linked/target bytes, range sizes and ABI descriptions. These are review candidates, not integrated assembly or C++ acceptance. The requested minimum work period remains ongoing.
