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
    Dest* dest = &D_01d498d0;
    if ((u8*)source != (u8*)dest) {
        dest->first = source->first;
    }
    dest->first.y = dest->first.y + source->owner->b;
    dest->first.w = D_0036df90;
    if (&source->second != &dest->second) {
        dest->second = source->second;
    }
    dest->second.w = D_0036df90;
    func_00143928(dest);
}