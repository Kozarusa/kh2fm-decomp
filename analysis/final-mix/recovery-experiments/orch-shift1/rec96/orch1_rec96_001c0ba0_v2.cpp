#include "../common/types.h"
extern "C" s32* D_01d49360;
extern "C" u32 D_0032f254[];

void func_001c0ba0(u32 key) {
    s32* header = D_01d49360;
    s32 index = 0;
    u32* entry = (u32*)(header + 2);
    if (header[1] > 0) {
        do {
            if (entry[1] == key) {
                D_0032f254[entry[0] >> 5] |= 1 << (entry[0] & 0x1f);
            }
            index++;
            entry += 8;
        } while (index < header[1]);
    }
}
