#include "../common/types.h"
extern "C" void func_001b1be0(f32, u8*);

void func_001b1bb8(f32 scalar, u8* object, u32 first, u32 second, u32 third, u32 fourth)
{
  object[20] = (u8)first;
  // why: the original addresses the last three bytes through t7 = object+20
  register u8* cursor asm("$15") = object + 20;
  // why: keeps the cursor from being folded into the store offsets
  asm("" : "+r"(cursor));
  cursor[1] = (u8)second;
  cursor[2] = (u8)third;
  cursor[3] = (u8)fourth;
  func_001b1be0(scalar, object);
}
