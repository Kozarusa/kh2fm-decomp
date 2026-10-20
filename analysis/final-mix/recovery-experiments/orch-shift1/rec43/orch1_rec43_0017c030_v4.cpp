#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Vec { Quad q; };
struct Obj { u8 pad[0x10]; Vec vec; u8 rest[0xe8]; u32 flags; };
extern "C" f32 func_0016c460(Obj*, s32);

Vec* func_0017c030(Vec* destination, Obj* object, s32 argument, u8 flag) {
    if (destination != &object->vec) {
        *destination = object->vec;
    }
    ((f32*)destination)[1] = func_0016c460(object, argument);
    if (flag != 0) {
        object->flags = object->flags | 0x10000;
    }
    return destination;
}