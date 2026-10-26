#include "../common/types.h"
struct Object;
// why: the method pointer returns s32 (result unused); with a void return the compiler picks t7 instead of v0 for the call target
typedef s32 (*Method)(Object*, u32, u32);
struct Object { Method* vtable; };
extern "C" Object* D_01d9e340;
void func_001de948(u32 value) {
    Object* object = D_01d9e340;
    Method method = object->vtable[0];
    method(object, value, 0);
}
