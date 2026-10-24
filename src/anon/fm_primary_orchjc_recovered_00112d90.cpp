#include "../common/types.h"
extern "C" bool func_00112d28(...);
extern "C" u32 func_00190140(...);

u32 func_00112d90(s32* object) {
    s32* pointer = object;
    u32 flag = 0;
    u32 result = 0;
    if (func_00190140(object) != 0) {
        flag = (u32)(*pointer != 0);
    }
    if ((flag & 0xff) != 0) {
        result = func_00112d28((u32)*pointer);
    }
    return result;
}
