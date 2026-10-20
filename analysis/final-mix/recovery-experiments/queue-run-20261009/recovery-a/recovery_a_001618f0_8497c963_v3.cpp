#include "../common/types.h"
extern "C" u64 func_001069f8(...);
extern "C" u32 func_00102c18(u32,u32,s32);
extern "C" u64 func_00106998(...);
extern "C" u64 func_001617c8(...);
extern "C" char func_00161818;
extern "C" char func_001433e8;
extern "C" char func_00107888;
extern "C" char func_001dd2b8;
extern "C" char func_00144250;
extern "C" char func_00161880;
extern "C" char func_001618a0;
extern "C" char func_001dd920;
extern "C" char func_00167228;
extern "C" char func_0015de18;

void func_001618f0(void)

{
  int iVar1;
  
  func_001617c8();
  func_00106998(0);
  func_001069f8(0);
  func_00102c18(3,6000,(s32)(long)&func_00161818);
  func_00102c18(3,0x1771,(s32)(long)&func_001433e8);
  func_00102c18(3,30000,(s32)(long)&func_00107888);
  func_00102c18(3,41000,(s32)(long)&func_001dd2b8);
  func_00102c18(3,43000,(s32)(long)&func_00144250);
  func_00102c18(3,49999,(s32)(long)&func_00161880);
  func_00102c18(3,50000,(s32)(long)&func_001618a0);
  func_00102c18(3,0xea61,(s32)(long)&func_001dd920);
  iVar1 = func_00102c18(3,71000,(s32)(long)&func_00167228);
  *(u8 *)(iVar1 + 4) = 0;
  func_00102c18(3,65000,(s32)(long)&func_0015de18);
  return;
}
