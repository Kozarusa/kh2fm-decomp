#include "../common/types.h"
struct __attribute__((packed,aligned(2))) Record { union {u64 first;u8 bytes[8];};s16 second; };
extern "C" Record D_0032bae0,D_0032bb10;
extern "C" void func_0019ee80(u32,u32);
extern "C" void func_001d5198(Record*);
void func_00178220(void) { Record* p=&D_0032bae0;func_0019ee80(p->bytes[0],p->bytes[1]);D_0032bb10=*p;func_001d5198(p); }
