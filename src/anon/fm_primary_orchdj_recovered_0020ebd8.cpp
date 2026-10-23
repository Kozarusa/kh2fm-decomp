#include "../common/types.h"
extern "C" s32 D_00359780;
extern "C" s32 D_00359788[];

void func_0020ebd8(s32 size) {
    s32 top = D_00359780;
    if (top > 0) {
        if (D_00359788[top] - D_00359788[top - 1] == size) {
            D_00359780 = top - 1;
            return;
        }
    }
    *(s32*)0 = 0;
}
