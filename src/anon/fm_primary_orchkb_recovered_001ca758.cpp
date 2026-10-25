#include "../common/types.h"
extern "C" u8* D_00351f68;
extern "C" u8 D_0036e0f8[];
extern "C" u8 D_0036e108[];
extern "C" u32 func_001a5420(u8* object, void* first, void* second);

void func_001ca758(u8* owner, u8* counts) {
    if (D_00351f68 != 0) {
        // why: original keeps the row index in s6 and the owner in s5; without the binding the two swap
        register s32 row asm("$22");
        for (row = 0; row < 9; row++) {
            s32 count = 0;
            if (counts[row + 2] != 0) {
                u32 offset = D_0036e0f8[row] * 16;
                do {
                    count++;
                    func_001a5420(D_00351f68, D_0036e108 + offset, owner);
                } while (count < counts[row + 2]);
            }
        }
    }
}
