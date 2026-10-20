#include "../common/types.h"
extern "C" u32 func_00321728(s32,u32,u8);
extern "C" void func_001d4f40(u32,u16);
void func_001d4ef0(u32 param_1,u8 *param_2)

{
  int iVar1;
  
  iVar1 = func_00321728((int)param_1 + 0x38,1,*param_2);
  register u32 byte asm("$6")=*(u8*)(iVar1+1); asm("" : : "r"(byte)); register u32 finalObject asm("$4"), incremented asm("$15"); asm("daddu %0,%1,$0" : "=r"(finalObject) : "r"(param_1),"r"(byte)); asm("addiu %0,%1,1" : "=r"(incremented) : "r"(byte),"r"(finalObject)); *(u8*)(iVar1+1)=incremented;
  func_001d4f40(finalObject,*(u16 *)(param_2 + 0x42));
  return;
}
