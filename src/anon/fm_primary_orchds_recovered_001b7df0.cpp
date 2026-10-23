#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 func_0019bb98(u8*);
extern "C" u8* func_001b7998(s32* list, s32 key);
extern "C" void func_0018a7d0(u8*, s32, Quad*);

void func_001b7df0(s32* object, s32 key) {
    Quad temporary;
    if (func_0019bb98(*(u8**)((u8*)object + 4)) == 0) {
        u8* entry = func_001b7998(object, key);
        if (entry != 0) {
            func_0018a7d0(entry, key, &temporary);
            u8* base = *(u8**)((u8*)object + 4);
            // why: the original computes the destination in numeric register 15.
            register u8* destination asm("$15") = base + 0x870;
            asm("" : "+r"(destination)); // why: retain the computed destination as one opaque register value for the VU memory operand.
            // why: accepted 00163210 supplies this exact four-operation VU subtraction prefix, which ordinary C++ cannot express.
            asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,%2; vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,%0" : "=m"(*(Quad*)destination) : "r"(destination), "m"(temporary) : "memory");
        }
    }
}
