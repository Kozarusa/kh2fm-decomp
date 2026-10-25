#include "../common/types.h"
extern "C" u32 D_0035f110;
extern "C" s32 func_00289310(s32);
extern "C" u32 func_002891e8(u8* select);
extern "C" void func_002890e0(u8* select, u32 a1, s32 a2, u32 a3, s32 a4);
// why: seven word arguments a0..t2 are set before the jal; no recovered non-varargs declaration exists
extern "C" void func_00289038(u8* select, u32 current, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern "C" u32 func_0028d008(u32 index);
// why: one argument a0 is passed and v0 is read; no recovered non-varargs declaration exists
extern "C" u32 func_002891d0(u8* select);
extern "C" u32 func_0028cf28(s32 index, s32 value);
// why: a0 is loaded from D_0035f110 and v0 is tested; no recovered non-varargs declaration exists
extern "C" u32 func_0028d6e8(u32 light);
extern "C" void func_0028d660(u32 light, int item);

void func_0026eae8(u8* select) {
    if (func_00289310((s32)select) == 0) {
        return;
    }
    u32 current = func_002891e8(select);
    func_002890e0(select, 1, 2, 0, -1);
    func_00289038(select, current, 1, 1, 2, 0, -1);
    if (func_0028d008(0) != 0) {
        func_0028cf28(0, func_002891d0(select));
    }
    if (func_0028d6e8(D_0035f110) != 0) {
        func_0028d660(D_0035f110, func_002891d0(select));
    }
}
