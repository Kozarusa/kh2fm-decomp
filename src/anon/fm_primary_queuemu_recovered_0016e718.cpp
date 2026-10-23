#include "../common/types.h"
extern "C" void func_00188b68(u32,u32,bool);

// Preserve original registry aliases.
void func_0016e718(const u32* record) asm("_ZN2YS24trap_partram_add_abilityEP8BD_VALUE");

void func_0016e718(const u32* record){register u32 first asm("$15")=record[0];asm("" : "+r"(first));func_00188b68(first,record[1],record[2]!=0);}
