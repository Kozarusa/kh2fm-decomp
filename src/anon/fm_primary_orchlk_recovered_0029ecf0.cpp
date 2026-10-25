#include "../common/types.h"
extern "C" u8* D_0035f5ac;
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_00294000(u32);
// why: a0 is a pointer into the 36-byte entry table, v0 is tested as a flag
extern "C" u32 func_002943b0(u32);
extern "C" u32 func_002954e0(s32);
// why: probe linker script defines only the plain symbol; the C++ form of the accepted definition fails the isolated link (v1)
extern "C" s32 func_0029c9d8(s32);

s32 func_0029ecf0(s32 index) {
    u32 mode = func_00287bc0();
    u32 entries = func_00294000(3) + 16;
    switch (mode) {
    case 14:
        if (index < 0) return 1;
        return func_002954e0(func_0029c9d8(index)) != 0;
    case 15:
    case 18:
    case 21:
        if (index < 0) return 1;
        return func_002943b0(entries + *(s16*)(D_0035f5ac + index * 2 + 8) * 36) != 0;
    case 16:
    case 19:
    case 22:
        return 1;
    default:
        return 0;
    }
}
