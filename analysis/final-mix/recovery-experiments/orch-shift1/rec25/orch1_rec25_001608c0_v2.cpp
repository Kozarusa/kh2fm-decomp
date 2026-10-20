#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_00144908(void*, void*);
extern "C" u32 func_0016b0d0(void);
extern "C" s32 func_0016c028(s32);

void func_001608c0(u8* object) {
    Quad local;
    func_00144908(object + 0x290, &local);
    Quad* dest = (Quad*)(object + 0x280);
    asm("" : "+r"(dest)); // why: keeps pointer in its own register
    if (dest != &local) {
        *dest = local;
    }
    s32 player = func_0016b0d0();
    if (player != 0) {
        f32* data = (f32*)func_0016c028(player);
        f32 value = data[1];
        if (*(f32*)(object + 0x294) <= value && value <= *(f32*)(object + 0x2a0)) {
            *(f32*)(object + 0x284) = value;
        }
    }
}

