#include "../common/types.h"
extern "C" u8* D_01d9e6e4;
extern "C" void func_0021fe08(void*, s32);

// Preserve original registry aliases.
void func_001fab48(u8* object, s32* message, u8* other) asm("_Z13func_001fab48Pv");

void func_001fab48(u8* object, s32* message, u8* other) {
    s32* table = *(s32**)(other + 12);
    u8* base = object + table[0];
    u8* entry = base + 0xa0;
    if (message[0] == *(s32*)(object + 12)) {
        *(s32*)(base + 0xa0) = (s32)object + table[1] + 0xa0;
        s32 id = message[1];
        if (id == 0xffff) {
            *(s32*)(entry + 4) = 0;
        } else {
            s32 value = *(s32*)(D_01d9e6e4 + 0x14) + id * 8;
            if (value != *(s32*)(entry + 4)) {
                func_0021fe08(entry, value);
            }
        }
    }
}
