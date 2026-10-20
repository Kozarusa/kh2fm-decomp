#include "../common/types.h"
// Provisional decompiler recovery; no exactness is assumed.


int func_00132018(short *param_1)



{

  while( true ) {

    if (param_1 == (short *)0x0) {

      return 0;

    }

    if (__builtin_expect(*param_1 != -1,0)) break;

    param_1 = (short *)((int)param_1 + *(int *)(param_1 + *(int *)(param_1 + 2) * 2 + 2));

  }

  if (*param_1 != 0) {

    return 0;

  }

  return (int)param_1 + *(int *)(param_1 + 0x10) + *(int *)(param_1 + 2) * 4;

}



