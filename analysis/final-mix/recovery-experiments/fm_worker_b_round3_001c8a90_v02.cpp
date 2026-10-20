#include "../common/types.h"

asm(".globl DAT_01d49960\n\tDAT_01d49960 = 0x1d49960\n"
    ".globl DAT_01d49964\n\tDAT_01d49964 = 0x1d49964\n"
    ".globl DAT_01d49968\n\tDAT_01d49968 = 0x1d49968\n");

extern "C" u32 DAT_01d49960;
extern "C" u32 DAT_01d49964;
extern "C" u32 DAT_01d49968;

void func_001c8a90(void)
{
  DAT_01d49960 = 0;
  DAT_01d49964 = 0;
  DAT_01d49968 = 0;
}
