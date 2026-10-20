#include "../common/types.h"
extern "C" u32 D_0035f654;
extern "C" u32 D_0035f6c8;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00192048(...);
extern "C" u32 func_002b6338(u32);

u32 func_002b5108(u32 value, s32 index) {
    func_00139d78(D_0035f654);
    if (index >= 0) {
        u32 result = func_002b6338(D_0035f6c8);
        *(u32*)(D_0035f654 + 0x198) = D_0035f6c8;
        return result;
    }
    u32 result = func_00192048(value, 0x200, value, index);
    *(u32*)(D_0035f654 + 0x198) = result;
    return result;
}
