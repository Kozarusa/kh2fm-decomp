#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
typedef s32 (*Method)(void*);
struct Object { Method* table; };
extern "C" u8 D_0034aa70[];
extern "C" f32 D_0036b3a0;
extern "C" Quad* func_001904a8(Quad* result, const void* source);
extern "C" u32 func_00167f18(s32);
extern "C" void func_0015a260(u8*, Quad*, f32);
extern "C" void func_0015a158(u32, u8*);
extern "C" s32 func_0015a528(u8*);

s32 func_0015a5a8(u8* object) {
    Quad buffer;
    func_001904a8(&buffer, D_0034aa70);
    const f32* speed = &D_0036b3a0;
    asm("" : "+r"(speed)); // why: original forms the full address before the lwc1
    func_0015a260(object, &buffer, *speed);
    u32 state = func_00167f18(0);
    Object* owner = *(Object**)(object + 68);
    if (owner->table[16](owner) != 0) {
        func_0015a158(state, object);
    }
    return func_0015a528(object);
}
