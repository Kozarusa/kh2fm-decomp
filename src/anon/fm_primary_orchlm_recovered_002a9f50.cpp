#include "../common/types.h"
extern "C" u32* D_0035f610;
extern "C" s32 func_002a9d68(void);
extern "C" u32 func_00294000(u64);

s32 func_002a9f50(s32 value) {
    s32 result = 1;
    u32* sram = (u32*)func_002a9d68();
    u8* info = (u8*)func_00294000(3);
    if (value < 0) {
        s32 count = *(s32*)(info + 8);
        u32 index;
        for (index = 0; (s32)index < count; index++) {
            u32 mask = 1u << (index & 31);
            if ((D_0035f610[index >> 5] & mask) != 0) {
                result = (sram[index >> 5] & mask) != 0;
                if (result == 0) {
                    return result;
                }
            }
        }
    } else {
        u32 mask = 1u << ((u32)value & 31);
        s32 flag = 0;
        if ((D_0035f610[(u32)value >> 5] & mask) != 0) {
            flag = (sram[(u32)value >> 5] & mask) != 0;
        }
        result = flag;
    }
    return result;
}
