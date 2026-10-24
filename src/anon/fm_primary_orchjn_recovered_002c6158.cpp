#include "../common/types.h"
extern "C" void func_002c6190(u8*);
extern "C" u8 D_002c6380[];

void func_002c6158(u8* object) {
    *(s32*)object = 1;
    *(s32*)(object + 4) = 26000;
    *(u8**)(object + 8) = D_002c6380;
    *(s32*)(object + 12) = 0;
    func_002c6190(object);
}
