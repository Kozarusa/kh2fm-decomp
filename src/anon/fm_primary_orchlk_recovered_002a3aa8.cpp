#include "../common/types.h"
// why: copied from fm_primary_orchex_recovered_002a4990.cpp
extern "C" u32 D_0035f5e4;
// why: signature from the definition in fm_primary_orchex_recovered_002a4990.cpp; extern "C" because the C++ form failed the isolated link (v1): the probe linker script defines only the plain symbol
extern "C" s32 func_002a4990(s32 value);
// why: no call site exists; v0 only tested for zero
extern "C" u32 func_002a4430(void);
// why: signature from the definition in fm_scalar_recovered_07.cpp; extern "C" because the C++ form failed the isolated link (v1): the probe linker script defines only the plain symbol
extern "C" u32 func_002a43f0(void);
// why: no call site exists; a0 = slot index, result unused
extern "C" u32 func_002ac8e0(s32);
// why: no call site exists; a0 = slot index, result unused
extern "C" u32 func_002ab728(s32);
// why: no call site exists; a0 = slot index, result unused
extern "C" u32 func_002abac8(s32);
// why: no call site exists; its tail chain (002a3950 -> 002fde18 / 001a3788 / 00192c90 / 0028de08) ends in integer v0 writers
extern "C" u32 func_002a3318(void);

// why: the only exit is the tail call into 002a3318, whose chain leaves an integer v0, so that direct result is returned

u32 func_002a3aa8(void) {
    s32 index = func_002a4990(-1);
    if (func_002a4430() != 0) {
        u8* slot = (u8*)(index * 8 + D_0035f5e4) + 0x1000;
        if (slot[2] != 0 && slot[3] == 0) {
            func_002ac8e0(index);
            *((u8*)(index * 8 + D_0035f5e4) + 0x1003) = 1;
        }
    } else if (func_002a43f0() != 0) {
        u8* slot = (u8*)(index * 8 + D_0035f5e4) + 0x1000;
        if (slot[2] != 0 && slot[3] == 0) {
            func_002ab728(index);
            *((u8*)(index * 8 + D_0035f5e4) + 0x1003) = 1;
        }
    } else {
        u8* slot = (u8*)(index * 8 + D_0035f5e4) + 0x1000;
        if (slot[2] != 0 && slot[3] == 0) {
            func_002abac8(index);
            *((u8*)(index * 8 + D_0035f5e4) + 0x1003) = 1;
        }
    }
    return func_002a3318();
}
