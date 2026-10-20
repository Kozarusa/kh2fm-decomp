#include "../common/types.h"
extern "C" s32 D_003417b0;
extern "C" u64 func_00190140(...);

s32 func_0010ce78(u8* object) {
    u8 flag = 0;
    if (func_00190140(&D_003417b0)) {
        flag = D_003417b0 != 0;
    }
    if (flag) {
        s32 value = D_003417b0;
        if (value != 0) {
            if (*(s32*)(object + 0x9f4) == value) {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}
