#include "../common/types.h"
extern "C" u32 func_00263ea8(void);
s32 func_00264328(u32 value) {
    u32 object = func_00263ea8();
    u16* pointer = (u16*)(object + *(s32*)(object+12));
    s32 result = -1;
    s32 index = 0;
    do {
        u16 item = *pointer++;
        if (item == value) { result = index; break; }
        ++index;
    } while (index < 128);
    return result;
}
