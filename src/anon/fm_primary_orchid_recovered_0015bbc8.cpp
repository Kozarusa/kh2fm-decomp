#include "../common/types.h"
extern "C" f32 D_0036b3d0[];
extern "C" u32 func_0014fc40(...);
extern "C" void func_0015b7c0(u8*, u32);
extern "C" void func_0015c068(u8*, u32);
extern "C" s32 func_001664c0(s32);

void func_0015bbc8(u8* object, u32 value) {
    f32* pointer;
    func_0014fc40(object, 18, 0, 5000, 0, 1);
    func_0015b7c0(object + 48, value);
    func_0015c068(object, value);
    func_001664c0(*(s32*)(object + 2976));
    *(u8*)(object + 3024) = 1;
    *(u8*)(object + 3025) = 96;
    pointer = D_0036b3d0;
    asm("" : "+r"(pointer)); // why: original materializes the full address before the load
    *(f32*)(object + 2992) = *pointer;
}
