#include "../common/types.h"
extern "C" u32 func_001e7070(u32, u32);
extern "C" u32 func_001e7088(u32, u32);

void func_001dca70(s32* object) {
    u32 first = 0;
    u32 second;
    if (object[2] & 0x40000) {
        first = object[12];
        second = object[13];
    } else {
        second = 0;
    }
    func_001e7070(first, second);
    u32 third = 0;
    u32 fourth;
    u32 flags = object[2];
    if (flags & 0x80000) {
        fourth = object[13];
        third = object[12];
    } else {
        fourth = 0;
    }
    func_001e7088(third, fourth);
}