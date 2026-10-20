#include "../common/types.h"
extern "C" u32 func_00321728(s32,u32,u8);
extern "C" void func_001d4f40(u32,u16);
void func_001d4ef0(u32 param_1,u8 *param_2)

{
  int iVar1;
  
  iVar1 = func_00321728((int)param_1 + 0x38,1,*param_2);
  register u32 byte asm("$6")=*(u8*)(iVar1+1); asm("" : : "r"(byte)); *(u8*)(iVar1+1)=byte+1;
  func_001d4f40(param_1,*(u16 *)(param_2 + 0x42));
  return;
}
