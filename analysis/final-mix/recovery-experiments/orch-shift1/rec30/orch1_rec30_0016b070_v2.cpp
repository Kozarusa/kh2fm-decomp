#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_0016b070(u8* object, Quad* vector) {
    Quad* position = (Quad*)(object + 1360);
    u32 flags;
    if (position != vector) {
        *position = *vector;
    }
    flags = *(u32*)(object + 2040);
    f32 w = *(f32*)((u8*)vector + 4);
    *(u32*)(object + 2040) = flags | 8;
    *(f32*)(object + 1372) = w;
}