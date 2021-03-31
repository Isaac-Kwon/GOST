#ifndef __GSGEOMETRY__
#define __GSGEOMETRY__ 1

#include "deque"
// #include "GSVector.hpp"

class GSRay;
class GSPoints;
class GSVector;

//Pure class to define geometrical properties of interface

class GSGeometry{
    public:
    GSGeometry();

    virtual GSPoints GetCrossPoint(GSRay* ray, bool& crossed);
    virtual GSVector GetNormalVector(GSVector pos, bool& detected);

    protected:

    private:
};

#endif