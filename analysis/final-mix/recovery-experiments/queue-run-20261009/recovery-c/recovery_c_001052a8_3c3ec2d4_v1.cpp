#include "../common/types.h"
extern "C" u8 D_0032bae0[];
extern "C" u8 D_0032bb30[];
extern "C" void func_00104d30(u8*,const u8*);
void func_001052a8(const u8*input){register u8*header asm("$16")=D_0032bae0;asm("" : "+r"(header));func_00104d30(header,input);u8 a=D_0032bae0[0],c=header[2],b=header[1];u8*table=D_0032bb30;table[14]=c;table[12]=a;table[13]=b;}
