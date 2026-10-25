#include "../common/types.h"
extern "C" u8* D_0035f634;
extern "C" u32 D_0035f3d4;
extern "C" u32 D_0035f14c;
extern "C" u32 D_0035f148;
extern "C" u32 D_0035f210;
extern "C" u8* D_0035f638;
extern "C" u32 func_002766d0(void);
extern "C" void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32);
extern "C" u64 func_00139620(...);
// why: the accepted asm-label form fails the isolated link (probe linker script defines only the plain symbol); types copied from the fm_width_recovered_12 definition
extern "C" void func_0028dcc0(u32, u32);
extern "C" u32 func_00192048(...);
extern "C" u32 func_002b23e0(...);
// why: a0 is the lhu halfword and a1 is -1 before the jal; v0 is passed on as a word
extern "C" u32 func_001a37e8(u32, s32);
extern "C" u64 func_00192e50(...);

// why: the only exit leaves the direct v0 result of func_00192e50 (accepted definition returns u8*), so the return is typed

u64 func_002b1af0(void) {
    u32 sequence = func_002766d0();
    u32 frame = D_0035f3d4 + 2;
    u8* cursor = D_0035f634 + 24212;
    func_0028d980(cursor, frame, D_0035f14c, D_0035f148, D_0035f210, 131, -1, -1, 0);
    func_00139620(cursor);
    func_0028dcc0((u32)cursor, sequence);
    *(s32*)(cursor + 432) = 2;
    u32 text = func_00192048(20688);
    u16* entry = (u16*)func_002b23e0(-1);
    u32 value = func_001a37e8(*entry, -1);
    u64 result = func_00192e50(text, D_0035f638 + 88, 64, value);
    *(u8**)(cursor + 408) = D_0035f638 + 88;
    return result;
}
