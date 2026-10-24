#include "../common/types.h"
extern "C" u8 D_00351ec0[];
extern "C" u8* func_001d3fe0(u16);
extern "C" bool func_001b58a8(void);
extern "C" bool func_001c8db8(void*,s64);
extern "C" s32 func_001d3f80(u8*);
extern "C" s32 func_001b5c60(u8*);
extern "C" u64 func_001a1de0(u32);
extern "C" u32 func_0017df58(s32);
extern "C" bool func_0019ba60(u64);
extern "C" u64 func_0017e280(...);

s32 func_001b5b20(u8* object, u16* info, s32 result) {
    u8* entry = func_001d3fe0(info[0]);
    if (entry != 0) {
        if (func_001b58a8()) {
            result = 5;
        } else if (info[1] == 81 && func_001c8db8(D_00351ec0, 0)) {
            result = 5;
        } else if (func_001d3f80(entry) != 0) {
            if (*(f32*)(*(u8**)(object + 1164) + 436) == 0.0f) {
                result = 5;
            }
        } else {
            s32 cost = func_001b5c60((u8*)info);
            if (cost > 0) {
                if (func_001a1de0(*(u32*)(object + 1164)) != 0) {
                    result = 5;
                } else if (*(s32*)(*(u8**)(object + 1164) + 384) < cost) {
                    result = 2;
                }
            }
        }
        if (info[1] == 707 && result < 4) {
            for (s32 index = 0; index < 2; index++) {
                u32 member = func_0017df58(index);
                if (func_0019ba60((s32)member) && func_0017e280(member) == 0) {
                    result = 5;
                    break;
                }
            }
        }
    }
    return result;
}
