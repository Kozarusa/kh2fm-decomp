#include "../common/types.h"
extern "C" u32 func_001ba028(...);
void func_0022e6b0(s32 index, u8* object, f32 value) {
    func_001ba028(object);
    if (index == 1) {
        *(f32*)(object + 56) = value;
    } else if (index < 2) {
        if (index == 0) *(f32*)(object + 52) = value;
    } else if (index == 2) {
        *(f32*)(object + 48) = value;
    }
}