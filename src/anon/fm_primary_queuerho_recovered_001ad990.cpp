

// Preserve original registry aliases.
void func_001ad990(float start,float end,float duration,float* output) asm("_Z13func_001ad990jfff");

void func_001ad990(float start,float end,float duration,float* output)
{
 register float zero asm("$f0")=0.0f;
 if(zero<duration){
 float difference=end-start;
 output[0]=start;
 output[1]=difference/duration;
 }else{
 output[1]=zero;
 asm("" : "+r"(output) : "m"(output[1]));
 output[0]=end;
 }
}
