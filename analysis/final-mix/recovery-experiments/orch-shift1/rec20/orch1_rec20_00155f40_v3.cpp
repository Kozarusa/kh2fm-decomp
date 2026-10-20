#include "../common/types.h"
extern "C" s64 func_001a1de0(s32);

s32 func_00155f40(u8* object) {
    u8* owner = *(u8**)(object + 0x34);
    s32 result;
    if (owner == 0) {
        result = 0x17;
    } else {
        switch (*(u8*)(*(u8**)(owner + 0x48c) + 0x1af)) {
        case 0:
        case 1:
        default:
            if (func_001a1de0(*(s32*)(owner + 0x48c))) {
                result = 0x1a;
            } else {
                result = 0x17;
            }
            break;
        case 2:
            result = 0x33;
            break;
        case 3:
            result = 0x8d;
            break;
        case 4:
            result = 0x13;
            break;
        }
    }
    return result;
}