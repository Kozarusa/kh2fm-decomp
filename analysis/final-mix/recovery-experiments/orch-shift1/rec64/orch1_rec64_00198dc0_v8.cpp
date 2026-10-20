#include "../common/types.h"
extern "C" u32 func_0019ef70(void*);
extern "C" u32 func_0031cc28(void*);

void func_00198dc0(u32* object) {
    u32* jumper = object + 13;
    u8* part38 = (u8*)object + 56;
    u16* part3c = (u16*)((u8*)object + 60);
    u32 mask = 0xffff;
    u32 minus = 0xffffffff;
    object[0] = minus;
    object[1] = minus;
    object[2] = mask;
    object[3] = minus;
    object[4] = 0;
    object[5] = minus;
    object[6] = 0;
    object[7] = 0;
    *(u16*)((u8*)object + 0x2e) = 0;
    *(u8*)(object + 12) = 0;
    *(u8*)(object + 14) = mask;
    part38[1] = minus;
    part38[2] = minus;
    part3c[2] = minus;
    part3c[0] = mask;
    part3c[1] = minus;
    func_0031cc28(object + 21);
    func_0019ef70(jumper);
}

