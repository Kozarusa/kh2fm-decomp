#include "../common/types.h"
// Provisional decompiler recovery; exactness requires independent proof.
extern "C" void func_00168388(u64,u64,u32,u32);
extern "C" s64 func_00170cd0(void);
extern "C" void func_00102448(u64,u32);

void func_001367e0(u64 param_1,u64 param_2,u64 param_3)



{

  s64 lVar1;

  

  func_00168388(param_2,param_3,0,0);

  while (lVar1 = func_00170cd0(), lVar1 != 0) {

    func_00102448(param_1,0);

  }

  return;

}
