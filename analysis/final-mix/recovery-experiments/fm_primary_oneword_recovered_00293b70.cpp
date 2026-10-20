#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00181500(s64);
extern "C" bool func_002944d0(void*);
extern "C" s32 func_001d56c8(...);
extern "C" s32 func_002924d0(s32,s64);
extern "C" s32 func_00295158(s32);
extern "C" s32 func_0029a5f0(...);
extern "C" s32 func_002a9d68(void);
extern "C" s32 func_002aa5b8(s8,s32);
extern "C" s32 func_002abf40(s8,s32);
extern "C" s32 func_002b6708(...);
extern "C" u32 func_00102448(s32,u32);
extern "C" u32 func_00102818(u64,u64,u64,u64,s32);
extern "C" u32 func_00102a38(s32,s32);
extern "C" u32 func_00103eb0(void);
extern "C" u32 func_001058e8(void);
extern "C" u32 func_00139d78(s32);
extern "C" u32 func_00192048(u64);
extern "C" u32 func_002538f8(s32);
extern "C" u32 func_00253928(s32);
extern "C" u32 func_002539e8(s32,void*);
extern "C" u32 func_00276150(...);
extern "C" u32 func_00276568(void);
extern "C" u32 func_002766d0(void);
extern "C" u32 func_00276c18(void);
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_0028da70(u64,s32);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_00294000(u64);
extern "C" u32 func_0029df98(...);
extern "C" u32 func_0029e050(...);
extern "C" u32 func_0029e258(...);
extern "C" u32 func_002b3c38(...);
extern "C" u64 func_00192e50(...);
extern "C" u64 func_00242618(u64,s8);
extern "C" u64 func_002941a8(void*);
extern "C" u64 func_002941d8(...);
extern "C" u8 func_001a3570(...);
extern "C" u8 func_00253918(void);
extern "C" u8 func_00292520(u64,s64,s64);

// Address-only symbol; original data/callback type remains provisional.
extern u8 D_00293b08;

void func_00293b70(void)

{
  int iVar1;
  
  iVar1 = func_00103eb0(); asm volatile("" ::: "memory");
  func_00102a38(*(u32 *)(iVar1 + 4),(u32)&D_00293b08); asm volatile("" ::: "memory");
  return;
}
