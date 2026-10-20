#include "../common/types.h"
extern "C" void func_0019aec0(u8*, u32);

void func_0019ae60(u8* object) {
    u32 count = *(volatile u8*)(object + 0x20); // why: keeps one load, mask applied at the compare
    u32 next = count + 1;
    if ((count & 0xff) < 200) {
        object[0x20] = next;
        u8* data = *(u8**)(object + 8);
        u8 limit = data[0x23];
        if (limit != 0 && (next & 0xff) >= limit) {
            func_0019aec0(object, data[0x24]);
        }
    }
}
