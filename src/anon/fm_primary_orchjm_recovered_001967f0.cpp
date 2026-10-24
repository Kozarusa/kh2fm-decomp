#include "../common/types.h"
struct Table0032bb30 {
    u8 header[0x1ef8];
    u16 entries[1][2];
};
extern "C" Table0032bb30 D_0032bb30;
extern "C" s32 func_00196618(u32 first, u32 second);
extern "C" u32 func_001d52c0(u32, u32);
extern "C" u32 func_00192048(...);

u32 func_001967f0(u32 first, u32 second, s32 column) {
    s32 index = func_00196618(first, second);
    if (index < 0) {
        return 0;
    }
    u32 value = D_0032bb30.entries[index][column];
    if (value == 0) {
        value = func_001d52c0(first, second);
    }
    return func_00192048(value);
}
