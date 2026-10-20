#include "../common/types.h"
extern "C" s32 func_001bb4a0();
extern "C" s32 func_001bbcb0();

bool func_001d8898(s32 index) {
    if (func_001bb4a0() == 0) {
        return false;
    }
    s32 base = func_001bbcb0();
    if ((u8)(*(u32*)(base + index * 0x38 + 0xf4) & 1) == 0) {
        return false;
    }
    base = func_001bbcb0();
    return (*(u32*)(base + index * 0x38 + 0xf4) & 8) != 0;
}