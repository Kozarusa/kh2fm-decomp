#include "../common/types.h"

extern "C" s16* D_0035f230;

s32 func_0027ae20()
{
  s32 count = 0;
  s32 index = 0;
  do {
    if (index != 6) {
      if (((*D_0035f230 >> index) ^ 1) & 1) {
      } else {
        count = count + 1;
      }
    }
    index = index + 1;
  } while (index < 7);
  if ((*(u16*)D_0035f230 & 0x80) != 0) {
    count = count + 1;
  }
  return count;
}
