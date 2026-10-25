#include "../common/types.h"
// why: the table base is held as an s32 so the s32 field stores may alias it, as the original reloads it after each store
extern "C" s32 D_0035dcf4;
extern "C" u64 func_001dde40(...);
extern "C" u32 func_001de568(...);

void func_0022e288() {
    if (D_0035dcf4 != 0) {
        s32 none = -1;
        s32 offset = 0;
        s32 count = 95;
        do {
            if (*(s32*)(offset + D_0035dcf4 + 4) != none) {
                if (func_001de568(offset + D_0035dcf4 + 16) != 0) {
                    func_001dde40(D_0035dcf4 + offset + 16);
                }
                *(s32*)(offset + D_0035dcf4 + 12) = 0;
                *(s32*)(offset + D_0035dcf4 + 4) = none;
            }
            count--;
            offset += 52;
        } while (count >= 0);
    }
}
