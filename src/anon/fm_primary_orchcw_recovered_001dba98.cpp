#include "../common/types.h"
struct Object {
    s32* table;
    u8 pad[0x9f4];
    s32 count;
};

void func_001dba98(Object* object) {
    s32 value = object->count - 1;
    object->count = value;
    if (value == 0) {
        ((void (*)(Object*))object->table[8])(object);
    }
}
