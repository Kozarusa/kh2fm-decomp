#include "../common/types.h"
extern "C" void* D_0035276c;
extern "C" s8 D_0036e598[];
extern "C" s32 func_001b1490(void*);
extern "C" s32 func_00168b88(s32, s32, s32, s32);
extern "C" void func_001c10b8(s32);

void func_001d53e8(void) {
    s32 handle = func_001b1490(D_0035276c);
    s32 byte0 = D_0036e598[0];
    s32 byte1 = D_0036e598[1];
    s32 byte3 = D_0036e598[3];
    s32 byte2 = D_0036e598[2];
    s32 object = func_00168b88(handle, -1, byte0 | (byte3 << 24) | ((byte2 << 16) | (byte1 << 8)), 0);
    func_001c10b8(*(s32*)(object + 8));
}
