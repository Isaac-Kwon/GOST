#include "GSGeometryLine.hpp"
#include "GSRay.hpp"
#include "GSPoints.hpp"

GSGeometryLine::GSGeometryLine() : fX1(-10), fY1(-10), fX2(+10), fY2(+10){;}

GSGeometryLine::GSGeometryLine(double x1, double y1, double x2, double y2) : fX1(x1), fY1(y1), fX2(x2), fY2(y2){;}

GSVector GSGeometryLine::GetDirection(){
    return GSVector(fX2, fY2)-GSVector(fX1, fY1);
}

GSPoints GSGeometryLine::GetCrossPoint(GSRay* ray, bool& crossed){
    // GSRaySegment * seg = ray->GetLast();
    GSPoints points = GSPoints();
    GSVector ppos   = ray->GetPosition();
    GSVector pdir   = ray->GetDirection().Unit();

    GSVector lpos   = GSVector(fX1, fY2);
    GSVector ldir   = GetDirection().Unit();
    
    double k, kp;
    {
        // double A = 
    }


    

    return points;
}

GSVector GSGeometryLine::GetNormalVector(GSVector pos, bool& detected){
    detected=true;
    return GSVector(-pos.Y(), pos.X());
}
