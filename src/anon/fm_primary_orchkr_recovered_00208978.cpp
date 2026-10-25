#include "../common/types.h"

extern "C" u8* D_01d9e6e8;
extern "C" u8 D_01d9e840[];
extern "C" const void* D_0037060c[10];
extern "C" void func_002f4000(f32*);
extern "C" void func_002f3d08(u8*, u8*, u8*);

void func_00208978(u8* target, u8* object, u8* other) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0037060c
    static const void* targets[10] asm("fm_switch_table_00208978") = {
        &&check, &&apply, &&check, &&apply, &&check,
        &&apply, &&check, &&apply, &&check, &&apply};
    s32 flag = *(s32*)(other + 20);
    func_002f4000((f32*)target); // why: the accepted call site at 001eb0c8 declares an f32* matrix parameter
    u32 index = object[38];
    if (index >= 10) goto check;
    goto *D_0037060c[index];
check:
    if (flag == 0) {
        func_002f3d08(target, D_01d9e840, D_01d9e6e8 + 16);
    }
    return;
apply:
    func_002f3d08(target, D_01d9e840, D_01d9e6e8 + 16);
    asm volatile("" ::: "memory"); // why: original makes a normal call on this path and returns through the shared epilogue instead of a tail jump
}
