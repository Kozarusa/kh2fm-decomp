#include "../common/types.h"
struct Object;
typedef void (*Method)(Object*);
struct Object {
    Method* table;
};
extern "C" u32 D_0035f10c;
extern "C" u32 D_0035f104;
extern "C" u32 D_0035f110;
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
extern "C" s32 func_00139d78(u32);
// why: one argument in a0, result tested with beqz; accepted declarations are only varargs placeholders
extern "C" u32 func_0028d6e8(u32);
// why: its tail chain ends in func_0023d820, declared void at accepted call sites, whose v0 is never a set result
extern "C" void func_0026e340();

void func_0026ebc0() {
    if (func_0028acc8(D_0035f10c) != 0) {
        func_0028abe0(D_0035f10c);
    }
    for (s32 index = 0; index < 3; index++) {
        if (func_00139d78(D_0035f104 + index * 436) != 0) {
            Object* object = (Object*)(index * 436 + D_0035f104);
            object->table[5](object);
        }
    }
    if (func_0028d6e8(D_0035f110) != 0) {
        Object* object = (Object*)D_0035f110;
        object->table[5](object);
    }
    func_0026e340();
}
