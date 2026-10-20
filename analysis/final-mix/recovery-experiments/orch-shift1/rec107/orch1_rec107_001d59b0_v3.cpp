#include "../common/types.h"
extern "C" u8* D_01d5ba6c;
extern "C" void func_001d5960(u8*);

void func_001d59b0(void) {
    s32 offset = 0;
    s32 index;
    for (index = 0; index < *(s32*)(D_01d5ba6c + 4); index++) {
        func_001d5960(D_01d5ba6c + offset + 8);
        offset += 60;
    }
}
