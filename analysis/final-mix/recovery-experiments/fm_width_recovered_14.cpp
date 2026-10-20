#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00181500(...);
extern "C" bool func_002944d0(...);
extern "C" s32 func_001d56c8(...);
extern "C" s32 func_002924d0(...);
extern "C" s32 func_00295158(...);
extern "C" s32 func_0029a5f0(...);
extern "C" s32 func_002a9d68(...);
extern "C" s32 func_002aa5b8(...);
extern "C" s32 func_002abf40(...);
extern "C" s32 func_002b6708(...);
extern "C" u32 func_00102448(...);
extern "C" u32 func_00102818(...);
extern "C" u32 func_00102a38(...);
extern "C" u32 func_00103eb0(...);
extern "C" u32 func_001058e8(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00192048(...);
extern "C" u32 func_002538f8(...);
extern "C" u32 func_00253928(...);
extern "C" u32 func_002539e8(...);
extern "C" u32 func_00276150(...);
extern "C" u32 func_00276568(...);
extern "C" u32 func_002766d0(...);
extern "C" u32 func_00276c18(...);
extern "C" u32 func_00287bc0(...);
extern "C" u32 func_0028da70(...);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_00294000(...);
extern "C" u32 func_0029df98(...);
extern "C" u32 func_0029e050(...);
extern "C" u32 func_0029e258(...);
extern "C" u32 func_002b3c38(...);
extern "C" u32 func_00192e50(...);
extern "C" u32 func_00242618(...);
extern "C" u32 func_002941a8(...);
extern "C" u32 func_002941d8(...);
extern "C" u8 func_001a3570(...);
extern "C" u8 func_00253918(...);
extern "C" u8 func_00292520(...);

void func_0029aa30(void)

{
  s32 lVar1;
  
  lVar1 = func_00287bc0(); asm volatile("" ::: "memory");
  if (((((((int)lVar1 - 0xeU < 2) || (lVar1 == 0x12)) || (lVar1 == 0x15)) ||
       ((lVar1 == 0x10 || (lVar1 == 0x13)))) ||
      ((lVar1 == 0x16 || ((lVar1 == 0x11 || (lVar1 == 0x14)))))) || (lVar1 == 0x17)) {
    func_0029df98(); asm volatile("" ::: "memory");
    func_0029e050(); asm volatile("" ::: "memory");
    func_0029e258(0); asm volatile("" ::: "memory");
    func_0029e258(1); asm volatile("" ::: "memory");
  }
  return;
}
