#include "../common/types.h"
struct State {
    u8 first;
    u8 second;
    u8 third;
    u8 level;
    f32 x;
    f32 y;
    f32 width;
    f32 height;
    u8 pad[68];
};
extern "C" f32 D_0036b3fc;
extern "C" State D_004f3694;
extern "C" State D_004f36ec;
extern "C" State D_004f3744;

// Preserve original registry aliases.
void func_0015ccf0(s32 kind, s64 mode) asm("_Z16wtarget_0015ccf0jjjj");

void func_0015ccf0(s32 kind, s64 mode) {
    if (mode == 0xffff && kind == 1) {
        register f32* source asm("$14") = &D_0036b3fc; // why: original holds this address in t6
        asm("" : "+r"(source)); // why: original forms the address of D_0036b3fc before loading it
        f32 height = *source;
        D_004f3694.width = 0.0f;
        D_004f3694.height = height;
    }
    if (mode == 0xffff && kind == 1) {
        register f32* source asm("$14") = &D_0036b3fc; // why: original holds this address in t6
        asm("" : "+r"(source)); // why: original forms the address of D_0036b3fc before loading it
        f32 height = *source;
        D_004f36ec.width = 0.0f;
        D_004f36ec.height = height;
    }
    if (mode == 0xffff && kind == 1) {
        register f32* source asm("$14") = &D_0036b3fc; // why: original holds this address in t6
        asm("" : "+r"(source)); // why: original forms the address of D_0036b3fc before loading it
        f32 height = *source;
        D_004f3744.width = 0.0f;
        D_004f3744.height = height;
    }
}
