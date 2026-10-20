#include "../common/types.h"
struct Object {
    void* table;
    u8 pad0[1412];
    u32 flags;
    u8 pad1[1328];
    u32 mode;
};
extern "C" void func_001d7cd0(Object*, u64, u64);
extern "C" u8 D_00351468[];

void func_001c2ce8(Object* object, u64 second, u64 third)
{
    func_001d7cd0(object, second, third);
    object->flags |= 0x200000;
    object->table = D_00351468;
    object->mode |= 4;
}
