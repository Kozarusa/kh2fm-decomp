# rec83 progress
start 2026-10-13T03:14:36Z
claim 1 of 6: 001af778 token 3f6e27af9f23481abbb58b7561449e64 attempts 1
v1: 0 words exact
submitted 001af778 v1
claim 2 of 6: 001afe30 token 348d20a56924460893b8e0db676cc398 attempts 1
v1: 12 words, first diff 2: mthi quirk/addr split -> next: struct array loop (C21-ish)
v2: 0 words exact
submitted 001afe30 v2
claim 3 of 6: 001b0210 token 1822be5cc45a4279b4bb6dd5595b7f8c attempts 1
v1: 2 words, first diff 11: C10 -> next: memory barrier between stores
v2: 0 words exact
submitted 001b0210 v2
claim 4 of 6: 001b0728 token 5ed0fb1bf38b4180b654f8b7c5af9401 attempts 1
v1: 22 words, first diff 1: float/scheduling mix -> next: global as pointer read (address split)
v2: 22 words same as v1 (array global had no effect) -> next: C7c early return
v1: 22; best v1 22; streak 0 / v2: 22; best v1 22; streak 1
v3: 22; best v1 22; streak 2 (identical output)
v4: 13; best v4 13; streak 0 (asm memory barrier before call fixed hoist; remaining: lq/sq regs, D address in reg) -> next: pointer to D forced in register
v5: 2; best v5 2; streak 0 (only lq/sq reg+base differ) -> next: force destination pointer in register via asm +r
v6: 5; best v5 2; streak 1 (asm on destination at top shifted move s1) -> next: put the +r inside the copy branch
v7: 2; best v5 2; streak 2 (only lq/sq temp t7 vs t0) -> next: bind copy to \
v8: 0 exact
submitted 001b0728 v8
claim 5 of 6: 001b1360 token b2f992450509493aa7b6ca6c8cfd01d0 attempts 1
v1: 0 exact
submitted 001b1360 v1
claim 6 of 6: 001b1e80 token efa0baf3fb45496280b82cd10f62ff88 attempts 1
v1: 2 words, first diff 19: C10 -> next: local temp plus ordered stores
v2: 0 exact
submitted 001b1e80 v2
