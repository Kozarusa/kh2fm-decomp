#include "../common/types.h"
extern "C" u32 func_00106450(s64);
extern "C" u32 func_00239870(void*);

// Preserve original registry aliases.
void func_0028e350(void* object) asm("_Z16ctarget_0028e350jjjj");

void func_0028e350(void* object) {
    register u8* base asm("$4"); // why: original keeps the array pointer in a0
    u8* end;

    base = (u8*)*(u32*)((u8*)object + 0x38);
    if (base == 0) {
        return;
    }

    end = base + (*(s32*)(base - 4) * 0x17c);
    for (;;) {
        if (base == end) {
            break;
        }
        end -= 0x17c;
        func_00239870((void*)end);
        base = (u8*)*(u32*)((u8*)object + 0x38);
    }

    u8* block = base - 4;
    func_00106450((s64)(s32)block);
    *(u32*)((u8*)object + 0x38) = 0;
}
