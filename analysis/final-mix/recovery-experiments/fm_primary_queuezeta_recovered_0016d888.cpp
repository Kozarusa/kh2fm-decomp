#include "../common/types.h"
#include "../kn/fvector.hpp"
struct VectorPair { const kn::FVector* first; const kn::FVector* second; };
extern "C" kn::FVector D_004f62a0;
// Publish the xyz cross product with a zero w lane into shared vector storage,
// then redirect the pair's first pointer to that storage.

void func_0016d888(VectorPair* pair)
{
 kn::FVector temporary;
 register const kn::FVector* first asm("$15")=pair->first;
 register const kn::FVector* second asm("$14")=pair->second;
 asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vsub.xyzw $vf3,$vf0,$vf0; vopmula.xyz ACC,$vf1,$vf2; vopmsub.xyz $vf3,$vf2,$vf1; sqc2 $vf3,%0"
              : "=m"(temporary) : "r"(first),"r"(second) : "memory");
 D_004f62a0=temporary;
 pair->first=&D_004f62a0;
}
