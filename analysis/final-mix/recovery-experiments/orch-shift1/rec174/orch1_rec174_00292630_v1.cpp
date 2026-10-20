#include "../common/types.h"
extern "C" u32 func_00102a38(s32,s32);
extern "C" u32 func_00103eb0(void);
extern "C" s64 func_00170cd0(void);
extern "C" u8 D_0035f4b8;
extern "C" u8 D_00292608[];
s64 func_00292630() {
    s64 flag = D_0035f4b8;
    u32 object = func_00103eb0();
    if (func_00102a38(*(s32*)(object + 4), (s32)D_00292608)) return 1;
    if (flag == 0) flag = func_00170cd0();
    return flag;
}
