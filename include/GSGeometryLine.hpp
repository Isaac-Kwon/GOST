#ifndef __GSGEOMETRYLINE__
#define __GSGEOMETRYLINE__ 1

#include "GSGeometry.hpp"

class GSGeometryLine : GSGeometry{
public:
    GSGeometryLine();
    GSGeometryLine(double x1, double y1, double x2, double y2);
    // GSGeometryLine(double x1, double y1, double z1, double x2, double y2, double z2);

    virtual GSPoints GetCrossPoint(GSRay*, bool& crossed);
    virtual GSVector GetNormalVector(GSVector pos, bool& detected);
    
    GSVector GetDirection();

protected:
private:
    double fX1 = -10;
    double fY1 = -10;
    double fX2 = +10;
    double fY2 = +10;
};

#endif