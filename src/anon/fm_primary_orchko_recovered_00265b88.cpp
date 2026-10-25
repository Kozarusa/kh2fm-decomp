#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 D_0035f01c;
extern "C" u32 D_0035f020;

u32 func_00265b88() {
    u32 object = func_00257770();
    u32 result = func_00139d78(object);
    if (result == 0) {
        s32 index;
        object += 0x5ef0;
        index = 0;
        do {
            result = func_00139d78(object);
            if (result != 0) return result;
            object += 0x1b4;
            index++;
        } while (index < 20);
        result = func_0028acc8(D_0035f01c);
        if (result == 0) {
            result = func_0028acc8(D_0035f020);
        }
    }
    return result;
}
