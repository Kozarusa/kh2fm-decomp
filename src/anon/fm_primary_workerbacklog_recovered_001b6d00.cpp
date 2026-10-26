#include "../common/types.h"
struct Entry { u32 pad[6]; u32 value; };
extern "C" Entry* D_00351184;
extern "C" u32 D_00351214;
extern "C" void func_00102670(u32, u32);

void func_001b6d00(void)
{
    Entry* entry = D_00351184;
    if (entry != 0) {
        func_00102670(D_00351214, entry->value);
        D_00351184 = 0;
    }
}
