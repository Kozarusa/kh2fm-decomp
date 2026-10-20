#include "../common/types.h"
typedef void (*Callback)(void);
struct CallbackTable{u8 padding[32];Callback first;Callback second;};
extern "C" volatile CallbackTable D_0032b968;
extern "C" u32 D_0032b994;
extern "C" void func_00102a70(void),func_00102b90(void),func_00102b58(void);
void func_00102bd8(void){D_0032b968.second=func_00102b90;asm volatile("" ::: "memory");D_0032b968.first=func_00102a70;D_0032b994=0;func_00102b58();}
