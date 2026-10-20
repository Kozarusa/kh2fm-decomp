#include "../common/types.h"
extern "C" u32 func_00102818(u64,u64,u64,u64,s32);
extern "C" u32 func_00103eb0(void);
extern "C" u8 D_00292608[];
extern "C" u8 D_00292620[];
u32 func_002925c0(void) {
    u32 object = func_00103eb0();
    register u64 size asm("$6") = 0x222e0; // why: original materializes size in a2 before callback address
    asm("" : "+r"(size)); // why: preserves original size materialization before callback setup
    u32 result = func_00102818(*(s32 *)(object + 4), 0, size, (s32)D_00292608, 4096);
    *(u32 *)(result + 48) = (u32)D_00292620;
    return result;
}





