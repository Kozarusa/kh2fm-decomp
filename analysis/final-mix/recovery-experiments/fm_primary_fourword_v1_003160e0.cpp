#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_00100350(...);
extern "C" u64 func_00101ce0(...);
extern "C" u64 func_00108698(...);
extern "C" u64 func_00138988(...);
extern "C" u64 func_00138de0(...);
extern "C" u64 func_0014b9a8(...);
extern "C" u64 func_001ddd10(...);
extern "C" u64 func_002ff3fc(...);
extern "C" u64 func_003032d0(...);
extern "C" u64 func_0030edb0(...);
extern "C" u64 func_0030ee00(...);
extern "C" u64 func_0030ff08(...);
extern "C" u64 func_00310518(...);
extern "C" u64 func_00310670(...);
extern "C" u64 func_00311aa0(...);
extern "C" u64 func_00311af0(...);
extern "C" u64 func_00313c58(...);
extern "C" u64 func_00313f98(...);
extern "C" u64 func_003141e8(...);
extern "C" u64 func_00314698(...);
extern "C" u64 func_003146c8(...);
extern "C" u64 func_003147a0(...);
extern "C" u64 func_003149e8(...);
extern "C" u64 func_00314b90(...);

u32 func_003160e0(int param_1,int param_2,u32 param_3,volatile u32 *param_4)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_2 + 4)) {
    *param_4 = param_3;
    param_4[1] = 6;
    param_4[3] = 8;
    return 1;
  }
  return 0;
}
