#include "../common/types.h"
extern "C" u8* D_01d5ba6c;
extern "C" void func_001d5960(u8*);

void func_001d59b0(void) {
    // why: original keeps the byte offset in s0 and the loop index in s1
    register s32 index asm("$17");
    register s32 offset asm("$16");
    offset = 0;
    for (index = 0; index < *(s32*)(D_01d5ba6c + 4); index++) {
        func_001d5960(D_01d5ba6c + offset + 8);
        offset += 60;
    }
}
