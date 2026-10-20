#include "../common/types.h"
extern "C" u32 func_001e7070(u32, u32);
extern "C" u32 func_001e7088(u32, u32);

void func_001dca70(s32* object) {
    u32 first = 0;
    u32 second;
    if ((object[2] & 0x40000) == 0) {
        second = 0;
    } else {
        first = object[12];
        second = object[13];
    }
    func_001e7070(first, second);
    first = 0;
    if ((object[2] & 0x80000) == 0) {
        second = 0;
    } else {
        second = object[13];
        first = object[12];
    }
    func_001e7088(first, second);
}