#include "../common/types.h"
extern "C" u8* D_00352ae0;
extern "C" void func_001dc878(u8*);

void func_001dcfb0() {
    u8* object = D_00352ae0;
    while (object != 0) {
        u8* next = *(u8**)(object + 0x28);
        func_001dc878(object);
        object = next;
    }
}
