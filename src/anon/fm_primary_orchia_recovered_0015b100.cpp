#include "../common/types.h"
struct Object;
struct VTable {
    u8 pad[16];
    void (*release)(Object*);
};
struct Object {
    VTable* vtable;
};
extern "C" Object* D_0034aaa8;
extern "C" Object* D_0034aaa4;
extern "C" Object* D_0034aa9c;
extern "C" Object* D_0034aaa0;

// Preserve original registry aliases.
void func_0015b100() asm("_Z13func_0015b100Pv");

void func_0015b100() {
    if (D_0034aaa8 != 0) {
        D_0034aaa8->vtable->release(D_0034aaa8);
        D_0034aaa8 = 0;
    }
    if (D_0034aaa4 != 0) {
        D_0034aaa4->vtable->release(D_0034aaa4);
        D_0034aaa4 = 0;
    }
    if (D_0034aa9c != 0) {
        D_0034aa9c->vtable->release(D_0034aa9c);
        D_0034aa9c = 0;
    }
    if (D_0034aaa0 != 0) {
        D_0034aaa0->vtable->release(D_0034aaa0);
        D_0034aaa0 = 0;
    }
}
