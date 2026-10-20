#include "../common/types.h"
u8* func_00100468(u8* cursor,u64* output){
u32 shift=0;
u64 value=0;
u8 byte;
do {
byte=*cursor++;
value|=(s64)(s32)((u32)(byte&0x7f) << shift);
shift+=7;
}while(byte&0x80);
if(shift<64 && (byte&0x40))value|=(~(u64)0)<<shift;
*output=value;
return cursor;
}
