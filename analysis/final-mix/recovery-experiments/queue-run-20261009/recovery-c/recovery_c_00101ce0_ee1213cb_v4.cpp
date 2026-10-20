#include "../common/types.h"
typedef void (*Callback)(void);
extern "C" char D_0037a6e4;
void func_00101ce0(void){
register Callback* end asm("$15")=(Callback*)&D_0037a6e4;asm("" : "+r"(end));
Callback* cursor=end-1;
Callback candidate=*cursor;
if(candidate!=(Callback)(long)-1){
register Callback active asm("$14");
asm("daddu %0,%1,$0" : "=r"(active) : "r"(candidate));
 do{--cursor;active();candidate=*cursor;asm("daddu %0,%1,$0" : "=r"(active) : "r"(candidate));}while(candidate!=(Callback)(long)-1);
}
}
