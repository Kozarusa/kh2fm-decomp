#include "../common/types.h"
extern "C" u8 D_01e2a410[];
extern "C" u32 func_002b7fbc(u32);
// why: no recovered site uses this callee; a0 carries the D_01e2a410 address
extern "C" u32 func_002bced8(void*);
// why: plain extern "C" name; the recovered definition takes the same pointer in a0
extern "C" u32 func_002bcee8(s32*);
extern "C" u32 func_002b9b78(void);
extern "C" u32 func_002ba390(void);
extern "C" void func_002bc798(void);
// why: plain extern "C" name; the recovered definition returns u64 with no arguments
extern "C" u64 func_002ba9c0(void);
extern "C" u32 func_002bc470(s32);
extern "C" u32 func_002baa60(...);
// why: plain extern "C" name; the recovered definition is void with one s32 argument
extern "C" void func_002bc608(s32);
// why: its own instructions never write v0 or f0, so the tail call returns nothing
extern "C" void func_002bbf98(void);

void func_002b9fb0()
{
    func_002b7fbc(1);
    func_002bced8(D_01e2a410);
    func_002bcee8((s32*)D_01e2a410);
    func_002b9b78();
    func_002ba390();
    func_002bc798();
    func_002ba9c0();
    func_002bc470(2);
    func_002bc470(3);
    func_002baa60();
    func_002bc608(0);
    func_002bc608(1);
    func_002bc608(2);
    func_002bbf98();
}
