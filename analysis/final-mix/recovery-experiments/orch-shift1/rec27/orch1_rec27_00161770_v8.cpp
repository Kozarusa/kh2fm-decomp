#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" void func_001447e0(u8* box, void* min, void* max);

typedef void (*BoundsFn)(u8* self, void* min, void* max);

void func_00161770(u8* object) {
    Quad bounds[2];
    // why: original keeps the box pointer in s0 and the maximum pointer in s1
    register u8* box asm("$16") = object + 0x54;
    register Quad* maxp asm("$17") = &bounds[1];
    asm("" : "+r"(box), "+r"(maxp));
    u8* provider = *(u8**)(object + 0x48);
    u8* table = *(u8**)provider;
    (*(BoundsFn*)(table + 0x14))(provider, &bounds[0], maxp);
    // why: forces the maximum argument to be re-set before the box argument
    asm("" : "+r"(maxp));
    func_001447e0(box, &bounds[0], maxp);
}
