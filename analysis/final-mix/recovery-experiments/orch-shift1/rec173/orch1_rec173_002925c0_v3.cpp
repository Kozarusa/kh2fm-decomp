#include "../common/types.h"
extern "C" u32 func_00102818(u64,u64,u64,u64,s32);
extern "C" u32 func_00103eb0(void);
extern "C" u8 D_00292608[];
extern "C" u8 D_00292620[];
u32 func_002925c0(void) {
    u32 object = func_00103eb0();
    u32 result = func_00102818(*(s32 *)(object + 4), 0, 0x222e0, (s32)D_00292608, 4096);
    *(u32 *)(result + 48) = (u32)D_00292620;
    return result;
}


