#include "../common/types.h"
typedef void (*Callback)(void);
extern "C" char D_0037a6e4;
void func_00101ce0(void){
register Callback* end asm("$15")=(Callback*)&D_0037a6e4;asm("" : "+r"(end));
register Callback sentinel asm("$14")=(Callback)(long)-1;

Callback* cursor=end-1;
Callback initial=*cursor;
if(initial!=sentinel){
register Callback active asm("$14")=initial;
do{--cursor;active();register Callback next asm("$15")=*cursor;active=next;if(next==(Callback)(long)-1)break;}while(true);
}
}
