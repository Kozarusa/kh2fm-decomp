#include "../common/types.h"
struct Object {
    void** vtable;
};

s32 func_0011f078(Object* object, u8* data) {
    s32 index = 0;
    while (index < ((s32 (*)(Object*))object->vtable[12])(object)) {
        if ((data[index++] & 4) != 0) {
            return 1;
        }
    }
    return 0;
}
