#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" u32 func_00105868(s32);
extern "C" u32 func_00276fd0(void);

// Preserve original registry aliases.
s32 func_001d9980(void) asm("_Z16wtarget_001d9980jjjj");

s32 func_001d9980(void) {
    s32 level = func_00105868((s32)D_0032bb30);
    s32 result;
    switch (level) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 1;
        break;
    case 2:
        result = (func_00276fd0() == 100) ? 3 : 2;
        break;
    case 3:
        result = (func_00276fd0() == 100) ? 5 : 4;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
