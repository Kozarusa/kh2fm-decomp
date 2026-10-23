#include "../common/types.h"
extern "C" u8* D_00352ae0;

void func_001ddc48() {
    u8* object = D_00352ae0;
    if (object != 0) {
        do {
            *(u32*)(object + 8) &= 0xfbffffff;
            object = *(u8**)(object + 0x28);
        } while (object != 0);
    }
}
