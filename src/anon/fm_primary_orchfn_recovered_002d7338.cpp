#include "../common/types.h"
extern "C" u8 D_003625a8[];
extern "C" void func_002e70b0(u32);
extern "C" void func_00106420(u32);
extern "C" s32 func_002cea28(u32*);

s32 func_002d7338(u32* object) {
    object[0] = (u32)D_003625a8;
    u32 pointer = object[40];
    if (pointer != 0) {
        func_002e70b0(pointer);
        func_00106420(pointer);
    }
    s32 result = func_002cea28(object);
    asm("" : "+r"(result)); // why: empty guard blocks sibling-call, original calls then returns
    return result;
}
