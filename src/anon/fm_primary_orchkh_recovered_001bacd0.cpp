#include "../common/types.h"
extern "C" u32 D_01d49324;
extern "C" u32 D_0034f240;
extern "C" u32 func_001708f8(...);
extern "C" u8* func_00168b38(u32, s32, s32);
// why: type of the accepted misc_1.cpp definition; extern "C" because C++ linkage fails the isolated probe link
extern "C" void func_001d5458(void* self);
// why: type of the accepted ys/traps.cpp declaration of YS::STATUS::CageOn; extern "C" func_ name because the isolated probe link defines only func_ symbols
extern "C" void func_00191990(void);

// why: void per DEVIATIONS #36 (accepted declaration void func_001bacd0(u32) in auto200_999.cpp);
// exits: flag 0x1 clear -> stale-b (void func_001d5458 last), flag set -> direct (func_00191990 last)

void func_001bacd0(u8* object) {
    u32 buffer = func_001708f8(object + 40, -1);
    *(u32*)(object + 72) = buffer;
    u8* info = func_00168b38(buffer, 2, 0);
    u8* status = *(u8**)(info + 8);
    func_001d5458(status);
    *(u32*)(object + 8) = (u32)status;
    D_01d49324 = (u32)status;
    if (*(u16*)(*(u32*)(object + 8) + 4) & 0x1) {
        func_00191990();
    }
    if (*(u16*)(*(u32*)(object + 8) + 4) & 0x20) {
        D_0034f240 |= 0x4;
    }
    if (*(u16*)(*(u32*)(object + 8) + 4) & 0x40) {
        D_0034f240 |= 0x200;
    }
    if (*(u16*)(*(u32*)(object + 8) + 4) & 0x80) {
        D_0034f240 |= 0x400;
    }
    if (*(u16*)(*(u32*)(object + 8) + 4) & 0x100) {
        D_0034f240 |= 0x8000;
    }
}
