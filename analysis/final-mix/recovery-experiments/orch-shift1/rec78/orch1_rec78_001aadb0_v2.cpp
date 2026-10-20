#include "../common/types.h"
extern "C" u8 D_01c6cd20[];
extern "C" u32 func_002362b0(u8*, s32);
extern "C" u32 func_002367c8(u8*);

void func_001aadb0(s32 value) {
    func_002362b0(D_01c6cd20, value);
    func_002367c8(D_01c6cd20);
}
