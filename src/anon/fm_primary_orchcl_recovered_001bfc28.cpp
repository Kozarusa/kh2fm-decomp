#include "../common/types.h"
extern "C" s32 D_0034e948;
extern "C" u8* func_001b9bc8(u8*);
extern "C" void func_001bf378(u8*, s32);

// Preserve original registry aliases.
void func_001bfc28(void) asm("_Z17ttarget0_001bfc28v");

void func_001bfc28(void) {
    s32 value = D_0034e948;
    u8* object = 0;
    while ((object = func_001b9bc8(object)) != 0) {
        if (*(u32*)(object + 0x588) & 0x40000) {
            func_001bf378(object, value);
        }
    }
}
