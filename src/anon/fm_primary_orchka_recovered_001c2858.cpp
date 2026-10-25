#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

struct Grid {
    Quad origin;
    union {
        Quad extent;
        f32 size[4];
    };
    f32 stepX;
    f32 pad0;
    f32 stepZ;
    f32 pad1;
    s32 countX;
    s32 countZ;
    s32 zero0;
    s32 zero1;
};

void func_001c2858(Grid* grid, Quad* origin, Quad* extent, s32 total) {
    // why: aligned 128-bit copy through t0 (plain Quad copy failed in v1), primitive from accepted fm_copy_helpers.cpp
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(&grid->origin), "r"(origin) : "$8", "memory");
    // why: second aligned 128-bit copy through t0, same primitive
    asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(&grid->extent), "r"(extent) : "$8", "memory");
    f32 depth = grid->size[2];
    f32 width = grid->size[0];
    f32 ratio = depth / width;
    grid->zero0 = 0;
    grid->zero1 = 0;
    f32 root = __builtin_sqrtf((f32)total / ratio);
    s32 countX = (s32)root;
    s32 countZ = (s32)(root * ratio);
    grid->countX = countX;
    grid->countZ = countZ;
    grid->stepX = width / (f32)countX;
    grid->stepZ = depth / (f32)countZ;
}
