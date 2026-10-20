#include "../common/types.h"
extern "C" s32 func_00242b58();
u32 func_001585a0(u64*object) { u32 set=0;if(*object & ((u64)1<<32)) set=1; s32 state=func_00242b58(); if(state==0) set=(set==0); return set;}
