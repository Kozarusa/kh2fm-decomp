#include "../common/types.h"
extern "C" u32 D_00361f60;
extern "C" void func_002ceb08(void);

// Preserve original registry aliases.
u32 func_002e2e18(void) asm("_ZN2Ti12MG_EHSidecar15GetCurrentPointEv");

u32 func_002e2e18(void)
{
 register u32 saved asm("$16")=D_00361f60;
 if(saved!=0)func_002ceb08();
 return *(u32*)(saved+264);
}
