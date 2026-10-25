#include "../common/types.h"
// Globals and callee declarations copied from tozawa/cmenu_jiminy.cpp (Jiminy::JmCommonLeave, same tail shape).
extern u32 D_0035f200 asm("D_0035f200");
extern u32 D_0035f214 asm("D_0035f214");
extern "C" u8* D_0035f5f0;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(...);
extern "C" void func_0028abe0(...);
extern "C" u32 func_0028be58(...);
extern "C" void func_0028be18(...);
// why: no accepted caller; v0 is a pointer passed as an argument and used as an object with a vtable at +0.
extern "C" u8* func_00276348(void);
// why: original trace 002766e0 tails into 00276b10 whose accepted definition returns u32 in v0, so the final call's v0 is live (non-void, no float); cmenu_jiminy.cpp's void call-site declaration discards it.
extern "C" u32 func_002766e0(void);
// why: the virtual slot 5 results are discarded (as in cmenu_jiminy.cpp JmCommonLeave's (void (*)(u32)) cast).
typedef void (*Callback)(u8*);

// Preserve original registry aliases.
u32 func_002a67a8(void) asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");

u32 func_002a67a8(void) {
    s32 offset = 0;
    s32 count = 9;
    do {
        if (func_00139d78(D_0035f5f0 + offset) != 0) {
            u8* object = (u8*)(offset + (u32)D_0035f5f0);
            (*(Callback**)object)[5](object);
        }
        count--;
        offset += 436;
    } while (count >= 0);
    if (func_0028acc8(D_0035f200) != 0) {
        func_0028abe0(D_0035f200);
    }
    if (func_00139d78(func_00276348()) != 0) {
        u8* parent = func_00276348();
        (*(Callback**)parent)[5](parent);
    }
    if (func_0028be58(D_0035f214) != 0) {
        func_0028be18(D_0035f214);
    }
    return func_002766e0();
}
