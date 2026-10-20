#include "../common/types.h"
extern "C" u16 func_001bc010(void);
extern "C" u32 func_0017df58(s32);
extern "C" bool func_0019ba60(u32);
extern "C" bool func_0017e3b8(u32);

u32 func_001c9ab8(void) {
    if (func_001bc010() == 0) {
        s32 index = 0;
        do {
            u32 object = func_0017df58(index);
            index++;
            if (!func_0019ba60(object) || !func_0017e3b8(object)) {
                return 0;
            }
        } while (index < 2);
    }
    return 1;
}
