#include "../common/types.h"
extern "C" u8* D_01d49360;
extern "C" u32 D_0032f254[];

void func_001c0ba0(u32 key) {
    u8* base = D_01d49360;
    s32 index = 0;
    u32* entry = (u32*)(base + 8);
    if (*(s32*)(base + 4) > 0) {
        do {
            if (entry[1] == key) {
                D_0032f254[entry[0] >> 5] |= 1 << (entry[0] & 0x1f);
            }
            index++;
            entry += 8;
        } while (index < *(s32*)(base + 4));
    }
}
