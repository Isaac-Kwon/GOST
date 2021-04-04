#ifndef __GSGEOMETRYPLANE__
#define __GSGEOMETRYPLANE__ 1

#include "GSGeometry.hpp"
#include "GSVector.hpp"

class GSGeometryPlane : GSGeometry{
public:
    GSGeometryPlane();
    GSGeometryPlane(GSVector& normal, GSVector& position);

    virtual GSPoints GetCrossPoint(GSRay*, bool& crossed);
    virtual GSVector GetNormalVector(GSVector pos, bool& detected);

protected:
private:
    GSVector fNormal;
    GSVector fPosition;
};

#endif