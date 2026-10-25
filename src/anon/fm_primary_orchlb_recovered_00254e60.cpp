#include "../common/types.h"
extern "C" u32 D_0035f02c;
extern "C" u8 D_0035f056;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028dac8(...);
// why: the accepted definition fm_primary_queuechi_recovered_00256b80.cpp is void, but this target tests v0 right after the call (beqz v0 at 00254e90), which a void declaration cannot express; the value is the func_00139d78 result that definition leaves in v0
extern "C" u32 func_00256b80(s32);
extern "C" u32 func_00256b68(s32);
extern "C" void func_00138c10(s32, u64);
extern "C" u32 func_00287dc0(void);
extern "C" void func_0023d820(u32);

void func_00254e60() {
    if (func_00139d78(D_0035f02c) != 0) {
        func_0028dac8(D_0035f02c, 48);
    }
    if (func_00256b80(0) != 0) {
        u32 object = func_00256b68(0);
        if (*(s32*)(object + 388) != 117) {
            func_00138c10(object, 117);
            *(s32*)(object + 392) = -1;
        }
        if (D_0035f056 == 0) {
            func_0023d820(func_00287dc0());
        }
    }
}
