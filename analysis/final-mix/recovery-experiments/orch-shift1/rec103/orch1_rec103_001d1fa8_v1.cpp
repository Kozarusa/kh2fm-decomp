#include "../common/types.h"
extern "C" void func_001d1678(u8*, s32);
extern "C" void func_001d19e8(u8*, s32);
extern "C" void func_001d16e8(u8*, s32, s32);
extern "C" void func_00320400(u8*);
extern "C" u8 D_003525c8[];
extern "C" u8 D_003525e8[];

void func_001d1fa8(u8* object) {
    *(s32*)(object + 4) = 0;
    *(u8**)object = D_003525c8;
    *(s32*)(object + 8) = 0;
    func_00320400(object + 12);
    func_001d1678(object, -1);
    *(s32*)(object + 0x30) = 0;
    *(u8**)object = D_003525e8;
    func_001d19e8(object, -1);
    *(s32*)(object + 0x2c) = 0;
    *(s32*)(object + 0x38) = 0;
    func_001d16e8(object, 0, 12);
}