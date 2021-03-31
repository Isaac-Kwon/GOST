#ifndef __GSCONSTANT__
#define __GSCONSTANT__ 1

#include "math.h"

namespace GSConstant{ // SI UnitSystem
    constexpr double Pi(){ return  3.1415926535; }
    constexpr double n0(){ return  1; }
    constexpr double c(){ return   299792458; }
    constexpr double h(){ return   6.62607015e-34; }
    constexpr double deg(){ return Pi()/(180.); }
};

#endif