#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 func_0010fa28(s32);
extern "C" s32 func_0010fa58(s32);
extern "C" u32 func_00110618(s32);

s32 func_002f0b60(s32* owner) {
    register s32 object asm("$16") = *(s32*)(*owner + 4); // why: original keeps the object in s0
    Quad* first = (Quad*)(object + 0x10);
    func_00110618(object);
    s32 source = func_0010fa28(object);
    if ((s32)first != source) {
        // why: original copies the quad with lq/sq through t0
        asm volatile("lq $8,0(%1); sq $8,0(%0)"
                     : : "r"(first), "r"(source) : "$8", "memory");
    }
    Quad* second = (Quad*)(object + 0x20);
    source = func_0010fa58(object);
    if ((s32)second != source) {
        // why: original copies the quad with lq/sq through t0
        asm volatile("lq $8,0(%1); sq $8,0(%0)"
                     : : "r"(second), "r"(source) : "$8", "memory");
    }
    return source;
}
