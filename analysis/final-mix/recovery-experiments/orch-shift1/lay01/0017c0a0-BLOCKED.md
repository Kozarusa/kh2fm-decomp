# 0017c0a0 blocked
- Range: 0017c0a0, 104 bytes. Versions tried: 4. Best: v1 with 2 differing words (104/104 bytes).
- First difference of the best version: !! 0017c0ac: 03a0202d  move	a0,sp  | 0017c0ac: 27a60020  addiu	a2,sp,32
- Changes tried: v1 copy of recovery_c_0017c0a0_17ec437b_v2 (asm lq/sq copy, a0 binding) (2); v2 blocker hypothesis: named aggregate-return local passed by value (15, RVO removes the copy, saves s1); v3 explicit out pointer + by-value pass of addressable local (23, no copy made, frame 48); v4 aggregate return assigned into named local `copy = func_0017c030(object, &extra, b)` then `func_0017c4c8(object, &copy)` with no asm copy (7, frame 64, natural lq/sq copy appears, but slots are copy=sp+0, extra=sp+16, return temp=sp+32 and a2 still set before a0).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: v4 (no emitted lq/sq asm) is the most natural shape: hidden-return temp + compiler struct copy; it only needs the stack slots rotated to temp=sp+0, copy=sp+16, extra=sp+32 (e.g. declare extra first / in an outer scope, or the copy in an inner block) which should also make the struct-value a0 setup come first.
