#include "../common/types.h"
extern "C" bool func_001bb4b0(void);
extern "C" u32 func_001bbcb0(void);
extern "C" u32 func_001d8718(s32,s32);
void func_001d86a0(u32 param_1,u32 param_2)

{
  register u32 iVar1 asm("$2");
  s32 lVar2; register s32 offset asm("$14");
  
  lVar2 = func_001bb4b0();
  if ((__builtin_expect(lVar2 != 0,1)) &&
     (iVar1 = func_001bbcb0(), offset=(int)param_2*0x38, ({asm("" : "+r"(offset));}), (*(u32 *)(iVar1 = iVar1 + offset, iVar1 + 0xf4) & 1) != 0)) {
    func_001d8718(param_1,param_2);
    return;
  }
  return;
}