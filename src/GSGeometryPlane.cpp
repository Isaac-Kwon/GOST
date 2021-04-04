#include "GSGeometryPlane.hpp"
#include "GSRay.hpp"
#include "GSPoints.hpp"

#include "limits"

GSGeometryPlane::GSGeometryPlane() : fNormal(), fPosition(){;}

GSGeometryPlane::GSGeometryPlane(GSVector& normal, GSVector& position) : fNormal(normal), fPosition(position){;}

GSPoints GSGeometryPlane::GetCrossPoint(GSRay* ray, bool& crossed){

    GSVector raydir = ray->GetDirection();
    GSVector raypos = ray->GetPosition();

    GSPoints points = GSPoints();
    
    {
        double dots = raydir * fNormal;
        dots = dots>0 ? dots : -1 * dots;
        if(dots < std::numeric_limits<double>::epsilon()){
            return points;
        }

    }

    double mu = fNormal * (raypos-fPosition) / (fNormal * raydir);

    GSVector crosspoint = GSVector(raypos+mu*raydir);
    points.AddPoint(crosspoint);

    return points;
}

GSVector GSGeometryPlane::GetNormalVector(GSVector pos, bool& detected){
    detected=true;
    return fNormal;
}
