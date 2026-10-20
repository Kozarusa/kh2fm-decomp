#include "../common/types.h"

typedef void (*code)(void);

extern "C" void func_002fd160(...);

void func_00315418(code param_1)
{
  (*param_1)();
  asm volatile ("");
  func_002fd160();
}
