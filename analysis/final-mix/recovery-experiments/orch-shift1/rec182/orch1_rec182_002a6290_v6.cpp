#include "../common/types.h"
extern "C" s8 *D_0035f5ec;
extern "C" bool func_002944d0(void*);
extern "C" int func_002a6368(int);
s32 func_002a6290() {
    s32 index = 0;
    s32 count = 0;
    register u32 global asm("$18") = ((u32)&D_0035f5ec + 0x10000u) & 0xffff0000u; // why: original high address persists in s2
    s8 *pointer = *(s8 **)(global - 2580u);
    if (*pointer > 0) {
        do {
            s32 value = pointer[index + 6];
            index++;
            s32 result = func_002a6368(value);
            bool flag = func_002944d0((void *)result);
            if (flag) count++;
            pointer = *(s8 **)(global - 2580u);
        } while (index < *pointer);
    }
    return count;
}




