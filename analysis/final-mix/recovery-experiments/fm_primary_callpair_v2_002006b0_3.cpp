#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001bb4a0(void);
extern "C" bool func_002282f0(...);
extern "C" s32 func_00102180(void*);
extern "C" s32 func_001e0cc8(...);
extern "C" s32 func_001e0ce8(s32);
extern "C" s32 func_001e3650(...);
extern "C" s64 func_001dba18(...);
extern "C" s8 func_00225b00(s32);
extern "C" u32 func_001024a8(void*);
extern "C" u32 func_00102c18(u64,u64,u64);
extern "C" u32 func_00102c80(void);
extern "C" u32 func_00104190(void);
extern "C" u32 func_001050d8(u64);
extern "C" u32 func_001391a8(s32,void*);
extern "C" u32 func_00143fc8(u64,u64);
extern "C" u32 func_0015c958(s32,u8,u8,u8,s32,s32);
extern "C" u32 func_001671e8(s32,u8);
extern "C" u32 func_00167218(void);
extern "C" u32 func_001bbcb0(void);
extern "C" u32 func_001d1b60(u64,s32);
extern "C" u32 func_001db950(...);
extern "C" u32 func_001dc700(s32,s8);
extern "C" u32 func_001dc840(s32);
extern "C" u32 func_001dc978(f32,s32);
extern "C" u32 func_001dca20(...);
extern "C" u32 func_001dde40(void*);
extern "C" u32 func_001de4b0(s32,u64,s32);
extern "C" u32 func_001de8a8(u64,u64,u64,u64);
extern "C" u32 func_001e0058(s64);
extern "C" u32 func_001e0158(...);
extern "C" u32 func_001e01b8(u64);
extern "C" u32 func_001e02f8(u32);
extern "C" u32 func_001e03b0(void*);
extern "C" u32 func_001e17b8(...);
extern "C" u32 func_001e18d8(...);
extern "C" u32 func_001e1988(...);
extern "C" u32 func_001e3468(s32);
extern "C" u32 func_001e3660(u64,s32);
extern "C" u32 func_001e38f8(void*,s32,s16,s16);
extern "C" u32 func_001e3a88(void*,s32,s16,s16);
extern "C" u32 func_001e3c98(void*,s32);
extern "C" u32 func_001e3e48(void*,s32);
extern "C" u32 func_001e4028(void*,s32);
extern "C" u32 func_001e6000(...);
extern "C" u32 func_001fa950(...);
extern "C" u32 func_001fab48(...);
extern "C" u32 func_001facf8(...);
extern "C" u32 func_00209178(s32,void*);
extern "C" u32 func_0020e2e8(...);
extern "C" u32 func_0021fa10(void*);
extern "C" u32 func_0021fbc0(...);
extern "C" u32 func_0021fe28(...);
extern "C" u32 func_00220070(...);
extern "C" u32 func_002223e0(void*);
extern "C" u32 func_002247e8(void);
extern "C" u32 func_002248f8(s32);
extern "C" u32 func_002249b8(void);
extern "C" u32 func_002251c8(u64);
extern "C" u32 func_00227ca8(void*);
extern "C" u32 func_00229b28(u32,s32,s32,u64,u64);
extern "C" u32 func_002f1460(u32,u32,u32,u32,void*,u32);
extern "C" u32 func_002f1670(s32);
extern "C" u32 func_002f3f88(void*,void*);
extern "C" u32 func_002fd348(u64);
extern "C" u32 func_002fdfc8(...);
extern "C" u32 func_002fe0a0(...);
extern "C" u32 func_00313b80(u32);
extern "C" u32 func_00321cb0(void*,s32);
extern "C" u32 func_00321ce8(void*,s32);
extern "C" u64 func_0022b688(u64);

extern "C" u8 D_00354bc0[], D_00354be0[];

void func_002006b0(int param_1,int param_2)

{
  register s32 value asm("$16") = param_1 + *(int *)(*(int *)(param_2 + 0xc) + 4);
  func_002f3f88(value + 0xa0,(s32)D_00354bc0); asm volatile("" ::: "memory");
  func_002f3f88(value + 0xb0,(s32)D_00354be0); asm volatile("" ::: "memory");
  return;
}
