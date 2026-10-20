#include "../common/types.h"
extern "C" bool func_001bb4a0(void);
extern "C" u64 func_00192048(u64);
extern "C" void func_0014f578(u64);
extern "C" u8* D_01d49320;

void func_001bb958(s64 value) {
    if (value == 0) {
        if (func_001bb4a0() == 0) {
            return;
        }
        value = *(u16*)(*(u8**)(D_01d49320 + 8) + 6);
    }
    if (value <= 0) {
        return;
    }
    func_0014f578(func_00192048(value));
}
