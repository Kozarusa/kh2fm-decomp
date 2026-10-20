#include "../common/types.h"

extern "C" u8 D_0032a980[];
extern "C" u8 D_0032b100[];

extern "C" void func_001e72a8(u8*);

void func_0021cda0(s64 value)
{
    func_001e72a8(value == 0 ? D_0032a980 : D_0032b100);
}
