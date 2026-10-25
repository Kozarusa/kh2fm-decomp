#include "../common/types.h"
struct Task {
    u8 pad[0x30];
    void* callback;
};
extern "C" void D_001dd2b8(Task*);
extern "C" void D_001dd920(Task*);
extern "C" void D_001dda78(Task*);
extern "C" void D_001ddb30(Task*);
extern "C" Task* func_00102788(s32, s32, s32, void (*)(Task*));

Task* func_001ddb78(s32 a, s32 b, s32 c, s32 d, s32 e) {
    func_00102788(a, b, c, D_001dd2b8);
    func_00102788(a, b, d, D_001dd920);
    Task* task = func_00102788(a, b, e, D_001dda78);
    task->callback = (void*)D_001ddb30;
    return task;
}
