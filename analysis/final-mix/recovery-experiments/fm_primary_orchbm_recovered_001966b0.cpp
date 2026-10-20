#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" u32 D_01c61b08;
extern "C" s32 func_00196388(u32, u32);
extern "C" s32 func_001963f8(s32);

s32 func_001966b0(s32 index) {
    u16* slot = (u16*)(D_0032bb30 + index * 4);
    u32 table = D_01c61b08;
    slot[0x1ef8 / 2] = 0xffff;
    u8* entry = (u8*)(index * 2 + table);
    s32 result = func_00196388(entry[2], entry[3]);
    if (result >= 0) {
        return func_001963f8(result);
    }
    return result;
}
