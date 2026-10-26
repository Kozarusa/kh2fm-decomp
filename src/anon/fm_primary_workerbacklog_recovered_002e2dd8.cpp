#include "../common/types.h"
struct Object { u8 pad[272]; u32 count; };
extern "C" Object* D_00361f60;
extern "C" void func_002ceb08(void);

u32 func_002e2dd8(void)
{
    Object* object = D_00361f60;
    if (object != 0) {
        func_002ceb08();
    }
    return object->count > 0;
}
