#include "../common/types.h"
struct VTable { u32 slot[8]; };
struct Object { VTable* vtable; };
extern "C" Object* D_0034a6f0;

void func_00153100() {
    Object* object = D_0034a6f0;
    if (object != 0) {
        ((void (*)(Object*))object->vtable->slot[4])(object);
        D_0034a6f0 = 0;
    }
}
