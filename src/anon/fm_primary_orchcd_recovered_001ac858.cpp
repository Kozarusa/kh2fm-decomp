#include "../common/types.h"
extern "C" u8 D_00350bf0[];
extern "C" void func_001ac378(s32*, s32, s32, s32, s32, s32, s32);
extern "C" void func_001aa668(s32*, s32*);

void func_001ac858(s32* object, s32 value) {
    func_001ac378(object, 4, 3, value, 0, 256, 365);
    object[25] = 4;
    object[0] = (s32)D_00350bf0;
    func_001aa668(object + 3, object);
}
