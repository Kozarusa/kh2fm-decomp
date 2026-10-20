#include "../common/types.h"
extern s32 D_0035f230;
bool func_0027bf20(int index)
{
  bool result;
  int pointer;
  register s32 count asm("$12"); // why: original halfword difference and clamped count use t4
  result = true;
  pointer = index * 8 + D_0035f230;
  count = (int)*(short *)(D_0035f230 + 2);
  asm("" : "+r"(count)); // why: retains original first halfword read in t4
  count = count - (int)*(short *)(D_0035f230 + 4);
  if (count < 0) {
    count = 0;
  }
  if (*(char *)(pointer + 0xe) == '\0') {
    result = *(char *)(pointer + 0x11) <= count;
  }
  return result;
}



