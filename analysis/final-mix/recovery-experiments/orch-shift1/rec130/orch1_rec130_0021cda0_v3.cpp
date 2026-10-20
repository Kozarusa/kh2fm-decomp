#include "../common/types.h"

extern "C" u32 D_0032a980;
extern "C" u32 D_0032b100;

extern "C" void func_001e72a8(u32*);

void func_0021cda0(s64 value)
{
    u32* pointer;
    if (value == 0) {
        pointer = &D_0032a980;
    } else {
        pointer = &D_0032b100;
    }
    func_001e72a8(pointer);
}
