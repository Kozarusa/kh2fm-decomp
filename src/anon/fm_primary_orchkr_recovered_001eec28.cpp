#include "../common/types.h"

struct Manager {
    u8 pad[168];
    u64 flags;
};

struct Emitter {
    s32 id;
    s32 index;
    s8 amount[4];
    u8 twice;
};

struct Source {
    u8 pad0[12];
    s32* offsets;
};

extern "C" s32 D_01d9ea9c;
extern "C" Manager* D_01d9e6e0;
extern "C" u8 D_01d9e360[];
// why: type copied from the accepted definition fm_primary_orchkf_recovered_001eeb90.cpp; extern "C" because the
// isolated probe linker script defines only the plain symbol func_001eeb90, so the C++ declaration in
// orch1_lg353_001eec28_v1 left the mangled name as an unresolved symbol
extern "C" f32 func_001eeb90(u8 twice);
// why: no accepted call site or definition carries this callee (only the tiny_auto80_queue.cpp placeholder);
// types derived from registers: a0 sign-extended byte (sll/sra 24 in the callee), $f12 float, v0 sign-extended byte result;
// extern "C" because the isolated probe linker script defines only the plain symbol func_001eeb60
// (the C++ declaration in orch1_lg353_001eec28_v1 left the mangled name unresolved)
extern "C" s8 func_001eeb60(s8 amount, f32 scale);

void func_001eec28(u8* base, Emitter* emitter, Source* source) {
    if (D_01d9ea9c != 0) {
        return;
    }
    if ((D_01d9e6e0->flags & 0xff0000ff00ULL) != 0) {
        return;
    }
    if (emitter->id != *(s32*)(base + 12)) {
        return;
    }
    f32* scale = (f32*)(base + source->offsets[0] + 160);
    scale[0] = func_001eeb90(emitter->twice);
    asm("" : "+r"(scale)); // why: original reads scale[0] back through the +160 pointer, not through base + offset
    scale[1] = func_001eeb90(emitter->twice);
    scale[2] = func_001eeb90(emitter->twice);
    scale[3] = func_001eeb90(emitter->twice);
    asm volatile("" ::: "memory"); // why: keeps order (scale[3] is stored before the D_01d9e360 address is formed)
    u8* target = D_01d9e360;
    asm volatile("" ::: "memory"); // why: keeps order (the D_01d9e360 address is formed before emitter->index is loaded)
    if (emitter->index != -1) {
        target = base + emitter->index + 160;
    }
    f32 value = scale[0];
    s8 delta = func_001eeb60(emitter->amount[0], value);
    s8 amount = emitter->amount[1];
    target[0] += delta;
    delta = func_001eeb60(amount, scale[1]);
    amount = emitter->amount[2];
    target[1] += delta;
    delta = func_001eeb60(amount, scale[2]);
    amount = emitter->amount[3];
    target[2] += delta;
    target[3] += func_001eeb60(amount, scale[3]);
}
