#include "../common/types.h"
extern "C" u32 func_001d9d48(u8* data);
extern "C" u8* func_001d9e30(u8* entry);
extern "C" u32 func_00276c18(void);
s32 func_002b3ae8() {
    u8* entry = 0;
    s32 flag = 0;
next:
    entry = func_001d9e30(entry);
    if (entry != 0) goto test;
finish: {
    s32 result = 0;
    if (flag != 0 || func_00276c18() != 0) result = 1;
    return result;
    }
test:
    if (func_001d9d48(entry) == 0) goto next;
    flag = 1;
    goto finish;
}

