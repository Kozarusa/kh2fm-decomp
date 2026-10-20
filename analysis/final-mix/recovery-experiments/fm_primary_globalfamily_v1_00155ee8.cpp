#include "../common/types.h"
// Provisional compiler proposal; types remain subject to original-byte proof.

u32 func_00155ee8(int param_1)

{
  if (*(int *)(param_1 + 0x34) != 0) {
    switch(*(u8 *)(*(int *)(*(int *)(param_1 + 0x34) + 0x48c) + 0x1af)) {
    case 2:
      return 0x32;
    case 3:
      return 0x8c;
    case 4:
      return 0x12;
    }
  }
  return 0x15;
}

