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
    *(f32*)(D_0034aa9c + 0x1b4) = amount;
    func_0015aea8(D_0034aa9c, value);
}
