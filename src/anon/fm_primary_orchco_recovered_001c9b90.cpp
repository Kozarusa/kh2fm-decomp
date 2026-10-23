#include "../common/types.h"
extern "C" s32 D_00351f30;
extern "C" u32 D_01d49980[];
extern "C" void func_001c9c00();
extern "C" void func_001c9c78(u32);

void func_001c9b90() {
    s32 index = 0;
    func_001c9c00();
    if (D_00351f30 > 0) {
        u32* pointer = D_01d49980;
        do {
            index = index + 1;
            func_001c9c78(*pointer);
            pointer = pointer + 1;
        } while (index < D_00351f30);
    }
    D_00351f30 = 0;
}
