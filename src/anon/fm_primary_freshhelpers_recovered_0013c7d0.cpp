#include "../common/types.h"
// Provisional decompiler recovery; exactness requires independent proof.
extern "C" s64 func_0013c738(u32);
extern "C" u32 D_003484a0;
extern "C" u8 D_003484a4;

u32 func_0013c7d0(void)



{

  s64 lVar1;

  

  if (D_003484a0 != 0) {

    lVar1 = func_0013c738(D_003484a0);

    if (lVar1 != 0) {

      return 1;

    }

    if (D_003484a4 == '\x01') {

      return 1;

    }

  }

  return 0;

}
