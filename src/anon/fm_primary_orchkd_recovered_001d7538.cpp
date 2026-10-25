#include "../common/types.h"
extern "C" s32 D_003527e4;
// why: accepted definition is f32 func_00191b70() (auto80_199_queue.cpp); extern "C" for the isolated probe link
extern "C" f32 func_00191b70();
extern "C" u32 func_001ba158(void);
// why: accepted definition is s32 func_001a5bd0(f32 a0, u32 a1, u32 a2) (tiny_auto80_queue.cpp); extern "C" for the isolated probe link
extern "C" s32 func_001a5bd0(f32, u32, u32);
// why: accepted declaration u32 func_001d9228(u32 index) asm("_Z16ctarget_001d9228jjjj") (fm_primary_orchjg_recovered_001d9228.cpp) fails the isolated probe link (v1); same types with extern "C"
extern "C" u32 func_001d9228(u32 index);
// why: no accepted source; types derived from a0 (object) and a1 (constant 0/1) set before the jal
extern "C" void func_001d7638(u8*, s32);

void func_001d7538(u8* object, u8* target) {
    if (D_003527e4 == 0) {
        return;
    }
    f32 scale = func_00191b70();
    if (*(s32*)(func_001ba158() + 20) > 0) {
        scale = scale + scale;
    }
    for (s32 index = 0; index < 9; index++) {
        for (s32 count = 0; count < func_001a5bd0(scale, (u32)target, index); count++) {
            func_001d7638(object, 1);
        }
    }
    s32 rest = (s32)func_001d9228(0) / 2;
    if (rest > 6) {
        rest = 6;
    }
    if (rest > 0) {
        s32 left = rest;
        do {
            func_001d7638(object, 0);
        } while (--left != 0);
    }
}
