#include "../common/types.h"
extern "C" void func_0016a2e0(u8*);

void func_00185a28(u8* object) {
    (*(void (**)(u8*))(*(u8**)object + 0x44))(object);
    (*(void (**)(u8*))(*(u8**)object + 0x28))(object);
    func_0016a2e0(object);
}
