#include "../common/types.h"
extern "C" u32 func_001d5370(void*, u64, s32);
extern "C" u32 func_002534e0(...);

u32 func_001bba30(u8* object) {
    u32 stack0 = 0;
    u32 stack1 = 0;
    u32 result = 0;
    u32 target = *(u32*)(object + 0x48);
    if (target != 0) {
        u8 count = *(u8*)(*(u32*)(object + 8) + 12);
        if (count == 0) {
            result = 0;
        } else {
            func_001d5370(&stack0, target, count - 1);
            func_002534e0(stack1, stack0);
            result = 1;
        }
    }
    return result;
}