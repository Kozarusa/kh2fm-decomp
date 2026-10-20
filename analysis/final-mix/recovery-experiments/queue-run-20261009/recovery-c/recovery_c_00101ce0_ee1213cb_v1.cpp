#include "../common/types.h"
typedef void (*Callback)(void);
extern "C" char D_0037a6e4;
void func_00101ce0(void){
register Callback *end asm("$15")=(Callback*)&D_0037a6e4;asm("" : "+r"(end));Callback *cursor=end-1;
Callback callback=*cursor;
while(callback!=(Callback)(long)-1){--cursor;callback();callback=*cursor;}
}
