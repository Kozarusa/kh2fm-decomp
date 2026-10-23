#include "../common/types.h"
extern "C" s32 D_0032b96c;
extern "C" void func_002c6280();
extern "C" s32 func_002ef8d0(u8*, s32);

s32 func_002c6228(u8* object, s32 index, s32 value) {
    func_002c6280();
    *(s32*)(object + index * 4 + 0x10) = value;
    return func_002ef8d0(object, D_0032b96c);
}
