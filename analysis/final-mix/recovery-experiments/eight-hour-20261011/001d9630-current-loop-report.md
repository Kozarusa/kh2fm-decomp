# Current loop scheduling evidence: 001d9630

The closest current proposal, the historical scoped-counter source, matches
every instruction except the order of the initial s0 and s1 stack saves. Its
count test already uses incoming a1, its pointer move occupies the original
branch delay slot, and its counter copy follows that branch. The older blocker
description about the counter copying before the guard describes another
proposal and must not be applied to this closest source.

This session tested entry saved-register clobbers, a single explicit guarded
counter transport, and narrowly varied unused callee result and promoted first
argument types. None produced a complete exact match. Entry clobbers and an
opaque counter move worsened surrounding instructions. Callee transport
profiles retained the original two-word stack-save ordering residual.

The adjacent `001d9630-current-loop-evidence.json` binds all complete new
proofs and source hashes. No failed proposal is registered. This evidence does
not establish compiler impossibility. The next useful investigation is the
original save-order scheduling dependency or a substantially different loop
representation that preserves the now-correct guarded entry; do not repeat
the tested callee return profiles or broad entry clobbers.
