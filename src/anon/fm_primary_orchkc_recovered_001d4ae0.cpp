#include "../common/types.h"
extern "C" u8 D_0036e4a0[];
extern "C" u8 D_0036e4b0[];
extern "C" u8 D_0036e4c0[];
extern "C" u32 func_001bce90(...);
extern "C" u32 func_00190878(void*,u32,u32);

s32 func_001d4ae0(s32* object, s32 player, s32 menu) {
    if ((*(u32*)(player + 0x160) & 0x4000) == 0 || *(s32*)(player + 0xb70) == 0) {
        return 0;
    }
    func_00190878(object + 3, object[1], 0);
    switch (*(s32*)(player + 0xb70)) {
    case 1:
        func_001bce90(menu, D_0036e4a0, 3, object + 3);
        break;
    case 2:
        func_001bce90(menu, D_0036e4b0, 3, object + 3);
        break;
    case 3:
        func_001bce90(menu, D_0036e4c0, 3, object + 3);
        break;
    }
    return 1;
}
