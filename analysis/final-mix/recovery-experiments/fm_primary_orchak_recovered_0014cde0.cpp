#include "../common/types.h"
extern "C" u64 func_00102788(...);
extern "C" void func_0014f030(void*);
extern "C" s32 D_0032b91c;
extern "C" u8 D_004574b8[];
extern "C" void D_0014cd98(void);

void func_0014cde0(void) {
    func_0014f030(D_004574b8);
    func_00102788(D_0032b91c, 0, 800000, (s32)D_0014cd98);
}
