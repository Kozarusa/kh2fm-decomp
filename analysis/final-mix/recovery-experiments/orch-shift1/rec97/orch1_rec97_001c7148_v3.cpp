#include "../common/types.h"
struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16)));
struct Owner {
    f32 a;
    f32 b;
};
struct Source {
    Vec first;
    u8 pad0[0x20];
    Vec second;
    u8 pad1[0xc];
    Owner* owner;
};
struct Dest {
    Vec first;
    Vec second;
};
extern "C" Dest D_01d498d0;
extern "C" f32 D_0036df90;
extern "C" u64 func_00143928(...);

void func_001c7148(Source* source) {
    if ((u8*)source != (u8*)&D_01d498d0) {
        D_01d498d0.first = source->first;
    }
    D_01d498d0.first.y = D_01d498d0.first.y + source->owner->b;
    D_01d498d0.first.w = D_0036df90;
    if (&source->second != &D_01d498d0.second) {
        D_01d498d0.second = source->second;
    }
    D_01d498d0.second.w = D_0036df90;
    func_00143928(&D_01d498d0);
}