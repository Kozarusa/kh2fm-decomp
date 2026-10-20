#include "../common/types.h"

typedef void (*code)(u32, u32, u32);

void func_001231f8(u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7)
{
  (*(code *)(*(u32 *)p1 + 76))(p1, 0, (p6 & 0xff), p7);
  return;
}
