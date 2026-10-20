#include "../common/types.h"
extern "C" u8* D_0035037c;
extern "C" void func_001024a8();
extern "C" void func_001d3148(u8*);

void func_00197ac0() {
    u8* object = D_0035037c;
    if (object != 0) {
        u8* member = object + 0x40;
        func_001d3148(member);
        return;
    }
    func_001024a8();
}