#include "../common/types.h"
extern "C" f32 D_00376140;
extern "C" void func_002eb778(f32 blend, u32 object, s32 value, u8 force);

void func_002ec170(s32 owner, u32 object) {
    f32* blend = &D_00376140;
    asm("" : "+r"(blend)); // why: original keeps the full address in t7 and loads with offset 0
    func_002eb778(*blend, object, *(s32*)(object + 0x100), 0);
    *(u32*)(object + 0x10c) = *(u32*)(object + 0x10c) & 0xfffffffe;
    *(u32*)(object + 0x108) = *(u32*)(object + 0x108) | 0x4000000;
}
