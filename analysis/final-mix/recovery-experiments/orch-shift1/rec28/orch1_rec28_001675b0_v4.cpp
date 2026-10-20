#include "../common/types.h"
extern "C" u8 D_0036b610[];
extern "C" u8 D_0036b614[];
extern "C" u8 D_0036b618[];
extern "C" s32 D_0032b91c;
extern "C" u8 D_00167618[];
extern "C" void func_00167638(f32, f32, f32);
extern "C" void func_00167b98();
extern "C" void func_00167c30();
extern "C" u64 func_00102788(...);

void func_001675b0(void) {
    f32 *p = (f32 *)D_0036b610;
    asm("" : "+r"(p)); // why: forces address to be built in a register before the load
    f32 *q = (f32 *)D_0036b614;
    asm("" : "+r"(q)); // why: forces address to be built in a register before the load
    f32 *r = (f32 *)D_0036b618;
    asm("" : "+r"(r)); // why: forces address to be built in a register before the load
    func_00167638(*p, *q, *r);
    func_00167b98();
    func_00167c30();
    func_00102788(D_0032b91c, 0, 110000, (s32)D_00167618);
}
