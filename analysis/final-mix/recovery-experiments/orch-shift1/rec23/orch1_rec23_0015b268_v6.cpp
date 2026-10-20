#include "../common/types.h"
extern "C" s32 D_0034aa98;
extern "C" u8* D_0034aa9c;
extern "C" void func_0015ad80(u8*, s32);
extern "C" void func_0015aea8(u8*, s32);

void func_0015b268(s32 value, f32 amount) {
    if (D_0034aa98 == 0) {
        func_0015ad80(D_0034aa9c, value);
        D_0034aa98 = D_0034aa98 + 1;
        return;
    }
    u8* target = D_0034aa9c;`n    *(f32*)(target + 0x1b4) = amount;
    func_0015aea8(*(u8* volatile*)&D_0034aa9c, value); // why: original reloads the pointer after the store
}
