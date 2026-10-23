#include "../common/types.h"
extern "C" u32 D_0035f638;
extern "C" u32 func_0023f900(u32);
extern "C" u32 func_0023fad0(...);
extern "C" u32 func_00293d80(s32);

u32 func_002b2840() {
    if ((*(u32*)(D_0035f638 + 52) & 0x200) != 0 && func_0023f900(D_0035f638) != 0) {
        func_0023fad0(D_0035f638);
    }
    u32 result = func_00293d80(5101);
    *(u32*)(D_0035f638 + 52) &= ~0x200u;
    return result;
}
