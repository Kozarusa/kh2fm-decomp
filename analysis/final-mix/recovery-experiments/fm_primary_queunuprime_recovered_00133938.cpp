#include "../common/types.h"
union HeaderCell {u32 word;u16 halves[2];u8 bytes[4];};

u8* func_00133938(HeaderCell*cursor,u32 next,u32 tag,u32 third,u32 fourth) {
 ((HeaderCell*)(cursor->word))[0].bytes[2]=0;
 ((HeaderCell*)(cursor->word))[2].word=third;
 ((HeaderCell*)(cursor->word))[3].word=fourth;
 ((HeaderCell*)(cursor->word))[0].bytes[3]=32;
 ((HeaderCell*)(cursor->word))[1].word=(u32)next;
 ((HeaderCell*)(cursor->word))[0].halves[0]=(u16)tag;
 u8*previous=(u8*)(cursor->word); cursor->word=(u32)next; return previous+16;
}
