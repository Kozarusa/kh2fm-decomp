#include "../common/types.h"
extern "C" s8 *D_0035f5ec;
extern "C" bool func_002944d0(void*);
extern "C" int func_002a6368(int);
s32 func_002a6290() {
    s32 index = 0;
    s32 count = 0;
    s8 **global = &D_0035f5ec;
    s8 *pointer = *global;
    if (*pointer > 0) {
        do {
            s32 value = pointer[index + 6];
            index++;
            s32 result = func_002a6368(value);
            bool flag = func_002944d0((void *)result);
            if (flag) count++;
            pointer = *global;
        } while (index < *pointer);
    }
    return count;
}


