#include "../common/types.h"
extern "C" u8 D_00375518[];
extern "C" s32 func_002c1b48(u8*);
extern "C" s32 func_001c2b58(s32);
extern "C" void func_002c1b60(u8*, s32);
extern "C" s32 func_00198450(u8*);

s32 func_002c1ae8(u8* object) {
    s32 course = func_002c1b48(object);
    s32 base = (s32)D_00375518;
    s32 adjusted = base - 3;
    *(s32*)(object + 0xae4) = course * 3 + adjusted;
    s32 value = func_001c2b58(func_002c1b48(object));
    func_002c1b60(object, value);
    return func_00198450(object);
}
