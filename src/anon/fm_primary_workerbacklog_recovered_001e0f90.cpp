#include "../common/types.h"
struct Object { u8 pad[36]; u32 state; u32 flag; };
extern "C" void* D_00352bd0;
extern "C" u64 func_001e0cc8(void);
extern "C" void func_001e26b8(void*, u64);

void func_001e0f90(Object* object)
{
    u64 value = func_001e0cc8();
    func_001e26b8(D_00352bd0, value);
    object->flag = 0;
    object->state = 5;
}
