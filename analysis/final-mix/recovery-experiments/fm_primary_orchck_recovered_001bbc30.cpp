#include "../common/types.h"
extern "C" u8* D_01d49320;
extern "C" u64 func_001bb468(...);
extern "C" void func_001af2e8();
extern "C" void func_001af360(u64);

void func_001bbc30() {
    u8* base = *(u8**)(D_01d49320 + 8);
    u8 kind = base[8];
    func_001bb468();
    switch (kind) {
    case 2:
    case 30:
    case 35:
        func_001af360(0);
        break;
    default:
        func_001af2e8();
        break;
    }
}
