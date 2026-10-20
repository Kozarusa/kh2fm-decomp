#include "../common/types.h"
struct __attribute__((packed)) Record { u64 first; s16 second; };
extern "C" Record D_01d5a970;
Record* func_001cd520(Record* p) { p->first=D_01d5a970.first;p->second=D_01d5a970.second;return p; }
