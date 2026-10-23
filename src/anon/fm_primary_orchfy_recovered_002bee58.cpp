#include "../common/types.h"
typedef s32 (*Callback)(u8*);
extern "C" u8 D_00361980[];
extern "C" u8 D_003637e0[];

s32 func_002bee58(u8* object) {
    *(u8**)object = D_00361980;
    register u8* pointer asm("$13") = *(u8**)(object + 36); // why: original keeps the member in t5
    register Callback callback asm("$14") = *(Callback*)(*(u8**)pointer + 12); // why: original loads the target into t6
    s32 result = callback(pointer);
    *(u8**)object = D_003637e0;
    return result;
}
