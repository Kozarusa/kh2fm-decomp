#include "../common/types.h"
extern "C" s32 func_00139d78(u32);
// why: copied from the recovered call site in fm_primary_orchlc_recovered_00272340.cpp (a0 the list, a1 the halfword loaded with lh)
extern "C" u32 func_0028dac8(u32, s32);
// why: the only recovered declaration is varargs; derived from registers (no argument registers read; it returns the func_00139d78 result in v0)
extern "C" u32 func_00281c30(void);
extern "C" u8 D_0035f299;
extern "C" u32 D_0035f274;
extern "C" u32 D_0035f28c;
extern "C" u32 D_0035f290;
extern "C" s16 D_0035f2a2;
extern "C" s16 D_0035f2aa;
extern "C" s16 D_0035f280;

// why: every exit is a direct callee result (func_00281c30 when zero or when the position already matches, else the func_0028dac8 result)

// Preserve original registry aliases.
u32 func_00281b30(void) asm("_ZN2Tz6CmItem11FadeOutHelpEv");

u32 func_00281b30(void) {
    if (D_0035f299 != 0 && D_0035f274 == 0 && func_00139d78(D_0035f28c) != 0) {
        u32 list = D_0035f28c;
        s16 position = D_0035f2a2;
        if (*(s32*)(list + 388) != position) {
            func_0028dac8(list, position);
            D_0035f280 = -1;
        }
    }
    u32 result = func_00281c30();
    if (result != 0) {
        u32 list = D_0035f290;
        s16 position = D_0035f2aa;
        if (*(s32*)(list + 388) != position) {
            result = func_0028dac8(list, position);
            D_0035f280 = -1;
        }
    }
    return result;
}
