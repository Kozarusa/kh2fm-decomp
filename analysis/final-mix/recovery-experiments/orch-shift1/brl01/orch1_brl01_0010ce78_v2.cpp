#include "../common/types.h"
extern "C" s32 D_003417b0;
extern "C" u32 func_00190140(...);

s32 func_0010ce78(u8* object) {
    u8 flag = 0;
    if (func_00190140(&D_003417b0)) {
        flag = D_003417b0 != 0;
    }
    return flag && (D_003417b0 == 0 || *(s32*)(object + 0x9f4) != D_003417b0);
}
