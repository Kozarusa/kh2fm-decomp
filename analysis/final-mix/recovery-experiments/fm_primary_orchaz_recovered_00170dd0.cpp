#include "../common/types.h"
extern "C" s64 func_00170cd0(void);
extern "C" void func_00102448(u64, u32);

void func_00170dd0(u64 task) {
    while (func_00170cd0() != 0) {
        func_00102448(task, 0);
    }
}
