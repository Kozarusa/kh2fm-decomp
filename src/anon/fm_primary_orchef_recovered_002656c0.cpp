#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 D_0035f01c;

u32 func_002656c0() {
    u32 object = func_00257770();
    u32 result = func_00139d78(object);
    if (result == 0) {
        s32 index = 0;
        do {
            result = func_00139d78(object+0x3610);
            if (result != 0) return result;
            result = func_00139d78(object+0x5ef0);
            if (result != 0) return result;
            ++index;
            object += 0x1b4;
        } while (index < 20);
        result = func_0028acc8(D_0035f01c);
    }
    return result;
}
