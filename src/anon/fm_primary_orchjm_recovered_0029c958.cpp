#include "../common/types.h"
extern "C" u32* D_0035f5ac;
extern "C" u32 func_002954e0(s32);
extern "C" u32 func_00276c18(void);

u32 func_0029c958() {
    s32 index = 0;
    u32 mask = 0;
    u32 result;
    do {
        result = func_002954e0(index);
        if (result != 0 || (result = func_00276c18()) != 0) {
            mask |= 1 << (index + 1);
        }
        index++;
    } while (index < 15);
    mask |= 1;
    *D_0035f5ac = mask;
    return result;
}
