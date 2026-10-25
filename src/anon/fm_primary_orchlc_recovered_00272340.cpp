#include "../common/types.h"
struct PosEntry {
    s16 field[3];
};
extern "C" PosEntry D_00373a30[];
extern "C" u8* D_0035f04c;
extern "C" u32 func_00257770(void);
extern "C" u32 func_00287bc0(void);
// why: the call site sets only a0 (li a0,26); a1 holds the default position for the later call
extern "C" s32 func_002570a0(s32);
extern "C" u8 func_00272b60(s32);
// why: a0 is the list buffer, a1 is the halfword loaded with lh
extern "C" u32 func_0028dac8(u32, s32);
extern "C" u32 func_0028be58(u8*);
// why: extern "C" because the accepted asm-label form fails the isolated link (v1); the probe linker script defines only the plain symbol
extern "C" u32 func_0028bdb8(u8* object);

void func_00272340(void) {
    u32 list = func_00257770();
    u32 mode = func_00287bc0();
    s32 position = 229;
    if (mode - 26 < 8) {
        if (mode - 26 >= 2) {
            position = D_00373a30[func_00272b60(func_002570a0(26))].field[1];
        }
        func_0028dac8(list, position);
        if (func_0028be58(D_0035f04c) != 0) {
            func_0028bdb8(D_0035f04c);
        }
    }
}
