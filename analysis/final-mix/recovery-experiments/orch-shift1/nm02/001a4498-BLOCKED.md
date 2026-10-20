# 001a4498 blocked
- Range: 001a4498, 120 bytes. Versions tried: 8. Best: v5 with 5 differing words (120/120 bytes); same count as rec73 v6.
- First difference of the best version: !! 001a44c8: ae0000c4  sw	zero,196(s0) | compiled 260e0100  addiu	t6,s0,256 (the addiu t6 and addiu a0 address computations are hoisted above sw 196 / lwc1 200; all stores and their order match).
- Changes tried: v1 C10d memory barrier before 204 store (8); v2 barrier after the 200 read, non-volatile stores (11); v3 vtable and 204 stores volatile (7); v4 asm +r guard on vector base (8); v5 v3 plus volatile vector stores in emitted order 0,3,1,2 (5); v6 asm volatile +r guard on vector (10); v7 memory barrier after read on v5 (9); v8 v5 with non-volatile vtable store (6).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: v5 is store-exact; only the placement of addiu t6 (s0+256) and addiu a0 (s0+272) differs. Try forming those pointers from a value that is not available until after the 200 read, e.g. derive the vector base from the loaded object pointer through a volatile read of a local copy of object, or pass `object + 0x44` via a volatile local assigned after the vtable store.
