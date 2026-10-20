#include "../common/types.h"
// Complete-range fresh proposal, pending independent original-byte proof.
extern "C" s64 func_00190140(void); extern "C" u64 func_00112d28(s32);
u64 func_00112d90(s32* object) { bool found=false; s64 available=func_00190140(); u64 result=0; if(available) found=*object!=0; if(found) result=func_00112d28(*object); return result; }
