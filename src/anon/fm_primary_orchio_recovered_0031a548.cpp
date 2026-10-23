// func_0031a548: exact form found by the KH2FM permuter (orchestration/tools/kh2perm) from an earlier
// attempt or a same-shape accepted sibling. Names and types are provisional.
#include "../common/types.h"

extern "C" void func_00239870(u32);
extern "C" void func_0031a840(u32);
extern "C" u8 D_00347e60[];
extern "C" u8 D_00347f80[];

typedef u32 (*Callback)(void*, void*);

u32 func_0031a548(u8* object) {
    *(u32*)object = (u32)D_00347e60;
    func_00239870((u32)(object + 24));
    func_0031a840((u32)object);
    u32* service = *(u32**)D_00347f80;
    u32* receiver = *(u32**)((u8*)service + 20);
    u32* table = *(u32**)receiver;
    register Callback call asm("$15") = (Callback)table[1]; // why: original calls through t7
    return call(receiver, object);
}
