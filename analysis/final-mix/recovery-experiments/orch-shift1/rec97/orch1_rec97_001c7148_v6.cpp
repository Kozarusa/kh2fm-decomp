#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Owner {
    f32 a;
    f32 b;
};
struct Source {
    kn::FVector first;
    u8 pad0[0x20];
    kn::FVector second;
    u8 pad1[0xc];
    Owner* owner;
};
struct Dest {
    kn::FVector first;
    kn::FVector second;
};
extern "C" Dest D_01d498d0;
extern "C" f32 D_0036df90;
extern "C" u64 func_00143928(...);

void func_001c7148(Source* source) {
    Dest* dest = &D_01d498d0;
    dest->first = source->first;
    *(f32*)&dest->first.y = *(f32*)&dest->first.y + source->owner->b;
    *(f32*)&dest->first.w = D_0036df90;
    dest->second = source->second;
    *(f32*)&dest->second.w = D_0036df90;
    func_00143928(dest);
}