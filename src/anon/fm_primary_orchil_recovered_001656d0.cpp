#include "../common/types.h"
struct NodeList {
    s32* head;
    s32* tail;
};
extern "C" s32 D_0034c7a4;
extern "C" NodeList D_004f41c0;
extern "C" void func_001656c0(s32*);
extern "C" s32 func_001063c0(u32, u32);
extern "C" s32 func_001415e8(s32, s32, s32);

s32 func_001656d0(s32* object, s32 name, s32 value) {
    func_001656c0(object);
    object[0] = value;
    s32 data = func_001063c0(224, D_0034c7a4);
    s32 result = func_001415e8(data, name, -1);
    ((s32**)object)[1] = (s32*)data;
    if (D_004f41c0.tail == 0) {
        D_004f41c0.tail = object;
        D_004f41c0.head = object;
        object[3] = 0;
    } else {
        ((s32**)D_004f41c0.tail)[3] = object;
        object[3] = 0;
        D_004f41c0.tail = object;
    }
    return result;
}
