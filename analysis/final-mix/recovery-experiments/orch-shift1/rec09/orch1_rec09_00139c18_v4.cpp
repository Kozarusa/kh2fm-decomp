#include "../common/types.h"
struct Object;
typedef void (*Method)(Object*);
struct Object {
    Method* vtable;
    u8 pad[20];
    Method* subVtable;
};
extern "C" u32 func_00139d78(...);

u32 func_00139c18(Object* object) {
    if (func_00139d78(object) != 0) {
        object->vtable[5](object);
        return 1;
    }
    Object* sub = (Object*)&object->subVtable;
    if (func_00139d78(sub) != 0) {
        object->subVtable[5](sub);
    }
    return 0;
}
