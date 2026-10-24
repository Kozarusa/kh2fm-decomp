#include "../common/types.h"

extern "C" u32 func_00135c50(s32*, void*);
extern "C" u32 func_00135ad0(s32*);

u32 func_00135bd0(s32* object, void* value) {
    u32 result = func_00135c50(object, value);
    s32 count = object[3];
    s32 first = count;
    if (count == 0x20) {
        result = func_00135ad0(object);
        count = object[3];
        if (count == first) {
            result = func_00135c50(object, ((void**)object)[4]);
            count = object[3];
        }
    }
    ((void**)object)[count + 4] = value;
    object[3] = count + 1;
    return result;
}
