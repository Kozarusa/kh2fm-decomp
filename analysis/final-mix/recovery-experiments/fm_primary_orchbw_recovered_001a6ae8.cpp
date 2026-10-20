#include "../common/types.h"
struct Slot {
    s32 pad;
    void* block;
};
extern "C" Slot D_01c6cb30[];
extern "C" s32 D_01c6cb70;
extern "C" void func_00105110(void*);

void func_001a6ae8(void) {
    s32 index;
    for (index = 0; index < D_01c6cb70; index++) {
        func_00105110(D_01c6cb30[index].block);
    }
    D_01c6cb70 = 0;
}
