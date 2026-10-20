#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { f32 value[4]; };
extern "C" u32 func_00144908(void*, void*);
extern "C" u32 func_0016b0d0(void);
extern "C" s32 func_0016c028(s32);

void func_001608c0(u8* object) {
    Quad local;
    func_00144908(object + 0x290, &local);
    Quad* dest = (Quad*)(object + 0x280);
    Quad* source = &local;
    // why: original copies the quad with lq t0 / sq t0 through a pointer register
    if (dest != source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*dest) : "r"(source), "r"(dest), "m"(*source) : "$8");
    s32 player = func_0016b0d0();
    if (player != 0) {
        f32* data = (f32*)func_0016c028(player);
        f32 value = data[1];
        if (*(f32*)(object + 0x294) <= value && value <= *(f32*)(object + 0x2a0)) {
            *(f32*)(object + 0x284) = value;
        }
    }
}
