#include "../common/types.h"
extern "C" void func_002f3f88(u8*, s32);
extern "C" void func_00222898(u8*, u8*, u8*);

void func_00220c88() {
    register u8* entry asm("$2"); // why: v0 is live on entry, not an argument
    u8* volatile slot = entry; // why: original spills v0 to 0(sp)
    u8* base = entry;
    u8* pointer = base + 480;
    func_002f3f88(pointer, *(s32*)(base + 500));
    func_00222898(base + 160, base, pointer);
    *(s32*)(base + 500) += *(s32*)(base + 516);
    *(s32*)(base + 524) -= 1;
}
