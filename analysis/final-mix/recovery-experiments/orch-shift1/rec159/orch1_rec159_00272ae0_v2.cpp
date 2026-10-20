#include "../common/types.h"
extern "C" u32 func_00287bc0(...);
extern "C" u8 func_00272b60(...);
extern "C" int func_0028b040(...);
extern "C" u16* func_00273140(s32);
extern "C" u32 func_00286068(u32);
extern "C" u32 func_00286280(u32);
extern "C" u32 D_0035f01c;
u32 func_00272ae0() {
    func_00287bc0();
    s32 object = func_0028b040(D_0035f01c);
    u32 result = func_00272b60(object) < 2;
    if (result == 0) return result;
    {
        u16* pointer = func_00273140(object);
        result = (u32)pointer;
        if (pointer) {
            u16 item = *pointer;
            result = func_00286068(item);
            if (result) return func_00286280(item);
        }
    }
    return result;
}

