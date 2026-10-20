#include "../common/types.h"
extern "C" u32 func_0019ef70(void*);
extern "C" u32 func_0031cc28(void*);

void func_00198dc0(u32* object) {
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
    *(u8*)((u8*)object + 0x3a) = 0xff;
    *(u8*)((u8*)object + 0x39) = 0xff;
    *(u16*)(object + 16) = 0xffff;
    *(u16*)(object + 15) = 0xffff;
    *(u16*)((u8*)object + 0x3e) = 0xffff;
    func_0031cc28(object + 21);
    func_0019ef70(object + 13);
}
