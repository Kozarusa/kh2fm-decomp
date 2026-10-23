#include "../common/types.h"
extern "C" s32 D_003417a8;
extern "C" s32 D_00341788[];

// Preserve original registry aliases.
void func_001128d0(s32 value, u8 flag) asm("_Z16u_tail4_001128d0jjjj");

void func_001128d0(s32 value, u8 flag) {
    s32 index;
    s32 next;
    s32 from;
    for (index = 0; index < D_003417a8; index++) {
        if (D_00341788[index] == value) {
            break;
        }
    }
    if (index < D_003417a8) {
        if (!flag) {
            for (next = index + 1; next < D_003417a8; next++) {
                D_00341788[next - 1] = D_00341788[next];
            }
            D_003417a8--;
            return;
        }
        for (from = index + 1; from < D_003417a8; from++) {
            D_00341788[from - index - 1] = D_00341788[from];
        }
        D_003417a8 = D_003417a8 - index - 1;
    }
}
