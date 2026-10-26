#include "../common/types.h"
extern "C" u32 func_00178888(s32);
extern "C" u32 func_00190140(s32);
extern "C" u32 func_001bc778(s32);
extern "C" s32 func_001bc780(s32,u64,s32,u64);

u32 func_002c5900(s32 object) {
    s32 menu = *(s32*)(object + 0xb44) + 0x4ac;
    s32 entry;
    func_001bc778(menu);
    if (func_00190140(*(s32*)(object + 0xb40) + 4) != 0) {
        entry = func_001bc780(menu, 0x246, 0, 1);
    } else {
        entry = func_001bc780(menu, 0x247, 0, 1);
    }
    *(u8*)(entry + 6) = 4;
    // why: only exit is the tail call; its result is returned (DEVIATIONS 36 iv), accepted declaration is u32
    return func_00178888(object);
}
