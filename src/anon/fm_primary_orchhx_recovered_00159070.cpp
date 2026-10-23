#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
typedef s32 (*Method)(void*);
struct Object { Method* table; };
extern "C" u8 D_0034a9f0[];
extern "C" f32 D_0036b324;
extern "C" u64 func_001b9d40(...);
extern "C" u32 func_00190140(s32);
extern "C" Quad* func_001904a8(Quad* result, const void* source);
extern "C" u32 func_00167f18(s32);
extern "C" s32 func_001591a0();
extern "C" void func_0015a260(u8*, Quad*, f32);
extern "C" void func_0015a158(u32, u8*);
extern "C" s32 func_0015a528(u8*);

s32 func_00159070(u8* object) {
    if (func_001b9d40(*(s32*)(object + 68)) != 0 || func_00190140((s32)D_0034a9f0) == 0) {
        return func_001591a0();
    }
    Quad buffer;
    func_001904a8(&buffer, D_0034a9f0);
    const f32* speed = &D_0036b324;
    asm("" : "+r"(speed)); // why: original forms the full address before the lwc1
    func_0015a260(object, &buffer, *speed);
    u32 state = func_00167f18(0);
    Object* owner = *(Object**)(object + 68);
    if (owner->table[16](owner) != 0) {
        func_0015a158(state, object);
    }
    return func_0015a528(object);
}
