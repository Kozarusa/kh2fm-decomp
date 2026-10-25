#include "../common/types.h"
extern "C" u8 D_0035f5c4;
extern "C" u8* D_0035f5ac;
extern "C" u32 func_00276568(void);
// why: SaveCurPos(int,int,int); a0,a1,a2 are set before the jal and its result is unused
extern "C" void func_002765e8(s32, s32, s32);
extern "C" u32 func_00287bd0(u32,u64);
// why: extern "C" because the C++ form of the accepted definition failed the isolated link (probe linker script defines only the plain symbol)
extern "C" u32 func_0029dd00();
// why: reads no argument register; its final call is into accepted-void Selector::SetState, so its v0 is stale
extern "C" void func_0029be08(void);

void func_0029c880(s8* object, s32 mode) {
    u8* menu;
    s32 index;
    s32 column;
    s32 row;

    D_0035f5c4 = mode;
    D_0035f5ac[5] = object[0];
    menu = D_0035f5ac;
    menu[4] = (mode == 6) ? *(u8*)func_00276568() : 16;
    for (index = 0; index < object[0]; index++) {
        // why: volatile read because the original reloads the pointer on every iteration
        *(u16*)(*(u8* volatile*)&D_0035f5ac + 8 + index * 2) = *(u16*)(object + 80 + index * 8);
    }
    func_00287bd0(16, 0);
    func_0029dd00();
    column = object[1];
    row = 0;
    if (column >= 10) {
        row = column - 9;
        column = 9;
    }
    func_002765e8(15, column, row);
    func_0029be08();
}
