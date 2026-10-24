#include "../common/types.h"
struct Entry00350338 {
    s32 key;
    s32 handle;
};
extern "C" Entry00350338 D_00350338[];
extern "C" void func_0016cce8(s32, s32, void*, s32, s32);

void func_00196aa0(s32 first, void* second, s32 third) {
    for (s32 index = 0; index < 8; index++) {
        if (D_00350338[index].handle != 0) {
            func_0016cce8(D_00350338[index].handle, first, second, third, 0);
        }
    }
}
