#include "common.h"
#include "src/io/viint.h"

void func_800DC840(f32 value) 
{
    register u32 saveMask;
    saveMask = __osDisableInt();
    /*__osViNext*/(D_80109E94)->y.factor = value;
    /*__osViNext*/(D_80109E94)->state |= VI_STATE_YSCALE_UPDATED;
    __osRestoreInt(saveMask);
}
