#include "../common/types.h"
struct Object {
    u8 pad0[0x12];
    u8 count;
    u8 pad1[0x21];
    u16 current[8];
    u16 ids[8];
};
extern "C" u32 func_001a34e0(u64,s64);
extern "C" s64 func_001a3570(u32);

void func_00188ac8(Object* object) {
    s32 index;
    for (index = 0; index < object->count; index++) {
        u16 id = object->ids[index];
        if (id != 0 && object->current[index] == 0) {
            if (func_001a3570(id) > 0) {
                func_001a34e0(object->ids[index], 1);
                object->current[index] = object->ids[index];
            }
        }
    }
}
