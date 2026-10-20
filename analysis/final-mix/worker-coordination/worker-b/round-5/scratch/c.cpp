typedef long long s64;
typedef int s32;
extern "C" s64 mk(s32 a, s32 b){ return (s64)a | ((s64)b << 16); }
