#include "../common/types.h"
extern "C" u32 func_00138c10(...);
extern "C" u32 func_00263cc0();
extern "C" s16 D_0035f0d8;
extern "C" u8* D_0035f0dc;
u32 func_00263c60() {
    u32 result = func_00263cc0();
    if (result) {
        s32 value = D_0035f0d8;
        u8* object = D_0035f0dc;
        if (*(s32*)(object+0x184) != value) {
            result = func_00138c10(object,value);
            *(s32*)(D_0035f0dc+0x188) = -1;
        }
    }
    return result;
}
