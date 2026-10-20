#include "../common/types.h"
extern "C" u32 D_0034f240;
extern "C" u8 D_00351ec8[];
extern "C" s32 func_00197920();
extern "C" s32 func_001c8db8(u8*, u32);

s32 func_00191a50() {
    u32 flags = D_0034f240;
    s32 result = 0;
    if ((flags & 0x100) == 0) {
        if ((flags & 2) == 0) {
            if (func_00197920() == 0 && func_001c8db8(D_00351ec8, 0) == 0) {
                return result;
            }
        }
    }
    return 1;
}