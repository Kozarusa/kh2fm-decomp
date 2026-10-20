#include "../common/types.h"
extern "C" u32 func_002cd1d8();
extern "C" void func_002cd290(u32, u8*, u32);

void func_00185050(u8* object, u32 arg) {
    u32 handle = *(u32*)(object + 0x508);
    if (handle == 0) {
        *(u32*)(object + 0x508) = func_002cd1d8();
    } else {
        func_002cd290(handle, object, arg);
    }
}
