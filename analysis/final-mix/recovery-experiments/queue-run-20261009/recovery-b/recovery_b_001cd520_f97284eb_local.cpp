#include "../common/types.h"
struct __attribute__((packed)) Record { u64 first; s16 second; };
extern "C" Record D_01d5a970;
Record* func_001cd520(Record* p) { u64 a=D_01d5a970.first;s16 c=D_01d5a970.second;p->first=a;p->second=c;return p; }
