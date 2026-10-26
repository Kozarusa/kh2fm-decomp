#include "../common/types.h"

struct Object;
typedef void (*Method)(Object*, u32);
struct Object { Method* vtable; };
extern "C" Object* D_0034dc98;

void func_0016fb00(u32 param_1) {
    Object* object = D_0034dc98;
    object->vtable[1](object, param_1);
}
