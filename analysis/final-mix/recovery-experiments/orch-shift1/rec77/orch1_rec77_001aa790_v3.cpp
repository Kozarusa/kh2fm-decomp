#include "../common/types.h"

extern "C" u32 func_00192f78(u32*);
extern "C" u32 func_001ab750(u32, u32*);

void func_001aa790(u32* object, u32 value) {
    object[0] = value;
    object[5] = 0x60000000;
    object[1] = 0;
    func_00192f78(object + 8);
    object[14] = 0;
    object[15] = 0;
    volatile u32* inner = object + 16;
    object[16] = 0;
    // why: keeps store order and the reload of ra after these stores
    inner[2] = 0;
    inner[1] = 0;
    object[19] = 0;
    func_001ab750(object[0], (u32*)inner);
}
