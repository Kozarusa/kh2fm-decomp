#include "../common/types.h"
extern "C" u32 func_001050d8(...);
extern "C" u32 func_001ad0f8(...);

void func_001ad158(int object, u32 second, u32 third, u32 fourth) {
    // why: bind third to s3 and second to s4 as the original, with empty guards to keep them live
    register u32 keep_third asm("$19") = third;
    register u32 keep_second asm("$20") = second;
    asm("" : "+r"(keep_third));
    asm("" : "+r"(keep_second));
    // why: bind fourth to s1 and the allocation result to s0 as the original does
    register u32 keep_fourth asm("$17") = fourth;
    asm("" : "+r"(keep_fourth));
    register u32 result asm("$16");

    result = func_001050d8(0xb6c); asm volatile("" ::: "memory");
    func_001ad0f8(result, keep_fourth, 0); asm volatile("" ::: "memory");
    *(int *)(object + 0x4a8) = (int)result;
    *(u32 *)(result + 4) = keep_second;
    *(u32 *)(result + 8) = keep_third;
}
