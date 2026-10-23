#include "../common/types.h"
extern "C" s32 D_003527e0;
extern "C" void func_001d6a28(u8*);
extern "C" void func_0019ca20(u8*);
extern "C" void func_0013dde8(s32);
extern "C" void func_001befa8(u8*);

void func_001d69d0(u8* object) {
    func_001d6a28(object);
    func_0019ca20(object + 2752);
    if (*(s32*)(*(u8**)(object + 2804) + 1164) != 0) {
        func_0013dde8(0);
    }
    func_001befa8(object);
    *(s32*)(object + 2804) = 0;
    D_003527e0 = 0;
}
