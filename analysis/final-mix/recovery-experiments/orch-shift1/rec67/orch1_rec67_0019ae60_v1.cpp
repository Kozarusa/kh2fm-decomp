#include "../common/types.h"
extern "C" void func_0019aec0(u8*, u32);

void func_0019ae60(u8* object) {
    u8 count = object[0x20];
    u8 next = count + 1;
    if (count < 200) {
        object[0x20] = next;
        u8* data = *(u8**)(object + 8);
        u8 limit = data[0x23];
        if (limit != 0 && limit <= next) {
            func_0019aec0(object, data[0x24]);
        }
    }
}
