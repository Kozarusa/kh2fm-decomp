#include "../common/types.h"
extern "C" u32 D_0034f240;
extern "C" u32 D_00350338[];
extern "C" void func_0016d110();
extern "C" u32 func_0016cd48(u32, u32);

void func_00196888() {
    func_0016d110();
    if ((D_0034f240 & 0x20) == 0) {
        s32 count = 7;
        u32* entry = D_00350338;
        do {
            if (entry[1] != 0 && entry[0] == 0) {
                entry[0] = func_0016cd48(entry[1], 0);
            }
            count--;
            entry += 2;
        } while (count >= 0);
    }
}
