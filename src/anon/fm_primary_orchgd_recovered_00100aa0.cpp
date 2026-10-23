#include "../common/types.h"
struct Object {
    u8 pad[16];
    u64 low : 3;
    u64 kind : 8;
    u64 rest : 53;
};
extern "C" u32 func_001004c0(...);
extern "C" u32 func_00100920(...);

s32 func_00100aa0(Object* object, u8* left, u8* right) {
    u32 values[2];
    u32 table;
    table = func_00100920((u8)object->kind, object);
    func_001004c0((u8)object->kind, table, left + 8, &values[0]);
    func_001004c0((u8)object->kind, table, right + 8, &values[1]);
    if (values[0] > values[1]) {
        return 1;
    }
    if (values[1] > values[0]) {
        return -1;
    }
    return 0;
}
