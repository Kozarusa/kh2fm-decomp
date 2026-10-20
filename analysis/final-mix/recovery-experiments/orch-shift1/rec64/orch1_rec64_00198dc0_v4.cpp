#include "../common/types.h"
extern "C" u32 func_0019ef70(void*);
extern "C" u32 func_0031cc28(void*);

void func_00198dc0(u32* object) {
    u32* jumper = object + 13;
    s8* part38 = (s8*)object + 56;
    s16* part3c = (s16*)((u8*)object + 60);
    object[0] = -1;
    object[1] = -1;
    object[2] = 0xffff;
    object[3] = -1;
    object[4] = 0;
    object[5] = -1;
    object[6] = 0;
    object[7] = 0;
    *(u16*)((u8*)object + 0x2e) = 0;
    *(u8*)(object + 12) = 0;
    *(u8*)(object + 14) = 0xffff;
    part38[2] = -1;
    part38[1] = -1;
    part3c[2] = -1;
    part3c[0] = 0xffff;
    part3c[1] = -1;
    func_0031cc28(object + 21);
    func_0019ef70(jumper);
}
