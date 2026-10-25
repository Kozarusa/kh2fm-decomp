#include "../common/types.h"
extern "C" void func_001bd5b0(u8*, s32, s32);
extern "C" void func_001bd668(u8*);
extern "C" u64 func_001d4818(...);
extern "C" u64 func_001d48e8(...);

void func_001bdb70(u8* object, s32 first, s32 second, s32 third, u8* fourth) {
    func_001bd668(object);
    func_001d4818(object + 2496, first, second, third, fourth);
    func_001d48e8(object + 2496, *(s32*)(object + 2528), object + 1660);
    func_001bd5b0(object, 14, 0);
    *(u32*)(object + 32) &= ~2;
}
