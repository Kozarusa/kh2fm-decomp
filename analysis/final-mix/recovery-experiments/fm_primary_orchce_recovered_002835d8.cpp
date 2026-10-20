#include "../common/types.h"

extern "C" u32 D_0035f2b8;
extern "C" s32 func_00139d78(u32);
extern "C" void func_00139510(u32);
extern "C" void func_00283960(u32);

void func_002835d8() {
    // why: original calls func_00139d78 with the word at D_0035f2b8 + 852 and keeps
    //      the result in v0 for the beqz test.
    if (func_00139d78(D_0035f2b8 + 852) != 0) {
        // why: same pointer argument, reloaded in the beqz delay slot.
        func_00139510(D_0035f2b8 + 852);
    }
    // why: tail call, so the callee gets a0 = 1 and the frame teardown sits in j delay slot.
    func_00283960(1);
}
