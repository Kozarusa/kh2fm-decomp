#include "../common/types.h"
struct Object;
// why: the method pointer returns s32 (result unused); with a void return the compiler picks t7 instead of v0 for the call target
typedef s32 (*Method)(Object*, u32, u32);
struct Object { Method* vtable; };
extern "C" Object* D_0035f3f8;
void func_0028cc08(u32 value) {
    Object* object = D_0035f3f8;
    Method method = object->vtable[0];
    method(object, value, (u32)__builtin_return_address(0));
}
