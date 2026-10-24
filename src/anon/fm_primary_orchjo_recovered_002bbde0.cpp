#include "../common/types.h"
struct Pair {
    s32 value;
    void* pointer;
};
extern "C" s32 D_003616f4;
extern "C" s32 D_003616e8;
extern "C" Pair D_01e2aa80;
extern "C" void* D_01e2aa88[];
extern "C" void func_002bb0c8(...);
extern "C" void func_002bc798(void);

void func_002bbde0() {
    D_003616f4 = 0;
    D_003616e8 = 1;
    func_002bb0c8(100);
    Pair* first = &D_01e2aa80;
    void** second = D_01e2aa88;
    first->pointer = 0;
    first->value = 0;
    second[1] = 0;
    second[0] = 0;
    func_002bc798();
}
