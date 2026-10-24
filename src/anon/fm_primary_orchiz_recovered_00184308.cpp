#include "../common/types.h"
extern "C" s32 func_0016cce8(s32, s32, void*, s32, s32);
extern "C" s32 func_00188340(u8*, s32, s32*, s32);

typedef s32 (*PairMethod)(u8*, u8*);
typedef s32 (*SingleMethod)(u8*);

s32 func_00184308(u8* object) {
    *(u32*)(object + 264) &= 0xf7ffffff;
    s32 result = func_00188340(object + 768, 2, 0, 0);
    if (!(*(u32*)(object + 264) & 0x8000000)) {
        s32 handle = *(s32*)(object + 1156);
        if (handle != 0) {
            result = func_0016cce8(handle, 14, 0, 0, 0);
        }
    }
    if (!(*(u32*)(object + 264) & 0x8000000)) {
        register u8* other asm("$15") = *(u8**)(object + 12); // why: original keeps the second object in t7
        register PairMethod pair asm("$13") = *(PairMethod*)(*(u8**)other + 20); // why: original calls through t5, v0 holds the result
        result = pair(other, object);
    }
    if (!(*(u32*)(object + 264) & 0x8000000)) {
        register SingleMethod single asm("$15") = *(SingleMethod*)(*(u8**)object + 48); // why: original calls through t7, v0 holds the result
        result = single(object);
    }
    return result;
}
