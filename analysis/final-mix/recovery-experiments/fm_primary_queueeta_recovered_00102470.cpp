#include "../common/types.h"
extern "C" float D_00349e10;
extern "C" void func_00105620(void*,void*);

void func_00102470(float value,void* object){*(volatile float*)((char*)*(void*volatile*)((char*)object+52)+248)=value-D_00349e10;func_00105620(*(void*volatile*)((char*)object+52),(char*)*(void*volatile*)((char*)object+36)+32);}
