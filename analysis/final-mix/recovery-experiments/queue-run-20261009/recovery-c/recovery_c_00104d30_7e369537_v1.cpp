#include "../common/types.h"
extern "C" char D_0032bb30;
extern "C" void func_00104cf0(u16*,const u16*);
void func_00104d30(u8*out,const u8*in){u8 a=in[0],b=in[1],c=in[2];out[0]=a;out[2]=c;out[1]=b;u16*table=(u16*)(&D_0032bb30+a*384+b*6);u16 third=table[10],second=table[9],first=table[8];*(u16*)(out+4)=first;*(u16*)(out+6)=second;*(u16*)(out+8)=third;func_00104cf0((u16*)(out+4),(const u16*)(in+4));}
