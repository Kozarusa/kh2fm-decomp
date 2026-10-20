#include "../common/types.h"
extern "C" u32 func_00192048(u32);
extern "C" void func_002595e8(u32,u32);
extern "C" char func_00373970;

// Keep the table lookup and preserved return value in C++.
// This narrow call block preserves original argument transport: the second
// argument is copied in the jal delay slot. Clobbers match existing EE call glue.

u32 func_00271828(u32 index,u32 preserved) {
register u32 argument asm("$4")=*(u32*)((u32)(long)&func_00373970+index*4);asm ("" : "+r"(argument));register u32 result asm("$2")=func_00192048(argument);
asm volatile(".set push; .set noreorder; daddu $4,%1,$0; jal func_002595e8; daddu $5,%0,$0; .set pop"
 : "+r"(result) : "r"(preserved)
 : "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "$31", "memory");
asm volatile("" ::: "$31");return preserved;
}
