#include "../common/types.h"
struct Inner { u8 pad[0xdc4]; u8* table; };
extern "C" Inner* volatile D_00352bd0;

void func_001e0d08(volatile s32* object, f32* vec) {
    *(f32*)(D_00352bd0->table + object[8] * 0x40 + 0x30) = vec[0];
    *(f32*)(D_00352bd0->table + object[8] * 0x40 + 0x34) = vec[1];
    *(f32*)(D_00352bd0->table + object[8] * 0x40 + 0x38) = vec[2];
}
