#include "../common/types.h"
extern "C" u32 func_001c1890(...);

void func_001c1708(u8* object) {
    u8* next;
    object = *(u8**)(object + 0xc);
    while (object != 0) {
        next = *(u8**)(object + 0x24);
        if (object != 0) {
            func_001c1890(object);
        }
        object = next;
    }
}
