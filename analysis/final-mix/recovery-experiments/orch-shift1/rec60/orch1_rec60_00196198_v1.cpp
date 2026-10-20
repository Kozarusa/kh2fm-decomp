#include "../common/types.h"
extern "C" u32 D_0032b91c;
extern "C" u32 D_01c61b00;
extern "C" void func_0016c750(u32);
extern "C" u32 func_0016d080(u32, u32);
extern "C" void func_0016cbc8(u32, u32, u32, u32);
extern "C" u32 func_0016cd48(u32, u32);
extern "C" u32 func_0016cab8(u32);
extern "C" u32 func_0016c7d8(u32);
extern "C" u32 func_0016c770();

u32 func_00196198() {
    func_0016c750(D_0032b91c);
    u32 object = func_0016d080(D_01c61b00, 0);
    func_0016cbc8(object, 7, 0, 0);
    func_0016cd48(object, 0);
    if (object != 0) {
        func_0016cab8(object);
        func_0016c7d8(object);
    }
    return func_0016c770();
}
