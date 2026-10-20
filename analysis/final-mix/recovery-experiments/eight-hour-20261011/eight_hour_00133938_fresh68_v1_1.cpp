#include "../common/types.h"
u8* func_00133938(u32*cursor,u32 next,u32 tag,u32 third,u32 fourth) {
 ((u8*)(*cursor))[2]=0;
 ((u32*)(*cursor))[2]=third;
 ((u32*)(*cursor))[3]=fourth;
 ((u8*)(*cursor))[3]=32;
 ((u32*)(*cursor))[1]=(u32)next;
 ((u16*)(*cursor))[0]=(u16)tag;
 u8*previous=(u8*)(*cursor); *cursor=(u32)next; return previous+16;
}
