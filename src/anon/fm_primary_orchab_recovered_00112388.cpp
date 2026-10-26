#include "../common/types.h"
extern "C" u8* D_00341708[];
extern "C" void func_00135d88();

void func_00112388() {
    s32 count = 1;
    func_00135d88();
    // why: folding the table local into D_00341708 + 1 compiles 4 bytes shorter (measured)
    u8** table = D_00341708;
    u8** cursor = table + 1;
    do {
        u8* entry = *cursor;
        cursor++;
        if (entry != 0) {
            u8* object = *(u8**)(entry + 0xb60);
            ((void (*)(u8*))(*(u32**)object)[9])(object);
        }
        count--;
    } while (count >= 0);
}
