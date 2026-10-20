# rec14 progress
start 2026-10-12T19:16:20Z
claim 00141928 token 01058c2ef0d74c6281bfb0f88ed3b57d attempts 1
v1: 15 words, first diff 0: C11 -> next: separate count copy
v2: 3 words, first diff 4: C11 -> next: offset + ptr order
v3: 3 words unchanged: C11 -> next: struct array index
v4: 2 words: count offset wrong (pad) -> fix pad
v5: 1 word (addu order): next byte-offset + base
v6: 3 words worse: next u32 index on v5
v7: 1 word no change: next last try u32 sum
v8: 2 words (li/move order): next declare one before i
v8: 8-version budget reached
blocked 00141928 -> register-allocation
claim 00141988 token 5216156d0797435785da1745f5101f13 attempts 1 (claim 2 of 6)
v1: 20 words, first diff 0: C10c -> next volatile object+16 reads
v2: 20 words no change (volatile obj+16 ineffective): next volatile u16 source reads (C9)
v3: 31 words worse: next union alias for source/result (C18)
v4: exact (C18 union alias)
submitted 00141988 v4
claim 00142208 token 6c64dded3a5743079a469706ae4ff446 attempts 1 (claim 3 of 6)
v1: 17 words, first diff 5 (index mask): next u16 param
v2: exact (C3 u16 param)
submitted 00142208 v2
claim 00143520 token ebf8b096302a4aa188dbfd009100eae6 attempts 1 (claim 4 of 6)
v1: 26 words, struct offsets wrong (C1): next fix layout
v2: 26 words, layout ok; copy via t0 differs: next struct Vec assign instead of Quad (C14)
v3: identical to v2 (struct Vec no effect): next inline helper copy (C21-ish)
v3 note: inline helper rejected (rule 1); next volatile global read (C9) on v2
v4: identical (volatile global no effect): next volatile quad read (C14/C9)
v5: identical 26; no improvement for 3 versions
blocked 00143520 -> register-allocation
claim 00143a48 token eba7852b698a4e69a64a12756906f65d attempts 1 (claim 5 of 6)
v1: exact
submitted 00143a48 v1
claim 00143ae0 token 134de36e8d9f44f4b7b28b4e507bbd49 attempts 1 (claim 6 of 6)
v1: 10 words: tail call j vs jal (C13) + lw/move order: next accepted-source style declaration check
v2: exact (C13 barrier)
submitted 00143ae0 v2
