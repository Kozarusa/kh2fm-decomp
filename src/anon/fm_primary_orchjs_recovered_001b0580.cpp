#include "../common/types.h"
#include "../kn/fvector.hpp"

struct Info {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    u64 id : 16;
    u64 flag : 1;
};

struct Source {
    s32 unused0;
    s32 type;
    s32 unused8;
    u16 id;
    u16 unusedE;
    f32 value;
    s32 unused14[3];
    kn::FVector color;
};

extern "C" s8 D_01c940c0;
extern "C" Info D_01c940d0;
extern "C" u8 D_001b13d0[];
extern "C" f32 D_0036d960;
extern "C" f32 D_0036d964;
extern "C" f32 D_0036d968;
extern "C" void func_002fd188(u8*);
extern "C" s32 func_001b0498(Source*);
extern "C" f32 func_002f87c0(f32);

Info* func_001b0580(Source* source) {
    if (D_01c940c0 == 0) {
        D_01c940c0 = 1;
        func_002fd188(D_001b13d0);
    }
    if (func_001b0498(source) == 0) return 0;
    switch (source->type) {
    case 0:
        return 0;
    case 1:
    case 2: {
        *(kn::FVector*)&D_01c940d0 = source->color;
        f32 value = source->value;
        f32* scale = &D_0036d960;
        asm volatile("" : "+r"(scale)); // why: original materializes the constant address before the lwc1
        f32 angle = func_002f87c0(value * *scale);
        f32* base = &D_0036d964;
        asm volatile("" : "+r"(base)); // why: original materializes the constant address before the lwc1
        f32 difference = *base - angle;
        asm volatile("" : "+f"(difference)); // why: original subtracts before materializing the next constant address
        f32* factor = &D_0036d968;
        asm volatile("" : "+r"(factor)); // why: original materializes the constant address before the lwc1
        D_01c940d0.w = difference * *factor;
        asm volatile("" ::: "memory"); // why: keeps store order
        D_01c940d0.id = source->id;
        D_01c940d0.flag = 0;
        break;
    }
    case 3: {
        *(kn::FVector*)&D_01c940d0 = source->color;
        f32 value = source->value;
        f32* scale = &D_0036d960;
        asm volatile("" : "+r"(scale)); // why: original materializes the constant address before the lwc1
        f32 angle = func_002f87c0(value * *scale);
        f32* base = &D_0036d964;
        asm volatile("" : "+r"(base)); // why: original materializes the constant address before the lwc1
        f32 difference = *base - angle;
        asm volatile("" : "+f"(difference)); // why: original subtracts before materializing the next constant address
        f32* factor = &D_0036d968;
        asm volatile("" : "+r"(factor)); // why: original materializes the constant address before the lwc1
        D_01c940d0.w = difference * *factor;
        asm volatile("" ::: "memory"); // why: keeps store order
        D_01c940d0.id = source->id;
        D_01c940d0.flag = 1;
        break;
    }
    }
    return &D_01c940d0;
}
