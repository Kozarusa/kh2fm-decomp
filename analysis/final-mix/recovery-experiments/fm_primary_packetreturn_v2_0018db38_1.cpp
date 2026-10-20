#include "../common/types.h"
extern "C" u32 func_0018d940(void);
extern "C" u32 func_001c0320(u32,u32,void*);
extern "C" u32 func_0018da18(u32,u32,u32,u32);
// Preserve incoming byte transport until the original byte store, and use unsigned packet flags.
u32 func_0018db38(u32 param_1,u32 param_2,u32 param_3,u32 param_4) {
 unsigned char packet[16];
 u32 condition = func_0018d940();
 register u32 result asm("$15") = 0;
 if (condition != 0) {
  u32 intermediate=func_001c0320(param_2+0xa50,param_1,packet); u32 pointer=func_0018da18(param_1,param_2,intermediate,param_4);
  *(u8*)(pointer+0x24) = param_3;
  if(packet[0] == 0) { *(u32*)(pointer+0x18) |= 3;  }
  result = pointer;
 }
 asm volatile("" : "+r"(result));
 return result;
}
