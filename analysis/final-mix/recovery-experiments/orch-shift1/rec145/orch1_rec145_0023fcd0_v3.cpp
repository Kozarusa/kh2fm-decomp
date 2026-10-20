#include "../common/types.h"
extern "C" u32 func_002fdd68(...);
extern "C" s32 D_0035ebec;
extern "C" u8* D_0035ebf0;
extern "C" u32 D_0035ebe8;
u32 func_0023fcd0(u32 object) {
    u8* pointer = D_0035ebf0 + D_0035ebec * 8;
    u32 result = func_002fdd68(object, *(u32*)(pointer - 8), *(u32*)(pointer - 4));
    s32 count = D_0035ebec;
    u32 value = *(u32*)(pointer - 8);
    D_0035ebec = count - 1;
    D_0035ebe8 = value;
    return result;
}


