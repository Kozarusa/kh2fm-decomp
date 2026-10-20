#include "../common/types.h"

void func_00101d38(void)
{
  asm volatile ("addiu $sp, $sp, -16
	"
                "sd $ra, 0($sp)
	"
                "ld $ra, 0($sp)
	"
                "addiu $sp, $sp, 16");
  return;
}
