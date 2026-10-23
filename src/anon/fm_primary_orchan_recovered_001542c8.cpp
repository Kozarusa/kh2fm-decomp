#include "../common/types.h"
extern "C" s32 func_001541d8(u8*, s32*, s32);
extern "C" s32 func_00154288(u8*, s32);
extern "C" void func_001387f8(u8*, s32, u8*, s32);

void func_001542c8(u8* object, s32 index, s32 kind) {
    s32 local = 0;
    if (func_001541d8(object, &local, index) == 1) {
        func_001387f8(object, local, object + 0x1a0, func_00154288(object, kind));
    }
}
