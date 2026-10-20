#include "../common/types.h"
extern "C" s32 func_001bb4a0();
extern "C" s32 func_001bbcb0();

bool func_001d8898(s32 index) {
    bool result = false;
    if (func_001bb4a0() != 0) {
        s32 base = func_001bbcb0();
        result = false;
        if ((bool)(*(u32*)(base + index * 0x38 + 0xf4) & 1)) {
            base = func_001bbcb0();
            result = (*(u32*)(base + index * 0x38 + 0xf4) & 8) != 0;
        }
    }
    return result;
}