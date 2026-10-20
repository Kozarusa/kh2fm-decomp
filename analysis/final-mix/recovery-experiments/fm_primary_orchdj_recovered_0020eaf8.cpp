#include "../common/types.h"
extern "C" s32 D_00359780;
extern "C" s32 D_00359788[];
extern "C" s32 D_00359808;
extern "C" s32 D_00359810[];

s32 func_0020eaf8(s32 size) {
    s32 top = D_00359780;
    if (top < 31) {
        s32 base = D_00359788[top];
        s32 end = base + size;
        if (D_00359810[D_00359808] >= end) {
            top = top + 1;
            D_00359780 = top;
            D_00359788[top] = end;
            return base;
        }
    }
    *(s32*)0 = 0;
    return 0;
}
