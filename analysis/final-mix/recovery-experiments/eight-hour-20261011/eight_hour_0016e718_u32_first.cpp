#include "../common/types.h"
extern "C" void func_00188b68(u32,u32,u32);
void func_0016e718(const u32* record){register u32 first asm("$15")=record[0];asm("" : "+r"(first));func_00188b68(first,record[1],record[2]!=0);}
