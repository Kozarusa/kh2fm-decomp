#include "../common/types.h"
struct Object {
    void** vtable;
};

s32 func_0011f078(Object* object, u8* data) {
    s32 index = 0;
    s32 result;
    while (true) {
        s32 count = ((s32 (*)(Object*))object->vtable[12])(object);
        bool more = index < count;
        u8* entry = data + index;
        result = 1;
        index = index + 1;
        if (!more) {
            result = 0;
            break;
        }
        if ((*entry & 4) == 0) {
            continue;
        }
        break;
    }
    return result;
}


