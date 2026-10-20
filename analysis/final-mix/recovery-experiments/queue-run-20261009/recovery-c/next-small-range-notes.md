# Fresh small fallback hypotheses during integration pause

No target ownership is claimed. Atomic leases are required before probes.

00152598,28bytes: original words are sll t7,a1,3; bne a2,zero; addu t7,t7,a3 in the delay slot; then two jr/word-load alternatives at offsets0/4. The archived28byte C++ proposal differs only in register allocation. Test a fixed t7 pointer local (not fixed returned result), plus an appropriate full-width condition argument if needed.

00308da0,28bytes: original clears object offset24 then masks bit0 at offset16, but materializes -2 with lui v0,0xffff and ori v0,v0,0xfffe. Prior24byte code compresses that mask to one instruction. Test a narrow explicit constant-construction constraint while retaining typed load/zero-store/mask/store behavior; do not invent padding bytes. Actual flags value is in v1.

002430b0,36bytes: original is a global setter followed by helper call returning a transported value and a tail call. Words establish high global0x36, signed low0xece0 (actual global0035ece0), ra-only16byte frame, first jal00243190, restoredra, daddu a0,v0,zero, tail j00243020. This has no nominated prior proposal and should be tested with correctly declared scalar64 transport first.
