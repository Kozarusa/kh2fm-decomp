// func_002c2610: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"
extern "C" u8* func_001c3748(u8*, u8*);
extern "C" u32 func_00192048(u32);

u32 func_002c2610(u8* object, s32 index) {
    s32 count = 0;
    u8* node = 0;
    while ((node = func_001c3748(object, node)) != 0) {
        if (count == index) {
            return func_00192048(*(u16*)(node + 0x6));
        }
        count++;
    }
    return (u32)node;
}
