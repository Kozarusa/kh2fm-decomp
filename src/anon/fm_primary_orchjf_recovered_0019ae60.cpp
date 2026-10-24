#include "../common/types.h"
extern "C" void func_0019aec0(u8*, u32);

void func_0019ae60(u8* object) {
    if (object[0x20] < 200) {
        object[0x20]++;
        u8* data = *(u8**)(object + 8);
        if (data[0x23] != 0 && object[0x20] >= data[0x23]) {
            func_0019aec0(object, data[0x24]);
        }
    }
}
