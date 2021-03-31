#include "GSConstants.hpp"
#include "GSVector.hpp"
#include "GSRay.hpp"
#include "GSPoints.hpp"


int main(){

    GSRay * ray = new GSRay(GSVector(1,1,0), GSVector(-1, -1, 0));
    ray->Print();
    ray->MakeNextStep(GSVector(1,2,3));
    ray->Print();
    ray->MakeNextStep(GSVector(2,2,3));
    ray->Print();    
    ray->MakeNextStep(GSVector(4,4,6));
    ray->Print();    
    ray->MakeNextStep(GSVector(7,8,9));
    ray->Print();    

    return 0;

}