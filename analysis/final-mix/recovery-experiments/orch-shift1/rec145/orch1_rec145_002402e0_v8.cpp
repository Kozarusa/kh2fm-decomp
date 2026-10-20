#include "../common/types.h"
extern "C" u32 func_00105c30(void);
extern "C" s32 D_0035ecac;
extern "C" s32 D_0035ecb0;
extern "C" s32 D_0035ecb4;
extern "C" volatile s32 D_01dae6a0;
s32 func_002402e0() {
    s32 result = func_00105c30();
    register volatile s32* pointer asm("$13") = &D_01dae6a0; // why: original destination uses t5
    register s32 value asm("$14"); // why: original loaded value uses t6
    if (result != 2) {
    if (result < 3) {
        if (result == 1) value = D_0035ecac;
        else value = D_0035ecb4;
    } else if (result == 8) value = D_0035ecac;
    else value = D_0035ecb4;
    } else value = D_0035ecb0;
    *pointer = value;
    return *pointer;
}






