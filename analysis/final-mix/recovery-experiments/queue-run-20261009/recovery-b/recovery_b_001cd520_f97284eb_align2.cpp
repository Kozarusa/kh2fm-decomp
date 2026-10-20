#include "../common/types.h"
struct __attribute__((packed,aligned(2))) Record { u64 first; s16 second; };
extern "C" Record D_01d5a970;
Record* func_001cd520(Record* p) { *p=D_01d5a970;return p; }
