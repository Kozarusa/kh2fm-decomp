#include "../common/types.h"
extern "C" int func_0028b040(...);
extern "C" u32 func_00281f20(u32);
extern "C" u32 func_001a3820(...);
extern "C" s32 func_002570a0(...);
extern "C" u32 func_001058e8(void);
extern "C" u32 D_0035f01c;
extern "C" u32 D_0035f014;
u32 func_00273678() {
    u32 value = 0;
    s32 index = func_0028b040(D_0035f01c);
    if (index) {
        u32 object = func_00281f20(D_0035f014);
        value = func_001a3820(*(u16*)(object + index*6 - 6));
    }
    s32 slot = func_002570a0(26);
    u32 result = func_001058e8();
    register s32 offset asm("$15") = slot*2; // why: original shifts slot into t7, leaving s0 restorable
    u8* pointer = (u8*)(offset + result + 0x36f0);
    *(u16*)(pointer + 8) = value;
    return result;
}



