#include "../common/types.h"
extern "C" u32 func_00256b68(s32);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
extern "C" u32 func_0028be58(...);
// why: copied from the recovered call site in src/tozawa/cmenu_jiminy.cpp; the accepted definition is void Tz::ScrollBar::Leave()
extern "C" void func_0028be18(...);
extern "C" u32 D_0035f01c;
extern "C" u32 D_0035f04c;

struct Object;
// why: the original calls slot 20 of the object's first word with the object in a0
typedef void (*ObjectMethod)(Object*);
struct Object {
    ObjectMethod* table;
};

// Preserve original registry aliases.
void func_00262208() asm("_ZN2Tz6CmItem13LeaveCategoryEv");

void func_00262208() {
    Object* object = (Object*)func_00256b68(1);
    if (func_00139d78(object)) {
        object->table[5](object);
    }
    if (func_0028acc8(D_0035f01c)) {
        func_0028abe0(D_0035f01c);
    }
    if (func_0028be58(D_0035f04c)) {
        func_0028be18(D_0035f04c);
    }
}
