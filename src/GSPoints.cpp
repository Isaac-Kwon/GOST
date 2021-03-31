#include "GSPoints.hpp"
#include "GSVector.hpp"
#include "deque"
#include "iostream"

GSPoints::GSPoints(){
}

GSPoints::GSPoints(GSVector& firstpoint){
    fPoints.emplace_back(firstpoint);
}

GSPoints::~GSPoints(){
    fPoints.clear();
}

int GSPoints::GetN(){
    return fPoints.size();
}

GSVector GSPoints::Get(int n){
    return fPoints.at(n);
    // return fPoints[n];
}

void GSPoints::AddPoint(GSVector& obj){
    fPoints.emplace_back(obj);
}

GSVector GSPoints::GetClosestPoint(GSVector obj){
    if(fPoints.size()<=0){
        std::cout<<std::endl;
        return GSVector();
    }
    GSVector ele = fPoints[0];
    double dist = (ele-obj).Norm2();
    GSVector save;
    for(GSVector ele: fPoints){
        if((ele-obj).Norm2()<dist){
            save = ele;
        }
    }
    return save;
}

GSVector GSPoints::GetClosestDirectionPoint(GSVector pos, GSVector dir, bool* resultQ){
    if(resultQ!=nullptr) (*resultQ) = false;
    if(fPoints.size()<=0){
        std::cout<<std::endl;
        return GSVector();
    }

    double dist = (fPoints[0]-pos).Norm2();
    GSVector save;
    for(GSVector ele: fPoints){
        if((ele-pos)*dir < 0) continue;
        if((ele-pos).Norm2()<dist){
            save = ele;
            if(resultQ!=nullptr) (*resultQ) = true;
        }
    }
    return save;
}