#include "../common/types.h"
extern "C" u8* D_01d49320;
extern "C" u32 D_0034f240;
extern "C" void func_0014ca20();
extern "C" void func_001d6c58();
extern "C" void func_001c11a8(s32);
extern "C" void func_001c1130(s32);
extern "C" void func_001af9f8();

void func_001bb890(void) {
    *(u32*)(D_01d49320 + 4) = *(u32*)(D_01d49320 + 4) | 4;
    *(u32*)(D_01d49320 + 4) = *(u32*)(D_01d49320 + 4) | 0x10;
    func_0014ca20();
    D_0034f240 = D_0034f240 | 2;
    func_001d6c58();
    func_001c11a8(8);
    func_001c1130(5);
    func_001af9f8();
}