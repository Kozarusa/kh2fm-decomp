#include "../common/types.h"
extern "C" u8 D_0034c70c;
extern "C" u8 D_0034c6f0[];
extern "C" u64 func_001dde40(...);
extern "C" u32 func_001de568(...);
extern "C" void func_00142f50();

void func_0015edb8() {
    if (D_0034c70c == 1) {
        u8* object = D_0034c6f0;
        if (func_001de568(object) != 0) {
            func_001dde40(object);
        }
    }
    D_0034c70c = 0;
    func_00142f50();
}
