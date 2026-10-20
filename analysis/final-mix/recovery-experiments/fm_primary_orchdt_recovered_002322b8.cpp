#include "../common/types.h"
extern "C" bool func_002282f0(...);
extern "C" void func_00102c18(u32,u32,void*);
extern "C" u8 D_0035de26;
extern "C" u8 D_00232150[];

void func_002322b8(u8* object) {
    if (func_002282f0(*(u16*)(object + 4)) == 0) {
        if (*(u16*)(object + 6) == 0) {
            if (D_0035de26 == 0) {
                func_00102c18(1, 0x7526, D_00232150);
                D_0035de26 = 1;
            }
        } else {
            D_0035de26 = 0;
        }
    }
}
