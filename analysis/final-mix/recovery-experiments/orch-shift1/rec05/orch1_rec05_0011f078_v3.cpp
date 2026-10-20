#include "../common/types.h"
struct Object {
    void** vtable;
};

s32 func_0011f078(Object* object, u8* data) {
    s32 index = 0;
    s32 result;
    while (true) {
        s32 count = ((s32 (*)(Object*))object->vtable[12])(object);
        u8* entry = data + index;
        s32 current = index;
        result = 1;
        index = index + 1;
        if (current < count) {
            if ((*entry & 4) != 0) {
                break;
            }
        } else {
            result = 0;
            break;
        }
    }
    return result;
}
