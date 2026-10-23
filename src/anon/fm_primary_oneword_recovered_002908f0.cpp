#include "../common/types.h"

// Preserve original registry aliases.
void func_002908f0(int param_1) asm("_Z16u_call4_002908f0jjjj");

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00138470(void);
extern "C" bool func_00263660(...);
extern "C" bool func_0028b1c0(s32,u32);
extern "C" s32 func_00168aa0(void*,u64);
extern "C" s32 func_002570a0(...);
extern "C" s32 func_00273180(s32,u64);
extern "C" s32 func_0027ae20(void);
extern "C" s32 func_002859a0(void);
extern "C" u32 func_00102818(u64,u64,u64,u64,s32);
extern "C" u32 func_001039f8(void);
extern "C" u32 func_00103eb0(void);
extern "C" u32 func_001058e8(void);
extern "C" u32 func_00106450(s64);
extern "C" u32 func_001382e0(void);
extern "C" u32 func_001386e0(u64,u64,u64,u64,u64,u64);
extern "C" u32 func_00138c10(s32,u32);
extern "C" u32 func_00138c68(...);
extern "C" u32 func_00139570(s32);
extern "C" u32 func_00139660(...);
extern "C" u32 func_00139688(...);
extern "C" u32 func_001396b0(...);
extern "C" u32 func_00139d78(...);
extern "C" u32 func_00167f18(...);
extern "C" u32 func_00168b38(void*,u32,s32);
extern "C" u32 func_0017a798(void);
extern "C" u32 func_00192048(u64);
extern "C" u32 func_001a17c8(s32);
extern "C" u32 func_001a3888(...);
extern "C" u32 func_001a8110(s64);
extern "C" u32 func_002362b0(s32,s32);
extern "C" u32 func_002367c8(s32);
extern "C" u32 func_00239870(void*);
extern "C" u32 func_00239bf8(s32,s32);
extern "C" u32 func_0023aa18(...);
extern "C" u32 func_0023aa38(...);
extern "C" u32 func_0023aa98(...);
extern "C" u32 func_0023fa08(s32,u64);
extern "C" u32 func_002537c8(s32);
extern "C" u32 func_00257770(void);
extern "C" u32 func_002632d0(...);
extern "C" u32 func_002635d8(...);
extern "C" u32 func_00263ea8(void);
extern "C" u32 func_002657a8(void);
extern "C" u32 func_002666a8(void);
extern "C" u32 func_00266988(void);
extern "C" u32 func_0026d968(void);
extern "C" u32 func_0026e638(u64);
extern "C" u32 func_0026e8a0(void);
extern "C" u32 func_0027e6e0(...);
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_00287bd0(u32,u64);
extern "C" u32 func_00287da0(void);
extern "C" u32 func_00288be8(...);
extern "C" u32 func_00288f48(s32,u16,u16,u16,u16);
extern "C" u32 func_00289b30(u64,void*,void*);
extern "C" u32 func_0028b1b0(s32,u32);
extern "C" u32 func_0028be58(...);
extern "C" u32 func_0028d6e8(...);
extern "C" u32 func_0028da70(u64,s32);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_0028e4c8(s32,s32);
extern "C" u32 func_0028e510(s32,s32,u32);
extern "C" u32 func_0028e560(u64,void*,s32,u64);
extern "C" u32 func_00290060(...);
extern "C" u32 func_00290580(...);
extern "C" u32 func_00290740(void);
extern "C" u32 func_00290a60(...);
extern "C" u32 func_002fde18(void*,u8,u32);
extern "C" u32 func_0031a260(...);
extern "C" u64 func_00138440(void);
extern "C" u64 func_001a3820(...);
extern "C" u64 func_00257140(s32);
extern "C" u64 func_0028af18(s32,u64);
extern "C" u8 func_00287db0(void);

void func_002908f0(int param_1)

{
  if (*(u8 *)(param_1 + 0x10) != '\0') {
    func_00290a60();
  }
  *(u32 *)(param_1 + 4) = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    func_00106450(*(int *)(param_1 + 0x14));
    *(u32 *)(param_1 + 0x14) = 0;
  }
  return;
}
