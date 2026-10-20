#include "../common/types.h"
extern s32 D_0035f230;
bool func_0027bf20(int index)
{
  bool result;
  int pointer;
  s32 count;
  result = true;
  pointer = index * 8 + D_0035f230;
  count = (s32)((int)*(short *)(D_0035f230 + 2) - (int)*(short *)(D_0035f230 + 4));
  if (count < 0) {
    count = 0;
  }
  if (*(char *)(pointer + 0xe) == '\0') {
    result = *(char *)(pointer + 0x11) <= count;
  }
  return result;
}
