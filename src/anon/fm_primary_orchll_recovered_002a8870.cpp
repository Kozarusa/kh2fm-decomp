#include "../common/types.h"
extern "C" s32 func_001d56c8(s32);
extern "C" u32 func_00276c18(void);
extern "C" u32 func_00294000(u64);

s32 func_002a8870(s32 key) {
    s32 index;
    u32 info = func_00294000(7);
    u32 base = info + 16;
    for (index = 0; index < *(s32*)(info + 8); index++) {
        if (key < 0 || *(u16*)(base + index * 8) == key) {
            u8* score = (u8*)func_001d56c8(*(u16*)(base + index * 8 + 6));
            s32 high = (*score < 2) ^ 1;
            asm("" : "+r"(high)); // why: original materializes the inverted flag with xori before branching on it
            if (high != 0) break;
            if (func_00276c18() != 0) break;
        }
    }
    return index < *(s32*)(info + 8);
}
