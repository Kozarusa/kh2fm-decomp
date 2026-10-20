#include "../common/types.h"
extern "C" u8* D_004f3b38;
extern "C" void func_00160488(u8* object, u32 red, u32 green, u32 blue);

void func_001611a8(u8 red, u8 green, u8 blue) {
    u8* node = 0;
    u8* next;
    // why: branch hint makes the compiler fill the delay slot from the taken arm
    while ((next = __builtin_expect(node == 0, 0) ? D_004f3b38 : *(u8**)(node + 0x80)), node = next, next != 0) {
        func_00160488(next, red, green, blue);
    }
}