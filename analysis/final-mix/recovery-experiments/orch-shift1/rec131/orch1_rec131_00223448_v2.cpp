#include "../common/types.h"
extern "C" u8 D_00370bd8[];
extern "C" u8 D_00370bf8[];
extern "C" u8 D_00370c10[];
extern "C" u32 func_002fdfc8(...);

void func_00223448(u64 first, u64 second, u64 third, u64 fourth) {
    func_002fdfc8(D_00370bd8, first);
    func_002fdfc8(D_00370bf8, second, third);
    func_002fdfc8(D_00370c10, fourth);
    __builtin_trap();
}
