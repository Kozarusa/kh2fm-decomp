typedef signed char s8; typedef unsigned char u8;
typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
typedef long long s64; typedef unsigned long long u64;
extern "C" s64 sh16(s64 x){ return x << 16; }
extern "C" s64 sh32(s64 x){ return x << 32; }
extern "C" s64 sh48(s64 x){ return x << 48; }
extern "C" s64 mk(int a, int b){ return (s64)a | ((s64)b << 16); }
