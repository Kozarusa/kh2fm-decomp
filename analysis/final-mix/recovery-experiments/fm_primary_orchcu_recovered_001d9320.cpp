#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u32 func_001bbcb0(void);

struct Vtable {
    u32 pad[3];
    void (*fn)(void*);
};
struct Object {
    Vtable* vtable;
};

void func_001d9320(u32 index) {
    u32 base = func_001bbcb0() + (index << 6);
    Object* object = (Object*)(base + 608);
    if (func_001bb4a0()) {
        u32 flags = *(u32*)(base + 620);
        u8 flag = flags & 1;
        if (flag) {
            if (!(flags & 8)) {
                object->vtable->fn(object);
            }
        }
    }
}
