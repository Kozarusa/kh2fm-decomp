#include "../common/types.h"
extern "C" u8 D_00341700;
extern "C" u8 D_003a9040[];
extern "C" u16 D_0032bae0;
extern "C" s32 D_00341780;
extern "C" s32 D_003417d0;
extern "C" s32 D_003417c4;
extern "C" s32 D_003417c8;
extern "C" void func_0010b550(u8* target);
extern "C" void func_001127b0();

// Preserve original registry aliases.
void func_001124f8() asm("_Z16wtarget_001124f8jjjj");

void func_001124f8() {
    D_00341700 = 0;
    func_0010b550(D_003a9040);
    if (D_0032bae0 == 0x808 || D_0032bae0 == 0x30d) {
        D_00341780 = 1;
    } else {
        D_00341780 = 2;
    }
    D_003417d0 = -1;
    D_003417c4 = 0;
    D_003417c8 = 0;
    func_001127b0();
}
