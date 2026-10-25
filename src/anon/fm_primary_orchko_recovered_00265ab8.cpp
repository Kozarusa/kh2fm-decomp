#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00139510(...);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_0028abe0(u32);
extern "C" u32 D_0035f01c;
extern "C" u32 D_0035f020;

struct Object;
// why: the original calls slot 20 of the object's first word with the object in a0
typedef void (*ObjectMethod)(Object*);
struct Object {
    ObjectMethod* table;
};

u32 func_00265ab8() {
    u32 base = func_00257770();
    if (func_00139d78(base)) {
        func_00139510(base);
    }
    u32 entry = base;
    s32 count = 19;
    do {
        Object* object = (Object*)(entry + 0x5ef0);
        if (func_00139d78(object)) {
            object->table[5](object);
        }
        count--;
        entry += 0x1b4;
    } while (count >= 0);
    if (func_0028acc8(D_0035f01c)) {
        func_0028abe0(D_0035f01c);
    }
    u32 result = func_0028acc8(D_0035f020);
    if (result) {
        return func_0028abe0(D_0035f020);
    }
    return result;
}
