#include "../common/types.h"
extern "C" u32 func_0010a800(void*,void*,void*);

void func_00108600(u8* object) {
    *(s32*)object = 0;
    object[7] = 0x80;
    object[6] = 0x80;
    object[5] = 0x80;
    object[4] = 0x80;
    func_0010a800(object + 8, object + 9, object + 10);
    object[11] = 0xff;
    object[43] = 0x80;
    object[42] = 0x80;
    object[41] = 0x80;
    *(u64*)(object + 24) = 0x31000070;
    *(u64*)(object + 16) = 0x800d8;
    *(s32*)(object + 32) = 0;
    *(s32*)(object + 36) = 0;
    object[40] = 0;
    *(s32*)(object + 44) = 0;
    *(s32*)(object + 48) = 0;
    *(s32*)(object + 52) = 0;
}
