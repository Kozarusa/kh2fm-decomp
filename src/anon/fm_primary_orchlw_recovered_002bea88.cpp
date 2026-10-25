#include "../common/types.h"

// why: byte flag set to 1 on entry (sb)
extern "C" u8 D_00361898;
// why: declaration copied from the accepted 00191bf0, which reads a float field of it
extern "C" u8* D_00352130;

// why: worldmap::Menu::initialize(); no argument registers are set before the call
extern "C" void func_002be6f0();
// why: no accepted using site; called with no argument setup and the result unused
extern "C" void func_001c8e90();
// why: worldmap::CameraManager::get(); its v0 is passed straight to 002c6190 as a0
extern "C" u8* func_002c6218();
// why: declaration copied from the accepted caller 002c6158
extern "C" void func_002c6190(u8*);
// why: declaration copied from the accepted caller 001a6c60 (AREA::Alloc)
extern "C" u32 func_001050d8(u64);
// why: no accepted using site; receives the allocated block in a0
extern "C" void func_002bf098(u32 block);
// why: type of the accepted definition 00191bf0; extern "C" because the probe linker
// script defines only the plain symbol (the C++ form failed to link in v1), and the
// full build resolves plain func_<addr> names via alias generation
extern "C" void func_00191bf0(f32 scalar);
// why: declaration copied from the accepted 00191bf0
extern "C" void func_00191c30(f32);
// why: declaration copied from the accepted caller 002be9b0
extern "C" s32 func_002c1dc0();
// why: no accepted using site; called with no argument setup and the result unused
extern "C" void func_002c1750();
// why: no accepted using site; one word argument (a0 = 0). Its tail chain ends in the
// accepted void 001398d0 (via 002bfa98), so it leaves no return value
extern "C" void func_002bf9d8(s32 mode);

void func_002bea88()
{
    // the two constants are the read-only float literals 4.0 (00375 3f4) and 500.0 (003753f8)
    D_00361898 = 1;
    f32 scale = 4.0f;
    func_002be6f0();
    func_001c8e90();
    func_002c6190(func_002c6218());
    func_002bf098(func_001050d8(160));
    func_00191bf0(scale);
    func_00191c30(*(f32*)(D_00352130 + 0x4c) * scale + 500.0f);
    func_002c1dc0();
    func_002c1750();
    func_002bf9d8(0);
}
