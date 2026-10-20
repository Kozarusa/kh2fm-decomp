#include "../common/types.h"
u64 func_001339d0(volatile u32*cursor,u64 next,u32 tag,u32 third,u32 fourth) {
 ((u8*)(*cursor))[2]=0;
 ((u32*)(*cursor))[2]=third;
 ((u32*)(*cursor))[3]=fourth;
 ((u8*)(*cursor))[3]=48;
 ((u32*)(*cursor))[1]=(u32)next;
 ((u16*)(*cursor))[0]=(u16)tag;
 *cursor=*cursor+16; return next;
}
