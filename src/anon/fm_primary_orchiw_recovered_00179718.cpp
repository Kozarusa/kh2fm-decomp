#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" f32 D_0036c4dc;
extern "C" f32 D_00349e10;
extern "C" s32 func_0015ef18();
extern "C" u32 func_0015ef28();
extern "C" u32 func_001dc9d0(u32);
extern "C" void func_001dc920(u32);
extern "C" s32 func_001de2e0(u32, s32);
extern "C" u32 func_001de168(u32, s32, s32, s32, s32, s32);
extern "C" kn::FVector func_00143e50(u16, s32);
extern "C" kn::FVector* func_001dc5f8(u32);
extern "C" kn::FVector* func_001dc648(u32);
extern "C" kn::FVector func_0017d050(const kn::FVector*);

void func_00179718(u8* object) {
    if (func_0015ef18() == 0) {
        return;
    }
    if (*(u32*)(object + 2900) != 0 && func_001dc9d0(*(u32*)(object + 2900)) == 0) {
        func_001dc920(*(u32*)(object + 2900));
        *(u32*)(object + 2900) = 0;
    }
    u32 id = *(u16*)(object + 1522);
    if (id != 0xffff) {
        if (*(u32*)(object + 2900) == 0 && id != *(s32*)(object + 2904)) {
            s32 index = func_001de2e0(func_0015ef28(), 1);
            if (index >= 0) {
                u32 effect = func_001de168(func_0015ef28(), index, 0, 2, 40000, 0);
                *(u32*)(object + 2900) = effect;
                if (effect != 0) {
                    kn::FVector normal = func_00143e50(id, 0);
                    *func_001dc5f8(*(u32*)(object + 2900)) = *(kn::FVector*)(object + 1488);
                    kn::FVector* angle = func_001dc648(*(u32*)(object + 2900));
                    *angle = func_0017d050(&normal);
                }
            }
            u32 current = *(u16*)(object + 1522);
            *(s32*)(object + 2904) = current;
            (*(void (**)(u8*, u32))(*(u8**)object + 148))(object, current);
        }
        const f32* reset = &D_0036c4dc;
        asm("" : "+r"(reset)); // why: original forms the full address before the lwc1
        *(f32*)(object + 2908) = *reset;
    } else {
        f32 timer = *(f32*)(object + 2908);
        if (timer > 0.0f) {
            f32 remaining = timer - D_00349e10;
            *(f32*)(object + 2908) = remaining;
            if (remaining <= 0.0f) {
                *(s32*)(object + 2904) = id;
            }
        }
    }
}
