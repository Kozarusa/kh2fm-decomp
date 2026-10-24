#include "../common/types.h"

f32 func_0011bd70(f32* object)
{
  f32 first = object[4] * object[8] - object[5] * object[7];
  f32 second = object[3] * object[8] - object[5] * object[6];
  f32 third = object[3] * object[7] - object[4] * object[6];
  return object[2] * third + (object[0] * first - object[1] * second);
}
