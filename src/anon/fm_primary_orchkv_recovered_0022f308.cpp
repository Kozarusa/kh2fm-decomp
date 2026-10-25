#include "../common/types.h"
typedef void (*Method)(s32);
// why: copied from the recovered call site in fm_primary_orchdt_recovered_0022efb8.cpp
extern "C" bool func_002282f0(...);
// why: copied from the recovered call site in fm_primary_orchdt_recovered_0022efb8.cpp
extern "C" u32 func_00227d10(...);
// why: copied from the recovered call site in fm_primary_orchjb_recovered_001b5cf8.cpp, which uses the result
extern "C" u32 func_001ba028(...);
// why: copied from the recovered call sites in fm_primary_orchcm_recovered_001c1060.cpp
extern "C" bool func_001c0cd8(s32);
extern "C" void func_001c0e60(s32);
// why: matches the accepted void definition in fm_primary_orchjh_recovered_00232db0.cpp; extern "C" because the isolated probe linker script defines only the plain symbol (lg376 0022d440 v1 C++ declaration failed to link)
extern "C" void func_00232db0(s32 value);
// why: copied from the recovered call site in fm_primary_orchiy_recovered_00182b18.cpp, which uses the result
extern "C" u32 func_00102c18(u32, u32, u32);
extern "C" u8 D_00227950[];

u32 func_0022f308(u8* object) {
    u32 result = func_002282f0(*(s16*)(object + 4));
    if (result != 0) return result;
    u8* entry = (u8*)func_00227d10(*(s16*)(object + 6));
    func_001ba028(*(s32*)(entry + 8));
    if (func_001c0cd8(*(s32*)(entry + 8))) {
        func_001c0e60(*(s32*)(entry + 8));
    }
    s32 self = *(s32*)(entry + 8);
    (*(Method*)(*(s32*)self + 40))(self);
    *(s32*)(entry + 8) = 0;
    asm volatile("" ::: "memory"); // why: keeps store order (original clears the slot before loading the call argument)
    func_00232db0(*(s16*)(object + 6));
    result = func_00102c18(1, 0xa7ee, (u32)D_00227950);
    *(s32*)(result + 4) = *(s16*)(object + 6);
    return result;
}
