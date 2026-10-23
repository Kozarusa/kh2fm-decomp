#include "../common/types.h"
extern "C" s64 func_002ba200();
extern "C" void func_00102448(u64, u32);

s64 func_002ba7c8(u64 task) {
    s64 result;
    while ((result = func_002ba200()) != 0) {
        func_00102448(task, 0);
    }
    return result;
}
