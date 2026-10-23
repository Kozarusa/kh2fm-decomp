#include "../common/types.h"
extern "C" u32 D_0035db18;
extern "C" u32 func_00224e90(u32*);
extern "C" u32 func_00225640(u32, u32, u32);
extern "C" u32 func_00227870(...);

u32 func_002256c8(u32* object, u32 buffer) {
    u32 result;
    if (func_00224e90(object) != 0 || D_0035db18 != 0x400000) {
        result = func_00227870(buffer, object, 0);
        object[5] = result;
    } else {
        result = func_00225640(buffer, (u32)object, 0);
        object[5] = result;
    }
    return result;
}
