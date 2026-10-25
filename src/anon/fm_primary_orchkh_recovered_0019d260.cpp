#include "../common/types.h"
#include "../kn/fvector.hpp"
struct Drawable;
typedef void (*DrawMethod)(Drawable*, kn::FVector*);
struct Drawable {
    DrawMethod* table;
};
extern "C" s32 func_0013e610(u32);
extern "C" kn::FVector* func_00190388(kn::FVector*, s32*);
extern "C" u32 func_0019d228(...);
// why: accepted C++ definition void func_0013e520(u32, u32) fails the isolated probe link; extern "C" resolves the plain symbol
extern "C" void func_0013e520(u32, u32);

void func_0019d260(u8* object) {
    kn::FVector position;
    s32 handle;
    if ((*(u32*)(object + 44) & 1) == 0) {
        s32 state = *(s32*)object;
        if (state != 1) {
            if (state != 2) {
                goto other; // why: original shares the func_0019d228 block placed after the epilogue
            }
            handle = *(s32*)(object + 24);
            if (handle != 0) {
                goto draw; // why: original jumps straight into the shared draw block
            }
            register s32 flag asm("$14") = *(s32*)(object + 36); // why: original loads the flag into t6
            s32 id = 27; // why: separate id temporary gives the original a0 movn register order
            if (flag != 0) {
                id = 23;
            }
            handle = func_0013e610(id);
        } else {
            handle = *(s32*)(object + 24);
            if (handle != 0) {
                goto draw; // why: original jumps straight into the shared draw block
            }
            handle = func_0013e610(*(s32*)(object + 36) == 0 ? 5 : 1);
        }
        *(s32*)(object + 24) = handle;
    } else {
    other:
        func_0019d228();
        handle = *(s32*)(object + 24);
    }
    if (handle == 0) {
        return;
    }
draw:
    func_00190388(&position, (s32*)(object + 4));
    {
        Drawable* drawable = *(Drawable**)(object + 24);
        drawable->table[7](drawable, &position);
    }
    {
        u8* owner = *(u8**)(object + 4);
        u32 enabled = 0;
        if ((*(u32*)(owner + 1416) & 2) != 0) {
            if (*(s32*)(owner + 2760) > 0 || *(s32*)(owner + 2764) > 0) {
                enabled = 1;
            }
        }
        func_0013e520(*(u32*)(object + 24), enabled);
    }
}
