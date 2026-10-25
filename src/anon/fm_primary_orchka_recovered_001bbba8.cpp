#include "../common/types.h"
struct Block {
    u32 words[9];
};
extern "C" u32 D_01d49324;
extern "C" u64 func_001bb468(...);
extern "C" Block func_00199098(s32 index); // why: accepted C++ definition fails isolated probe link (v1); same types, C linkage
extern "C" u32 func_0019f070(void*, u32);
extern "C" u32 func_001ada38(s64);
extern "C" u32 func_001d5460(...);
extern "C" void func_001d7940(void); // why: accepted C++ definition fails isolated probe link (v1); same types, C linkage

u32 func_001bbba8(s32 kind) {
    s32 code = -1;
    switch (kind) {
    case 3:
        if (func_001d5460(D_01d49324) != 0) {
            func_001d7940();
        }
        code = 139;
        break;
    case 4:
        func_001ada38(9);
        code = 141;
        break;
    }
    func_001bb468();
    Block block = func_00199098(code);
    return func_0019f070(&block, 0x40000000);
}
