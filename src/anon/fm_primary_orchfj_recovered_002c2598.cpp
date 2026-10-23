#include "../common/types.h"
extern "C" u8* func_001c3748(u8*, u8*);
extern "C" u32 func_00192048(u32);

u32 func_002c2598(u8* object, s32 index) {
    s32 count = 0;
    u8* node = 0;
    while ((node = func_001c3748(object, node)) != 0) {
        if (count == index) {
            return func_00192048(*(u16*)(node + 4));
        }
        count++;
    }
    return (u32)node;
}
