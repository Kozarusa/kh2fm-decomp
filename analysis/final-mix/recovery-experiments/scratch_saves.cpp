#include "../common/types.h"

// How does the callee-save slot stride depend on the number of saved registers?
// Each probe keeps N values live across a call so GCC must spill them to s0..sN.
extern "C" s32 func_003105a0(...);

#define BODY(N)                                                       \
  u32 fn##N(u32 param_1)                                              \
  {                                                                   \
    u32 x1 = param_1 + 1;                                             \
    IF_N_2 u32 x2 = param_1 + 2;                                      \
    IF_N_3 u32 x3 = param_1 + 3;                                      \
    IF_N_4 u32 x4 = param_1 + 4;                                      \
    IF_N_5 u32 x5 = param_1 + 5;                                      \
    IF_N_6 u32 x6 = param_1 + 6;                                      \
    asm("" : "+r"(x1) BAR_2 BAR_3 BAR_4 BAR_5 BAR_6);                 \
    func_003105a0(x1);                                                \
    return x1 + SUM;                                                  \
  }

#define IF_N_2
#define IF_N_3
#define IF_N_4
#define IF_N_5
#define IF_N_6
#define BAR_2
#define BAR_3
#define BAR_4
#define BAR_5
#define BAR_6
#define SUM x1

BODY(1)
