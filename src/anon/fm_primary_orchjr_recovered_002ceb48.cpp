#include "../common/types.h"
struct Object;
typedef void (*ObjectMethod)(Object*);
struct ObjectVtable {
    ObjectMethod first;
    ObjectMethod release;
};
struct Object {
    ObjectVtable* vtable;
    u8 pad[0x5c];
    u32 buffer;
};
extern "C" Object* D_00361f60;
extern "C" u32 func_00170950(...);

void func_002ceb48(void) {
    Object* object = D_00361f60;
    if (object != 0) {
        if (object->buffer != 0) {
            func_00170950(object->buffer);
            *(volatile u32*)&D_00361f60->buffer = 0;
            object = *(Object* volatile*)&D_00361f60;
        }
        if (object != 0) {
            object->vtable->release(object);
        }
        D_00361f60 = 0;
    }
}
