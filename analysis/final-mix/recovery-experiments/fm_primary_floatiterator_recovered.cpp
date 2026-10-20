#include "../common/types.h"
// Complete-range fresh proposal, pending independent original-byte proof.
extern "C" u32 func_00132350(u32); typedef void (*VirtualIterate)(f32,u32);

void func_0011ea40(f32 payload,u32 object) { for(u32 item=*(u32*)(object+0x38); item; item=func_00132350(item)) (*(VirtualIterate*)(*(u32*)item+0x14))(payload,item); }
