#include "../common/types.h"

struct Object;
typedef void (*Method)(Object*, u32);
struct Object { Method* vtable; };
extern "C" Object* D_01d5bb00;

void func_001dc4b8(u32 param_1) {
    Object* object = D_01d5bb00;
    object->vtable[1](object, param_1);
}
