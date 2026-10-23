#include "../common/types.h"
extern "C" s32 D_0034e948;
extern "C" void func_001781e8(s32);
extern "C" u32 func_001dc920(s32);
extern "C" void func_00175928(u8 *);

// Preserve original registry aliases.
void func_00178280(u8 *object) asm("_Z16wtarget_00178280jjjj");

void func_00178280(u8 *object) {
    D_0034e948 = 0;
    func_001781e8((s32)object);
    s32 effect = *(s32 *)(object + 0xb60);
    if (effect != 0) {
        func_001dc920(effect);
        *(s32 *)(object + 0xb60) = 0;
    }
    func_00175928(object);
}
