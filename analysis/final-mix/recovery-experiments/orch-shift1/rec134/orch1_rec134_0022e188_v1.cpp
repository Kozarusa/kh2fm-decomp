#include "../common/types.h"
extern "C" void func_002feee8(u8*,u8*);
extern "C" s32 func_002ff3fc(...);
extern "C" u8 D_003711e8[];
extern "C" u8 D_003711f8[];
extern "C" u8 D_01dadac0[];
u8* func_0022e188(u8* value) {
    D_01dadac0[0] = 0;
    u8* pointer = D_01dadac0;
    func_002feee8(pointer, D_003711e8);
    func_002feee8(pointer, value);
    func_002feee8(pointer, D_003711f8);
    func_002ff3fc(pointer);
    return pointer;
}
