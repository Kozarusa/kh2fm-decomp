#include "../common/types.h"
struct Object {
    void** vtable;
};

s32 func_0011f078(Object* object, u8* data) {
    s32 result;
    for (s32 index = 0;; index++) {
        s32 count = ((s32 (*)(Object*))object->vtable[12])(object);
        result = 1;
        if (!(index < count)) {
            result = 0;
            break;
        }
        if ((data[index] & 4) != 0) {
            break;
        }
    }
    return result;
}
