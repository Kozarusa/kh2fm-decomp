#include "../common/types.h"
struct Object;
struct VTable {
    u8 pad[4];
    void (*destroy)(Object*);
    u8 pad2[8];
    void (*release)(Object*);
};
struct Object {
    VTable* vtable;
};
extern "C" s16 D_0035f280;
extern "C" s32 D_0035f274;
extern "C" u8 D_0035f299;
extern "C" s32 D_0035f270;
extern "C" s32 D_0035f278;
extern "C" s32 D_0035f27c;
extern "C" s32 D_0035f284;
extern "C" Object* D_0035f288;
extern "C" Object* D_0035f290;
extern "C" Object* D_0035f29c;

// why: void per DEVIATIONS #36; exits leave either the untouched entry v0 or an indirect-call v0

void func_002816f0() {
    s32 none = -1;
    // why: keeps store order (the scheduler emits the last -1 store first)
    D_0035f274 = none;
    D_0035f270 = none;
    D_0035f278 = none;
    D_0035f27c = none;
    D_0035f280 = none;
    D_0035f299 = 1;
    D_0035f284 = 0;
    if (D_0035f288 != 0) {
        D_0035f288->vtable->release(D_0035f288);
        D_0035f288 = 0;
    }
    if (D_0035f290 != 0) {
        D_0035f290->vtable->release(D_0035f290);
        D_0035f290 = 0;
    }
    if (D_0035f29c != 0) {
        D_0035f29c->vtable->destroy(D_0035f29c);
        D_0035f29c = 0;
    }
}
