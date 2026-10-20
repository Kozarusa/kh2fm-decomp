#include "../common/types.h"
extern "C" u32 func_00232348();
extern "C" u32 func_002fee78(...);
extern "C" void func_002feee8(u8*,u8*);
extern "C" s32 func_002ff3fc(...);
extern "C" u8 D_01dadbb0[];
extern "C" u8 D_003712d8[];
extern "C" u8 D_003712e8[];

u8* func_00232498(u8* value) {
    D_01dadbb0[0] = 0;
    u32 result = func_00232348();
    u8* pointer = D_01dadbb0;
    func_002fee78(pointer, D_003712d8, result);
    func_002feee8(pointer, value);
    func_002feee8(pointer, D_003712e8);
    func_002ff3fc(pointer);
    return pointer;
}
