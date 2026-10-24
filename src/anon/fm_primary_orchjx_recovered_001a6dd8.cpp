#include "../common/types.h"
struct TaskData {
    s32 words[5];
};
struct TaskArgs {
    s32 value;
    TaskData data;
};
extern "C" TaskArgs D_01c6cb78;
extern "C" u32 func_00102c48(u32, u32, u32, u32);
extern "C" u8* func_001b8680(s32, s32);

u32 func_001a6dd8(s32* object, s32 value, TaskData* data, u32 entry, s32 key) {
    if (object[1] == 0) {
        object[1] = (s32)func_001b8680(object[0], key);
    }
    D_01c6cb78.value = value;
    D_01c6cb78.data = *data;
    u32 task = func_00102c48(1, 15000, entry, 4096);
    *(s32**)(task + 4) = object;
    return task;
}
