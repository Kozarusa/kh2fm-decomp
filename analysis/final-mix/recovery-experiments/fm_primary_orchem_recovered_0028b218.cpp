#include "../common/types.h"

void func_0028b218(u8* object,u8 flag) {
    object[39] = flag;
    register u32 result asm("$15"); // why: original merged branch result resides in t7
    if (flag) result = *(u32*)(object + 52) | 0x3000;
    else result = *(u32*)(object + 52) & 0xffffcfff;
    *(u32*)(object + 52) = result;
}
