#include "../common/types.h"
extern "C" u64 func_00242b58();
bool func_001585a0(u64*object) { bool set=(*object & ((u64)1<<32))!=0; u64 state=func_00242b58(); if (state==0) set=!set; return set; }
