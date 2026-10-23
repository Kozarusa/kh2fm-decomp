#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

// Preserve original registry aliases.
void func_0016b070(u8* object, Quad* vector) asm("_Z16wtarget_0016b070jjjj");

void func_0016b070(u8* object, Quad* vector) {
    Quad* position = (Quad*)(object + 1360);
    // why: original copies the quad with lq t0 / sq t0 through a pointer register
    if (position != vector) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*position) : "r"(vector), "r"(position), "m"(*vector) : "$8");
    f32 w = *(f32*)((u8*)vector + 4);
    *(f32*)(object + 1372) = w;
    *(u32*)(object + 2040) |= 8;
}
