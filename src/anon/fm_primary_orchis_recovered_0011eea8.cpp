#include "../common/types.h"

void func_0011eea8(u8* object, u8* value)
{
  register u8* pointer asm("$15") = *(u8**)(object + 8); // why: original first node uses t7
  if (pointer == value) {
    *(u8**)(object + 8) = *(u8**)(value + 4);
    return;
  }
  register u8* previous asm("$13") = pointer; // why: original predecessor uses t5
  register u8* next asm("$14") = *(u8**)(pointer + 4); // why: original next node uses t6
  while (next != 0 && next != value) {
    u8* loaded = *(u8**)(next + 4);
    previous = next;
    next = loaded;
  }
  *(u8**)(previous + 4) = *(u8**)(value + 4);
}
