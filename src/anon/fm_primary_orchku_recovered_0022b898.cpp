#include "../common/types.h"
extern "C" u32 D_0035e2e8;
// why: the accepted C++ definition in fm_primary_framealias_recovered_address.cpp fails the isolated link (v1); the probe linker script defines only the plain symbol
extern "C" u32 func_0022b7f0(void);
// why: the accepted asm-label form in fm_primary_width_recovered_02.cpp fails the isolated link (v1); the probe linker script defines only the plain symbol
extern "C" void func_0023fa90(u32 layout, u32 name);
extern "C" u32 func_0023f908(...);
extern "C" u32 func_0023f948(...);
extern "C" u32 func_001050c8(void);
extern "C" void func_00236a58(...);
// why: cmenu_slbase.cpp declares this void because it discards the result; the original 0023c100 ends with li v0,1 after its last call, so the tail call here returns that integer
extern "C" s32 func_0023c100(...);

s32 func_0022b898(void) {
    func_0023fa90(D_0035e2e8, func_0022b7f0());
    u32 message = func_0023f908(D_0035e2e8, 0);
    u32 graphic = func_0023f948(D_0035e2e8, 0);
    u32 allocator = func_001050c8();
    func_00236a58(D_0035e2e8 + 120, message, allocator);
    return func_0023c100(D_0035e2e8 + 28, graphic, D_0035e2e8 + 120, allocator);
}
