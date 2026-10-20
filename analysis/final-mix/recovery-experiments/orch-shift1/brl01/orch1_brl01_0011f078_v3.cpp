#include "../common/types.h"
struct Object {
    void** vtable;
};

s32 func_0011f078(Object* object, u8* data) {
    s32 index = 0;
    s32 result;
again:
    {
        s32 count = ((s32 (*)(Object*))object->vtable[12])(object);
        result = 1;
        if (!(index < count)) {
            result = 0;
            goto done;
        }
        if ((data[index] & 4) != 0) {
            goto done;
        }
        index++;
        goto again;
    }
done:
    return result;
}
