#include "../common/types.h"
struct Task {
    u8 pad[0x30];
    void* callback;
};
extern "C" void D_001de690(Task*);
extern "C" void D_001de6d0(Task*);
extern "C" void D_001de710(Task*);
extern "C" Task* func_00102788(s32, s32, s32, void (*)(Task*));

void func_001de8a8(s32 a, s32 b, s32 c, s32 d) {
    func_00102788(a, b, c, D_001de690);
    Task* task = func_00102788(a, b, d, D_001de6d0);
    task->callback = (void*)D_001de710;
}
