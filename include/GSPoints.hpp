#ifndef __GSPOINT__
#define __GSPOINT__ 1

#include "deque"
#include "GSVector.hpp"

class GSPoints{
    public:
    GSPoints();
    GSPoints(GSVector& firstpoint);
    ~GSPoints();
    
    void     AddPoint(GSVector& obj);
    GSVector Get(int n);
    int      GetN();
    GSVector GetClosestPoint(GSVector obj);
    GSVector GetClosestDirectionPoint(GSVector pos, GSVector dir, bool* resultQ=nullptr);

    private:
    std::deque<GSVector> fPoints;
};

#endif