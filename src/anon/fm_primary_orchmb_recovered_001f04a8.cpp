#include "../common/types.h"

struct Manager {
    u8 pad[168];
    u64 flags;
};

struct Emitter {
    s32 id;
    u8 pad0[8];
    f32 delta[5];
};

struct Source {
    u8 pad0[12];
    u8* entry;
};

extern "C" s32 D_01d9ea9c;
extern "C" Manager* D_01d9e6e0;
extern "C" s32 D_01d9eab4;
extern "C" void func_001f0430(Emitter* emitter, f32* state);
extern "C" f32 func_002f8b00(f32, f32);

void func_001f04a8(u8* base, Emitter* emitter, Source* source) {
    f32* state = (f32*)(base + *(s32*)(source->entry + 8) + 160);
    if (*(s32*)state == 0) {
        func_001f0430(emitter, state);
    }
    if (D_01d9ea9c != 0) {
        return;
    }
    if ((D_01d9e6e0->flags & 0xff0000ff00ULL) != 0) {
        return;
    }
    if (emitter->id == *(s32*)(base + 12)) {
        state[2] += emitter->delta[0];
        state[3] += emitter->delta[1];
        state[5] += emitter->delta[3];
        state[6] += emitter->delta[4];
    }
    if (D_01d9eab4 != 0) {
        return;
    }
    state[2] = state[2] + state[3];
    state[1] = state[1] + state[2];
    state[5] = state[5] + state[6];
    state[4] = state[4] + state[5];
    state[1] = func_002f8b00(state[1], 32768.0f);
    state[4] = func_002f8b00(state[4], 32768.0f);
}
