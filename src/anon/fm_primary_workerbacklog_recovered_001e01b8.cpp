#include "../common/types.h"

struct Object;
typedef void (*Method)(Object*, u32);
struct Object { Method* vtable; };
extern "C" Object* D_01d9e340;

void func_001e01b8(u32 param_1) {
    Object* object = D_01d9e340;
    object->vtable[1](object, param_1);
}
