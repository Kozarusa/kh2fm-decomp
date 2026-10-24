#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 D_0036cba8[];
extern "C" s32 func_0018b198(u8*);
extern "C" s32 func_001ad9c8(f32*);
extern "C" void func_0016aeb8(u32, f32);
extern "C" s32 func_001b0728(u8*, Quad*, s32, f32);

s32 func_0018b110(u8* object) {
    s32 result = func_0018b198(object);
    if (result != 0) {
        func_001ad9c8((f32*)(object + 0xa20));
        func_0016aeb8((u32)object, *(f32*)(object + 0xa04) + *(f32*)(object + 0xa08) * *(f32*)(object + 0xa20));
        result = func_0018b198(object);
        if (result == 0 && object[0xa00] != 0) {
            f32* pointer = D_0036cba8;
            asm("" : "+r"(pointer)); // why: original materializes the full address before the load
            result = func_001b0728(object + 0x4a0, (Quad*)(object + 0xa10), 0, *pointer);
            object[0xa00] = 0;
        }
    }
    return result;
}
