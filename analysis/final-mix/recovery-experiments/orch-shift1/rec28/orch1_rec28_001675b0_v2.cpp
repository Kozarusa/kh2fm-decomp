#include "../common/types.h"
extern "C" volatile f32 D_0036b610;
extern "C" volatile f32 D_0036b614;
extern "C" volatile f32 D_0036b618;
extern "C" s32 D_0032b91c;
extern "C" u8 D_00167618[];
extern "C" void func_00167638(f32, f32, f32);
extern "C" void func_00167b98();
extern "C" void func_00167c30();
extern "C" u64 func_00102788(...);

// why: volatile global keeps separate address+load per read`nvoid func_001675b0(void) {
    func_00167638(D_0036b610, D_0036b614, D_0036b618);
    func_00167b98();
    func_00167c30();
    func_00102788(D_0032b91c, 0, 110000, (s32)D_00167618);
}
