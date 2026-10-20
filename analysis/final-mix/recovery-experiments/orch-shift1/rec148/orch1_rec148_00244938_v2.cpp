#include "../common/types.h"
extern "C" bool func_001a6d08(u32);
bool func_00244938(s32 value) {
 s32 argument=1;
 bool result=true;
 if(value==0) { if(!func_001a6d08(argument)) return result; argument=118; }
 result=func_001a6d08(argument);
 return result;
}

