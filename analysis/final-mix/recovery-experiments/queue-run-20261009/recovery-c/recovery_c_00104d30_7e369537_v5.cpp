#include "../common/types.h"
extern "C" char D_0032bb30;
extern "C" void func_00104cf0(u16*,const u16*);
void func_00104d30(u8*out,const u8*in){register u32 a asm("$10")=in[0];register u32 b asm("$9")=in[1];register u32 c asm("$11")=in[2];asm("" : "+r"(a),"+r"(b),"+r"(c));out[0]=a;out[2]=c;out[1]=b;asm("" : "+r"(out));u16*table=(u16*)(&D_0032bb30+a*384+b*6);register u16 third asm("$11")=table[10];register u16 first asm("$15")=table[8];register u16 second asm("$12")=table[9];asm("" : "+r"(third),"+r"(first),"+r"(second));*(u16*)(out+4)=first;*(u16*)(out+6)=second;*(u16*)(out+8)=third;func_00104cf0((u16*)(out+4),(const u16*)(in+4));}
