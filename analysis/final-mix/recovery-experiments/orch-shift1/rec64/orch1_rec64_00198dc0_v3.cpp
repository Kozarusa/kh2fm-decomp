#include "../common/types.h"
extern "C" u32 func_0019ef70(void*);
extern "C" u32 func_0031cc28(void*);

void func_00198dc0(u32* object) {
    u32* jumper = object + 13;
    u8* part38 = (u8*)object + 56;
    u16* part3c = (u16*)((u8*)object + 60);
    object[0] = 0xffffffff;
    object[1] = 0xffffffff;
    object[2] = 0xffff;
    object[3] = 0xffffffff;
    object[4] = 0;
    object[5] = 0xffffffff;
    object[6] = 0;
    object[7] = 0;
    *(u16*)((u8*)object + 0x2e) = 0;
    *(u8*)(object + 12) = 0;
    *(u8*)(object + 14) = 0xff;
    part38[2] = 0xff;
    part38[1] = 0xff;
    part3c[2] = 0xffff;
    part3c[0] = 0xffff;
    part3c[1] = 0xffff;
    func_0031cc28(object + 21);
    func_0019ef70(jumper);
}
