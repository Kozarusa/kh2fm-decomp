#include "../common/types.h"
extern "C" u32 func_0028be58(...);
extern "C" u32 func_0028e4c8(s32,s32);
extern "C" u32 func_0028e560(u64,void*,s32,u64);
u32 func_0028bdb8(u8* object) {
    u32 result = func_0028be58(object);
    if (result == 0) return result;
    result = func_0028e4c8(*(s32*)object,0);
    if (result == (u32)*(s16*)(object+16)) return result;
    return func_0028e560(*(s32*)object,object+16,4,(u64)-1);
}
