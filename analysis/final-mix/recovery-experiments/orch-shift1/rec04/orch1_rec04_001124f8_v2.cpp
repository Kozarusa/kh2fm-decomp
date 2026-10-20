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

void func_001124f8() {
    D_00341700 = 0;
    func_0010b550(D_003a9040);
    u16 mode = D_0032bae0;
    s32 result = 2;
    if (mode == 0x808 || mode == 0x30d) {
        result = 1;
    }
    D_00341780 = result;
    D_003417d0 = -1;
    D_003417c4 = 0;
    D_003417c8 = 0;
    func_001127b0();
}

