#include "../common/types.h"
struct Object;
typedef void (*Method)(Object*);
struct Object {
    Method* vtable;
};
extern "C" u32 func_00139d78(...);

u32 func_00139c18(Object* object) {
    u32 result;
    if (func_00139d78(object) != 0) {
        object->vtable[5](object);
        result = 1;
    } else {
        Object* sub = (Object*)((u8*)object + 24);
        if (func_00139d78(sub) != 0) {
            sub->vtable[5](sub);
        }
        result = 0;
    }
    return result;
}
