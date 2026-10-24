#include "../common/types.h"
extern "C" f32 D_0037443c;
extern "C" f32 D_00349e10;
extern "C" void func_00138840(void*);
extern "C" u32 func_00313b80(f32);
extern "C" s32 func_003142e0(s32, u32);

void func_0028d2a0(u8* object) {
    if ((*(u32*)(object + 12) & 0x100) != 0) {
        return;
    }
    func_00138840(object);
    s32 result = func_003142e0(0, func_00313b80(*(f32*)(object + 0x1a0)));
    f32* pointer = &D_0037443c;
    asm("" : "+r"(pointer)); // why: original materializes the full address before the load
    f32 limit = *pointer;
    if (result > 0) {
        return;
    }
    f32 value = *(f32*)(object + 0x1a0);
    if (value < limit) {
        f32 sum = value + D_00349e10;
        *(f32*)(object + 0x1a0) = sum;
        if (limit < sum) {
            *(f32*)(object + 0x1a0) = limit;
        }
    }
}
