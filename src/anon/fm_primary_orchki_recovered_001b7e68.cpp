#include "../common/types.h"
extern "C" u32 D_003511bc;
extern "C" u32 D_01d48cb8;
extern "C" u8 D_003511c3;
extern "C" u32 func_001b7f30(void*);   // copied from accepted fm_primary_orchgi_recovered_0014b9a8.cpp (result unused here)
extern "C" void func_001b7f88();       // copied from accepted fm_primary_orchch_recovered_001b7f30.cpp
extern "C" u32 func_00170b30(...);     // copied from accepted fm_primary_orchgj_recovered_002ef6b0.cpp

void func_001b7e68(s32* object, u32 count) {
    func_001b7f30(object);
    if (count != 0) {
        count = count + 1;
        if (count < 1024) {
            D_003511c3 = 0;
            if (D_003511bc < D_01d48cb8 + (count << 4)) {
                func_001b7f88();
            }
            *object = D_01d48cb8;
            D_01d48cb8 += (count << 4);
        } else {
            *object = func_00170b30((count << 4));
            asm volatile("" ::: "memory");  // why: keeps store order
            D_003511c3 = 1;
        }
        object[1] = *object + (count << 4);
        object[2] = *object + 16;
    }
}
