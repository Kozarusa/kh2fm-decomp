#include "../common/types.h"
extern "C" s32 D_003417b0;
extern "C" u64 func_00190140(...);

s32 func_0010ce78(u8* object) {
    u32 flag = 0;
    if (func_00190140(&D_003417b0)) {
        flag = D_003417b0 != 0;
    }
    s32 result = 0;
    if (flag & 0xff) {
        s32 value = D_003417b0;
        result = 1;
        if (value != 0) {
            result = 0;
            if (*(volatile s32*)(object + 0x9f4) != value) {
                result = 1;
            }
        }
    }
    return result;
}

