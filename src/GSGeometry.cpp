#include "GSGeometry.hpp"
#include "GSPoints.hpp"
#include "GSRay.hpp"

#include "iostream"

GSGeometry::GSGeometry(){;}

GSPoints GSGeometry::GetCrossPoint(GSRay* ray, bool& crossed){
    std::cout<<"GSGeometry::GetCrossPoint - This Class is pure class. Doesn't have any cross point."<<std::endl;
    crossed = false;
    return GSPoints();
}

GSVector GSGeometry::GetNormalVector(GSVector pos, bool& detected){
    std::cout<<"GSGeometry::GetNormalVector - This Class is pure class. It can't have any normal vector."<<std::endl;   
    detected = false;
    return GSVector();
}