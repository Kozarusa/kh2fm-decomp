#include "../common/types.h"
extern "C" u32 D_0035f200;
extern "C" u32 D_0035f214;
extern "C" u32 func_0028b038(u32);
extern "C" void func_0028be78(u32, u32);
extern "C" void func_0029fcb0();
extern "C" void func_002a03d0();

void func_002a0168(u32 object, s32 event) {
    switch (event) {
    case 24:
        func_0029fcb0();
        func_002a03d0();
        break;
    case 25:
        func_0028be78(D_0035f214, func_0028b038(D_0035f200));
        break;
    }
}
