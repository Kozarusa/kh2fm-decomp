#include "../common/types.h"
extern "C" s64 func_001a1de0(s32);
extern "C" void* D_0036b2d8[];

s32 func_00155f40(u8* object) {
    u8* owner = *(u8**)(object + 0x34);
    s32 result = 0x17;
    if (owner != 0) {
        u32 kind = *(u8*)(*(u8**)(owner + 0x48c) + 0x1af);
        if (kind < 5) {
            goto *D_0036b2d8[kind];
        }
        goto call_case;
    case4:
        result = 0x13;
        goto done;
    call_case: {
            s64 flag = func_001a1de0(*(s32*)(owner + 0x48c));
            result = 0x1a;
            if (flag == 0) {
                result = 0x17;
            }
            goto done;
        }
    case2:
        result = 0x33;
        goto done;
    case3:
        result = 0x8d;
    }
done:
    return result;
}