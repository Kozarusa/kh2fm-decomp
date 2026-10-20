#include "../common/types.h"
extern "C" u32 func_001fa950(...);

void func_001fb720(u8* object, s32* message, u8* other) {
    u8* base = object + **(s32**)(other + 12);
    u8* entry = base + 0xa0;
    func_001fa950();
    if (message[0] == *(s32*)(object + 12)) {
        *(f32*)(entry + 0x44) = *(f32*)((u8*)message + 12);
        // why: volatile read keeps the u16 load after the f32 store
        *(f32*)(entry + 0x40) = (f32)*(volatile u16*)((u8*)message + 0x14);
    }
}