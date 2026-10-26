#include "../common/types.h"
extern "C" u8 D_00348d58[];
extern "C" u8 D_00348698[];
extern "C" void func_00106420(u32*);
void func_0031e0b8(u32* object) {
    object[20] = (u32)D_00348698;
    object[0] = (u32)D_00348d58;
    func_00106420(object);
}
