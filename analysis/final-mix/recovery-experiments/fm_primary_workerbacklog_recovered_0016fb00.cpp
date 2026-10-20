#include "../common/types.h"

asm(".globl PTR_0035dc98
	PTR_0035dc98 = 0x35dc98
");

extern "C" u32 PTR_0035dc98;

typedef void (*code)(u32, u32);

void func_0016fb00(u32 param_1)
{
  (*(code *)(*(u32 *)PTR_0035dc98 + 4))(PTR_0035dc98, param_1);
  asm volatile ("");
}
