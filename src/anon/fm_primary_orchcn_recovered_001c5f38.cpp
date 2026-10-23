#include "../common/types.h"
extern "C" u8 D_00351680[];
extern "C" void func_001c5e88();

u32 func_001c5f38(u8* object) {
    u8* table = D_00351680;
    // why: forces the table address to be formed before the indexed load
    asm("" : "+r"(table), "+r"(object));
    s32 count = *(s32*)(table + object[0x52] * 32 + 20);
    u32 result = 0;
    if (count > 0) {
        func_001c5e88();
        result = 1;
    }
    return result;
}
