#include "../common/types.h"
extern "C" u8* D_00352ae0;

void func_001ddc08() {
    u8* object = D_00352ae0;
    if (object != 0) {
        do {
            *(u32*)(object + 8) |= 0x4000000;
            object = *(u8**)(object + 0x28);
        } while (object != 0);
    }
}
