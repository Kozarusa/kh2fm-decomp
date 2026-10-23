#include "../common/types.h"
extern "C" void func_002ef928();
extern "C" u32* func_00102788(u32 manager, u32 first, u32 second, u32 third);

void func_002ef8d0(u32* object, u32 manager) {
    if (object[3] == 0) {
        u32* task = func_00102788(manager, object[0], object[1], object[2]);
        object[3] = (u32)task;
        task[1] = (u32)object;
        ((u32*)object[3])[12] = (u32)func_002ef928;
    }
}
