#include "../common/types.h"

extern "C" void func_00135c50(s32*, s32);
extern "C" void func_00135ad0(s32*);

void func_00135bd0(s32* object, s32 value) {
    func_00135c50(object, value);
    s32 count = object[3];
    s32 first = count;
    if (count == 0x20) {
        func_00135ad0(object);
        count = object[3];
        if (count == first) {
            func_00135c50(object, object[4]);
            count = object[3];
        }
    }
    object[count++ + 4] = value;
    object[3] = count;
}

