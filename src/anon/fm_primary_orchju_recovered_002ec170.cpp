#include "../common/types.h"
extern "C" void func_002eb778(f32 blend, u32 object, s32 value, u8 force);

void func_002ec170(s32 owner, u32 object) {

         func_002eb778(8.0f, object, *(s32*)(object + 0x100), 0);
    *(u32*)(object + 0x10c) = *(u32*)(object + 0x10c) & 0xfffffffe;
    *(u32*)(object + 0x108) = *(u32*)(object + 0x108) | 0x4000000;
}
