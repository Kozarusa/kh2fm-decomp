#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" void func_001447e0(u8* box, void* min, void* max);

typedef void (*BoundsFn)(u8* self, void* min, void* max);

void func_00161770(u8* object) {
    Quad bounds[2];
    u8* box = object + 0x54;
    u8* provider = *(u8**)(object + 0x48);
    u8* table = *(u8**)provider;
    Quad* maxp = &bounds[1];
    // why: keeps the maximum pointer in a saved register across the call
    asm("" : "+r"(maxp));
    (*(BoundsFn*)(table + 0x14))(provider, &bounds[0], maxp);
    func_001447e0(box, &bounds[0], maxp);
}
