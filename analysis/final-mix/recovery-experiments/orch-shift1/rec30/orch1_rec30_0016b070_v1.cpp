#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

void func_0016b070(u8* object, Quad* vector) {
    Quad* position = (Quad*)(object + 1360);
    if (position != vector) {
        *position = *vector;
    }
    *(u32*)(object + 2040) |= 8;
    *(f32*)(object + 1372) = *(f32*)((u8*)vector + 4);
}