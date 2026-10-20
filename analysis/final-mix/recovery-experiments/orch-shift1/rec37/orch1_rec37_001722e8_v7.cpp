#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Target {
    u8 pad0[0x100];
    s32 first;
    s32 second;
};
struct Inner {
    u32 pad0;
    Target* target;
};
struct Holder {
    Inner* inner;
    Quad* source;
    s32 base;
    f32 scale;
    s32 enabled;
};
extern "C" void func_001b6dd0(Target*, Quad*);
extern "C" void func_0017f488(s32, s32, f32, f32);

void func_001722e8(Holder* holder) {
    Target* target = holder->inner->target;
    Quad copy = *(volatile Quad*)holder->source;
    func_001b6dd0(target, &copy);
    func_0017f488((s32)target + 0x140, holder->base, holder->scale, 0.0f);
    if (holder->enabled != 0) {
        s32 base = holder->base;
        target->first = base + 1;
        target->second = base + 2;
    }
}