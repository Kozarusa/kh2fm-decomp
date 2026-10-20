#include "../common/types.h"
extern "C" void func_00139d78(void);
extern "C" u32 func_00192048(...);
void func_0023f5b8(u8* object, s32 value) {
    func_00139d78();
    if (value >= 0 && value != *(s32*)(object + 36)) {
        u32 result = func_00192048(value);
        *(u32*)(object + 32) = result;
        *(s32*)(object + 36) = value;
    }
}
