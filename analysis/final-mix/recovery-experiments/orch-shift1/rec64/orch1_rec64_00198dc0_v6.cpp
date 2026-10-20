#include "../common/types.h"
extern "C" u32 func_0019ef70(void*);
extern "C" u32 func_0031cc28(void*);

void func_00198dc0(u32* object) {
    u32* base = object;
    // why: keeps a separate copy of the pointer like the original (move t7,a0)
    asm("" : "+r"(base));
    u8* part38 = (u8*)object + 56;
    u16* part3c = (u16*)((u8*)object + 60);
    object[0] = 0xffffffff;
    object[1] = 0xffffffff;
    object[2] = 0xffff;
    object[3] = 0xffffffff;
    base[4] = 0;
    base[5] = 0xffffffff;
    base[6] = 0;
    base[7] = 0;
    *(u16*)((u8*)base + 0x2e) = 0;
    *(u8*)(base + 12) = 0;
    *(u8*)(base + 14) = 0xff;
    part38[2] = 0xff;
    part38[1] = 0xff;
    part3c[2] = 0xffff;
    *(u16*)(base + 15) = 0xffff;
    part3c[1] = 0xffff;
    func_0031cc28(object + 21);
    func_0019ef70(base + 13);
}
