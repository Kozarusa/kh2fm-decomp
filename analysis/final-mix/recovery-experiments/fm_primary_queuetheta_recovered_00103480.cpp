#include "../common/types.h"
extern "C" u8 D_0032ba28,D_0032ba1c;
extern "C" u32 D_0032ba20;
extern "C" char D_0032b9e8;
extern "C" void func_001031d0(void),func_00103100(void),func_00103ea0(s64),func_00103500(s64),func_00103c70(void),func_00103e78(void),func_0023ed90(void);
extern "C" u32 func_001384c0(void);

void func_00103480(void){D_0032ba28=0;func_00103ea0(0);volatile u32*table=(volatile u32*)&D_0032b9e8;table[9]=(u32)&func_001031d0;table[8]=(u32)&func_00103100;func_00103500(-1);func_00103c70();func_00103e78();func_0023ed90();D_0032ba20=-1;D_0032ba1c=func_001384c0();}
