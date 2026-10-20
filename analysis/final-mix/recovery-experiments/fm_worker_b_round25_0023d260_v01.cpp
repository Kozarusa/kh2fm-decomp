#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u8 DAT_00349e20;
asm(".globl DAT_00349e20
	DAT_00349e20 = 0x349e20
");
extern "C" volatile u32 DAT_00349e24;
asm(".globl DAT_00349e24
	DAT_00349e24 = 0x349e24
");
extern "C" volatile u8 DAT_0034eb50;
asm(".globl DAT_0034eb50
	DAT_0034eb50 = 0x34eb50
");
extern "C" volatile u32 DAT_0034eb54;
asm(".globl DAT_0034eb54
	DAT_0034eb54 = 0x34eb54
");
extern "C" void func_0023d2b0(void);
extern "C" void func_00253638(void);
extern "C" void func_00257000(void);

void func_0023d260(void)
{
  func_0023d2b0();
  func_00253638();
  func_00257000();
  DAT_0034eb50 = (DAT_00349e20 != 0);
  DAT_0034eb54 = DAT_00349e24;
  return;
}
