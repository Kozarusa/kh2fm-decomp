#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 func_001447e0(u8* box, void* min, void* max);

typedef void (*BoundsFn)(u8* self, void* min, void* max);

s32 func_00161770(u8* object) {
    Quad bounds[2];
    register u8* box asm("$16") = object + 0x54; // why: original keeps the box pointer in s0
    register Quad* maxp asm("$17") = &bounds[1]; // why: original keeps the maximum pointer in s1
    asm("" : "+r"(box), "+r"(maxp)); // why: computes box and maximum pointer before the first call
    u8* provider = *(u8**)(object + 0x48);
    u8* table = *(u8**)provider;
    (*(BoundsFn*)(table + 0x14))(provider, &bounds[0], maxp);
    register Quad* maxArg asm("$6") = maxp; // why: original loads a2 before a0 for the second call
    register u8* boxArg asm("$4") = box; // why: original loads a0 after a2 for the second call
    return func_001447e0(boxArg, &bounds[0], maxArg);
}
