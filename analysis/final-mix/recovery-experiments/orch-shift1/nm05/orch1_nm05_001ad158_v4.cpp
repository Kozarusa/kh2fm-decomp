#include "../common/types.h"
extern "C" u32 func_001050d8(...);
extern "C" u32 func_001ad0f8(...);

void func_001ad158(int object, u32 second, u32 third, u32 fourth) {
    // why: bind third to s3 and second to s4 as the original, with empty guards to keep them live
    register u32 keep_third asm("$19") = third;
    register u32 keep_second asm("$20") = second;
    asm("" : "+r"(keep_third));
    asm("" : "+r"(keep_second));
    u32 result;
    int pointer;

    result = func_001050d8(0xb6c);
    func_001ad0f8(result, fourth, 0); asm volatile("" ::: "memory");
    pointer = (int)result;
    *(int *)(object + 0x4a8) = pointer;
    *(u32 *)(pointer + 4) = keep_second;
    *(u32 *)(pointer + 8) = keep_third;
}
