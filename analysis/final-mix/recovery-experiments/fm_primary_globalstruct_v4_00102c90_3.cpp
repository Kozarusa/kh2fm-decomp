#include "../common/types.h"
struct GlobalState { u32 table, zero; u8 tag; u8 pad[3]; u32 reserved; u32 unknown; u32 enabled, count, clear1, clear2, clear3, limit; };
extern "C" char D_0032b930;
extern "C" volatile GlobalState D_0032b968;
void func_00102c90(s64 first,s64 second) { if(second==0xffff && first==1) { volatile GlobalState* state=&D_0032b968; register u32 enabled asm("$4")=(u32)first; asm("" : "+r"(enabled)); state->table=(u32)&D_0032b930; state->enabled=enabled; state->count=130000; state->limit=0x3800; state->tag=0x46; state->zero=0; state->clear1=0; state->clear2=0; state->clear3=0; } }
