#include "../common/types.h"
extern "C" u8* D_0035ec90;
extern "C" void func_00242408();
extern "C" u32 func_00242418(u8*, s32);

u32 func_002409b8(u8* object) {
    if (!object) object = D_0035ec90;
    func_00242408();
    func_00242418(object, 8);
    return func_00242418(object + 12, 0x10fb4);
}
