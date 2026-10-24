#include "../common/types.h"
extern "C" u32 D_0035f200;
extern "C" u32 D_0035f214;
extern "C" u32 func_0028b038(u32);
extern "C" void func_0028be78(u32, u32);
extern "C" void func_002a5df0();
extern "C" void func_002a65d0();

void func_002a6308(s32 unused, s32 command) {
    switch (command) {
    case 37:
        func_002a5df0();
        func_002a65d0();
        break;
    case 38:
        u32 result = func_0028b038(D_0035f200);
        func_0028be78(D_0035f214, result);
        break;
    }
}
