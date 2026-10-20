# rec87 progress
start 2026-10-13T03:34:39Z
claim 1 of 6: 001b5a10 token 4ee3183590be4956be2eb9d440f89021 attempts 1
v1: 10 words, first diff 6: C7 -> next: negate/swap if-else
submitted 001b5a10 v2
claim 2 of 6: 001b5ef0 token ad5fe4879a6f46bfa721f8539a7b8c80 attempts 1
2 claim v1: 9 words first diff 12: C10 -> next: reorder global store after node stores
submitted 001b5ef0 v2
claim 3 of 6: 001b6c60 token 6093dbc96f6d4c15b907470ba39e056f attempts 1
submitted 001b6c60 v1
claim 4 of 6: 001b6d88 token 90a8947d80624ac9a9083957b5b6a19c attempts 1
v1: 14 words first diff 1: C3 -> next: u32 value masked with 0xff
v2: 14 words same: C3b no change (mask dropped) -> next: volatile u8 read
v3: 2 words, first diff 4: C9 -> next: u32 value + mask, volatile
v4: 2 words; best v3 2; streak 1
v5: 8 words; best v3 2; streak 2
v6: 3 words; best v3 2; streak 3 -> stop
blocked 001b6d88 -> store-order
claim 5 of 6: 001b8258 token f7cc4fa817e94afd9e14f91657eda632 attempts 1
v1: 11 words first diff 0: C10 -> next: pointer-typed globals
v2: 11 words same; best v1 11; streak 1
v3: 12 words (volatile, order right, regs differ); best v1 11; streak 2
v4: 11 words; best v1 11; streak 3 -> stop
blocked 001b8258 -> register-allocation
claim 6 of 6: 001b86e0 token 34078383b36e4909b238884ca8d67091 attempts 1
v1: 5 words first diff 5: C11/C10 -> next: compute slot pointer before increment
v2: 12 words; best v1 5; streak 1
v3: 12 words; best v1 5; streak 2
v4: 11 words; best v1 5; streak 3 -> stop
blocked 001b86e0 -> register-allocation
