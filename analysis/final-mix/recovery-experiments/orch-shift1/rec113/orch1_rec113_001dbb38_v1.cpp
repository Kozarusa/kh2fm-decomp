#include "../common/types.h"
extern "C" u8* func_00185da8(u8*);
extern "C" s32 func_0019c410(u8*);

void func_001dbb38() {
    u8* object = 0;
    do {
        object = func_00185da8(object);
        if (object == 0) {
            return;
        }
    } while (func_0019c410(object) == 0);
    (*(void (**)(u8*))(*(u8**)object + 0x20))(object);
}
