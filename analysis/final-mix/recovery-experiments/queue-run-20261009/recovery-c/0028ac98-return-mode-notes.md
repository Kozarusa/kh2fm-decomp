# 0028ac98 return-mode follow-up

No ownership is claimed and no compiler probe ran during integration pause. New unprobed sources v8/v9 retain the closest32byte ternary body but return s64/u64 instead of s32. The original sll/addu instructions sign-extend their word results into the64-bit register. A wider scalar return mode may keep the32-bit index temporary separate from the return register and produce the original t6 shift without fixed-register glue. This is a scheduling/ABI hypothesis, not evidence of original source types. Fresh claim and complete original-range proof are required.
