#include "../common/types.h"
extern "C" u32 func_00257770(void);
extern "C" s32 func_00139d78(u32);
extern "C" void func_00139510(u32);
extern "C" u32 func_0028abe0(u32);
extern "C" u32 func_0028acc8(u32);
extern "C" u32 D_0035f01c;

typedef void (*LeaveMethod)(u32);

// why: every exit is a direct callee result (tail 0028abe0, or the zero 0028acc8 result), so the return is typed

u32 func_002655e8(void) {
    u32 base = func_00257770();
    if (func_00139d78(base) != 0) {
        func_00139510(base);
    }
    u32 cursor = base;
    s32 count = 19;
    do {
        u32 object = cursor + 13840;
        if (func_00139d78(object) != 0) {
            (*(LeaveMethod*)(*(u32*)object + 20))(object);
        }
        object = cursor + 24304;
        if (func_00139d78(object) != 0) {
            (*(LeaveMethod*)(*(u32*)object + 20))(object);
        }
        count--;
        cursor += 436;
    } while (count >= 0);
    u32 result = func_0028acc8(D_0035f01c);
    if (result != 0) {
        return func_0028abe0(D_0035f01c);
    }
    return result;
}
