#include "../common/types.h"
extern "C" s32 D_0035dcf0;
extern "C" u8 D_0035db00[];
extern "C" void func_00225fa0(s32,s32);
extern "C" void func_00227930(u8*);
void func_002278e0(u8* object) {
 if (D_0035dcf0) {
  func_00225fa0((s32)D_0035db00,*(s32*)(object+24));
  func_00227930(object);
 }
}
