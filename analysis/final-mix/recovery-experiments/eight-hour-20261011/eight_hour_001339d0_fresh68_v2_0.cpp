#include "../common/types.h"
union HeaderCell {u32 word;u16 halves[2];u8 bytes[4];};
s64 func_001339d0(HeaderCell*cursor,s32 next,u32 tag,u32 third,u32 fourth) {
 ((HeaderCell*)(cursor->word))[0].bytes[2]=0;
 ((HeaderCell*)(cursor->word))[2].word=third;
 ((HeaderCell*)(cursor->word))[3].word=fourth;
 ((HeaderCell*)(cursor->word))[0].bytes[3]=48;
 ((HeaderCell*)(cursor->word))[1].word=(u32)next;
 ((HeaderCell*)(cursor->word))[0].halves[0]=(u16)tag;
 cursor->word=cursor->word+16; return next;
}

