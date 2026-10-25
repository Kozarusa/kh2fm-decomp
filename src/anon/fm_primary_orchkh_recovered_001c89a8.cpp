#include "../common/types.h"
extern "C" s32 D_01d49960[];
extern "C" u8 D_0036e080[];
extern "C" bool func_0019ba60(u64);
extern "C" u32 func_001880b0(...);
extern "C" u32 func_00102448(...);
extern "C" void func_001c9e50(s32);
extern "C" void func_001c9b90();

// why: void per ruling #36: the only exit tail-calls func_001c9b90, whose accepted definition is void and which writes neither v0 nor $f0 (stale-b)

void func_001c89a8(s32 task) {
    if (func_0019ba60(D_01d49960[0])) {
        s32 index;
        func_001880b0(D_01d49960[0] + 0x300, D_0036e080);
        for (index = 0; index < 2; index++) {
            while (D_01d49960[index] != 0) {
                func_00102448(task, 0);
            }
        }
    }
    func_00102448(task, 2);
    func_001c9e50(task);
    func_001c9b90();
}
