#include "../common/types.h"
extern "C" u8* D_01d49320;
extern "C" u64 func_001bb468(...);
extern "C" void func_001af2e8();
extern "C" void func_001af360(u64);

void func_001bbc30() {
    u8* base = *(u8**)(D_01d49320 + 8);
    u8 kind = base[8];
    func_001bb468();
    if (kind != 30) {
        if (kind < 31) {
            if (kind != 2) {
                func_001af2e8();
                return;
            }
        } else if (kind != 35) {
            func_001af2e8();
            return;
        }
    }
    func_001af360(0);
}
