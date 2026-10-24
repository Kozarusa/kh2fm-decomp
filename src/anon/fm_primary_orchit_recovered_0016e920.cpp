#include "../common/types.h"
extern "C" s32 D_004f63a0;
extern "C" u8 D_0032f054;
extern "C" s32 D_00350cd0;
extern "C" u32 func_0016eb18(u32, u32);
extern "C" u32 func_0017df70(...);
extern "C" u32 func_0017dfc8(s32);
extern "C" u32 func_00198040(s32);
extern "C" u8* func_001a8b28();
extern "C" u32 func_001d1438(u32);
extern "C" u32 func_001d3408(u32);

// Preserve original registry aliases.
u32 func_0016e920(u32 value) asm("_ZN2Tz6JmInfo12GetCharaDataEj");

u32 func_0016e920(u32 value) {
    u32 result = value;
    switch (value & 0x0fffffff) {
    case 0x236:
    {
        s32 current = D_004f63a0;
        if (current != 0) {
            result = current;
            break;
        }
    }
    case 0x23b:
        result = func_001d1438(D_0032f054);
        if (result != 0) {
            break;
        }
        result = func_001d1438(0);
        break;
    case 0x237:
        result = func_0017df70(1);
        break;
    case 0x238:
        result = func_0017df70(2);
        break;
    case 0x23c:
        result = func_00198040(1);
        break;
    case 0x23d:
        result = func_0016eb18(0x236, 0);
        break;
    case 0x23f:
        result = func_0016eb18(*(u16*)(func_001a8b28() + 0x12), 0);
        break;
    case 0x240:
        result = func_0016eb18(*(u16*)(func_001a8b28() + 0x14), 0);
        break;
    case 0x2c0:
        result = func_0016eb18(101, 0);
        break;
    case 0x319:
        result = func_0017dfc8(1);
        break;
    case 0x31a:
        result = func_0017dfc8(2);
        break;
    case 0x3ee:
        result = func_0017dfc8(3);
        break;
    case 0x62a:
        result = (D_00350cd0 == 0x40b) ? 0x40c : 0x40b;
        break;
    case 0x62b:
        result = (D_00350cd0 == 0x40b) ? 0x40b : 0x40c;
        break;
    }
    if (result == 0) {
        return 0;
    }
    return func_001d3408(result & 0x0fffffff);
}
