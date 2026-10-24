#include "../common/types.h"
extern "C" u32 func_0019c090(...);
extern "C" u64 func_001b9d40(...);
extern "C" s32 func_00177860(...);
extern "C" u32 func_0016bd60(u8*, s32);

s32 func_00179450(u8* object) {
    if (*(s32*)(object + 0xb50) == 7) {
        s32 busy = 0;
        if (func_0019c090(object) == 0) {
            u32 flag = 0;
            if ((*(u32*)(*(u8**)(object + 12) + 8) & 2) != 0 || (*(u32*)(object + 0x160) & 0x40) != 0) {
                flag = 1;
            }
            if ((flag & 0xff) == 0) {
                goto done;
            }
        }
        busy = 1;
    done:
        if ((busy ^ 1) != 0 && *(s32*)(*(u8**)(object + 12) + 4) == 0 && func_001b9d40(object) != 0
            && 0.0f < *(f32*)(object + 0x1c)
            && (*(u32*)((u8*)func_00177860(object) + 0x14) & 0x40) != 0) {
            func_0016bd60(object, 22);
            return 1;
        }
    }
    return 0;
}
