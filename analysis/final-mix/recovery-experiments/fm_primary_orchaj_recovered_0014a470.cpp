#include "../common/types.h"
extern "C" u8 D_0034926a;
extern "C" u32 D_0032b91c;
extern "C" u8 D_0014a310[];
extern "C" u64 func_00102788(...);
extern "C" void func_0014a248(void);

u64 func_0014a470(void) {
    D_0034926a = 0;
    func_0014a248();
    return func_00102788(D_0032b91c, 0, 0x1c908, (s32)D_0014a310);
}
