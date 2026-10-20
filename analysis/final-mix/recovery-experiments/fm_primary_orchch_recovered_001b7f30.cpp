#include "../common/types.h"
extern "C" u8 D_003511c3;
extern "C" void func_001b7f88();
extern "C" u32 func_00170c00(...);

void func_001b7f30(s32* object) {
    if (*object != 0) {
        if (D_003511c3 != 1) {
            *object = 0;
            goto done;
        }
        func_001b7f88();
        func_00170c00(*object);
    }
    *object = 0;
done:
    object[1] = 0;
    object[2] = 0;
}
