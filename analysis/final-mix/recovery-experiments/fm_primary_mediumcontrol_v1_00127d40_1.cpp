#include "../common/types.h"
// Provisional decompiler recovery; no exactness is assumed.
extern "C" void func_00127f40(s32,s32);
extern "C" void func_001316f0(s32,s32);


u32 func_00127d40(u32 param_1)



{

  u32 uVar1;

  int iVar2;

  

  iVar2 = (int)param_1;

  if (*(int *)(iVar2 + 0x90) == 0) {

    func_00127f40(iVar2,iVar2 + 0x90);

    uVar1 = param_1;

  }

  else {

    uVar1 = 0;

    if (*(int *)(iVar2 + 0x90) == 1) {

      func_001316f0(iVar2,iVar2 + 0x90);

      uVar1 = param_1;

    }

  }

  return uVar1;

}



