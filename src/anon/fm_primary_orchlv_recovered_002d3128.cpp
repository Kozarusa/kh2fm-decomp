#include "../common/types.h"
extern "C" void* D_00361f60;
extern "C" void* func_002d1878(void*);

void* func_002d3128(u8* object, s32 count) {
    void* manager = func_002d1878(D_00361f60);
    f32 scale = *(f32*)((u8*)manager + 0x50);
    for (s32 i = 0; i < 64 && count > 0; i++) {
        f32* slot = (f32*)(object + 0xb80) + i;
        if (slot[1] < 0.0f) {
            count--;
            slot[1] = scale * (f32)count;
        }
    }
    return manager;
}
