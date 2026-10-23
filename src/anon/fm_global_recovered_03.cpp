#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0030edb0(void);
extern "C" bool func_0030ee00(void);
extern "C" s32 func_002ff3fc(...);
extern "C" s64 func_0030ff08(void);
extern "C" s64 func_00310518(u32);
extern "C" u32 func_00101ce0(void);
extern "C" u32 func_00108698(void*);
extern "C" u32 func_0014b9a8(...);
extern "C" u32 func_001ddd10(void*);
extern "C" u32 func_002f3500(u64,u32,s32);
extern "C" u32 func_003032d0(u64,void*);
extern "C" u32 func_00310090(u32);
extern "C" u32 func_00310180(s64,s64);
extern "C" u32 func_00310230(u32);
extern "C" u32 func_00310330(u32);
extern "C" u32 func_00310670(u32,u64,s64,u32);
extern "C" u32 func_00311af0(...);
extern "C" u32 func_00313e80(u64,u64);
extern "C" u32 func_00313f40(u64,u64);
extern "C" u32 func_00314640(void*,void*);
extern "C" u32 func_00314698(u32,u32,u32,u32);
extern "C" u32 func_003147a0(void*,void*);
extern "C" u32 func_003149e8(u8);
extern "C" u32 func_00314b90(u8,void*,u64,void*);
extern "C" u32 func_00316e10(void);
extern "C" u64 func_00100350(...);
extern "C" u64 func_00138988(...);
extern "C" u64 func_00138de0(...);
extern "C" u64 func_00311aa0(u64,u64);
extern "C" u64 func_00313c58(u64,u64,u64);
extern "C" u64 func_00314330(u64);
extern "C" u64 func_003146c8(void*);

u32 func_00314dd8(int param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  u32 auStack_30 [4];
  
  uVar1 = func_003149e8(*(u8 *)(param_1 + 0x14));
  iVar2 = func_00311aa0(param_2,uVar1);
  func_00314b90(*(u8 *)(param_1 + 0x14),*(u32 *)(param_1 + 8),
               *(int *)(param_1 + 0xc) - iVar2,auStack_30);
  return auStack_30[0];
}
