#include "../common/types.h"

void func_001003b0(void)
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
