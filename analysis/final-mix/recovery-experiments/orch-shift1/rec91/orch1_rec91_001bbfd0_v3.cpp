#include "../common/types.h"
extern "C" u8 D_0036dc44[];
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

f32 func_001bbfd0(void) {
    if (func_001bb4a0()) {
        u32 object = func_001bbcb0();
        return *(f32*)(object + 0x530);
    }
    f32 *p = (f32 *)D_0036dc44;
    asm("" : "+r"(p)); // why: forces address to be built in a register before the load
    return *p;
}
