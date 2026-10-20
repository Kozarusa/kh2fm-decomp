#include "../common/types.h"

extern "C" u8 D_0032a980[];
extern "C" u8 D_0032b100[];

extern "C" void func_001e72a8(u8*);

void func_0021cda0(s64 value)
{
    // why: original builds the address directly in a0
    register u8* pointer asm("$4");
    if (value == 0) {
        pointer = D_0032a980;
    } else {
        pointer = D_0032b100;
    }
    func_001e72a8(pointer);
}
