#include "../common/types.h"
extern "C" s32 D_0035de30;
extern "C" s32 D_0035de34;
extern "C" u8* D_0035de38;
extern "C" s32 D_0035de3c;
extern "C" u8 D_0035de27;
extern "C" u8 D_00227e30[];
extern "C" u8 D_002272b8[];
extern "C" u8 D_00228058[];
extern "C" u8 D_002280f8[];
// why: no accepted call site or definition exists; the instructions of 00228240 never write v0 or $f0 on any path, so it is declared void
extern "C" void func_00228240(void);
extern "C" u32 func_002282d8(void);
extern "C" u8* func_00102c80(void);
extern "C" u32 func_00102818(...);
extern "C" u8* func_00102788(...);

// why: every exit leaves the direct v0 of the last callee on that path (00102c80, 00102818 or 00102788), so the target returns that pointer; the parameter type comes from a0 being passed on as a word argument

u8* func_00228150(s32 owner) {
    func_00228240();
    u32 priority = func_002282d8();
    u8* result = func_00102c80();
    D_0035de3c = *(s32*)(result + 4);
    if (D_0035de30 == 0) {
        result = (u8*)func_00102818(D_0035de3c, owner, priority, D_00227e30, 0x2000);
        D_0035de30 = (s32)result;
    }
    if (D_0035de34 == 0) {
        result = (u8*)func_00102818(D_0035de3c, owner, priority, D_002272b8, 0x2000);
        D_0035de34 = (s32)result;
    }
    if (D_0035de38 == 0) {
        result = func_00102788(D_0035de3c, owner, priority, D_00228058);
        D_0035de38 = result;
        // why: the handler store goes through the just-written global so the global store is scheduled first, as in the original
        *(u8**)(D_0035de38 + 0x30) = D_002280f8;
        D_0035de27 = 0;
    }
    return result;
}
