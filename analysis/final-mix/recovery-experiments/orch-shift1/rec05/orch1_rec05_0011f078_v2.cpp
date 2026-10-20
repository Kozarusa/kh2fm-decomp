#include "../common/types.h"
struct Object {
    void** vtable;
};

s32 func_0011f078(Object* object, u8* data) {
    s32 index = 0;
    while (true) {
        s32 count = ((s32 (*)(Object*))object->vtable[12])(object);
        u8* entry = data + index;
        s32 current = index;
        index = index + 1;
        if (current < count) {
            if ((*entry & 4) != 0) {
                return 1;
            }
        } else {
            return 0;
        }
    }
}
