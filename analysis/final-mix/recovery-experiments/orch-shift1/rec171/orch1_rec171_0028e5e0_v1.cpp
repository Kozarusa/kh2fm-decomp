#include "../common/types.h"
extern "C" u32 func_00139d78(void);
extern "C" u32 func_0028e510(s32,s32,u32);
u32 func_0028e5e0(s32 object, s16* pointer, s32 count) {
    s32 index = 0;
    u32 result = func_00139d78();
    if (count > 0) {
        do {
            result = func_0028e510(object, index, *pointer);
            ++index;
            ++pointer;
        } while (index < count);
    }
    return result;
}
