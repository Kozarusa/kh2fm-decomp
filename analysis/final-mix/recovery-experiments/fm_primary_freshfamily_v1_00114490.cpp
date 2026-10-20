#include "../common/types.h"
// Complete-range fresh proposal, pending independent original-byte proof.
s32* func_00114490(u32 object,s32 value) { u32 root=*(u32*)(object+8); if(root) { s32 index=0; if(*(s32*)(root+0xb0)>0) { s32 offset=0; do { s32* item=(s32*)(offset+root+*(s32*)(root+0xb4)); ++index; if(*item==value) return item; offset=index*0x80; } while(index<*(s32*)(root+0xb0)); } } return 0; }
