#include "../common/types.h"
extern "C" u8 D_0032bae0;
extern "C" u8* D_00351338;
extern "C" u8 D_01d49368[];
extern "C" s32 D_01d4937c;
extern "C" void func_001c0ae0(u8*);
extern "C" void func_001c0ca0(s32);

void func_001c0a00(s32 seed) {
    if (seed == 0) {
        func_001c0ae0(D_01d49368);
        D_00351338 = D_01d49368;
        D_01d4937c = D_01d49368[D_0032bae0];
    } else {
        D_01d4937c = seed;
        D_00351338 = 0;
    }
    if (D_01d4937c == 0) {
        D_01d4937c = 1;
    }
    func_001c0ca0(D_01d4937c);
}
