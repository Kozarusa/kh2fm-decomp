#include "../common/types.h"
struct Object;
typedef void (*Method)(Object*);
struct Object {
    Method* vtable;
    u8 pad[20];
    Object* sub() { return (Object*)((u8*)this + 24); }
};
extern "C" u32 func_00139d78(...);

u32 func_00139c18(Object* object) {
    if (func_00139d78(object) != 0) {
        object->vtable[5](object);
        return 1;
    }
    if (func_00139d78(object->sub()) != 0) {
        object->sub()->vtable[5](object->sub());
    }
    return 0;
}
