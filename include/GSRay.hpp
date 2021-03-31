#ifndef __GSRAY__
#define __GSRAY__ 1

#include "deque"
#include "GSVector.hpp"

class GSGeometry;
class GSRaySegment;

class GSRay{
    public:
    GSRay();
    GSRay(const GSVector start, const GSVector direction);
    // GSRay(const GSRay& other);

    ~GSRay();

    // void Propagate(GSGeometry* geo);
    int  GetN(){return fSegments.size();}
    
    GSRaySegment* operator[](int i){return fSegments[i];}
    GSRaySegment* GetLast(){return (*(fSegments.end()-1));}

    GSVector& GetPosition();
    GSVector& GetStartPosition();
    GSVector  GetDirection();

    std::string Print(bool quite=false, bool entrybreak=false);
    
    void  MakeNextStep(GSVector next);
    protected:
    // void  AddSegment(const GSVector& nextpoint);

    private:
    std::deque<GSRaySegment*> fSegments;
    bool fPropagatable        = true;

    GSGeometry * lastInteracted;

    GSVector fStart;
    GSVector fDir;
    
};

class GSRaySegment{
    public:
    GSRaySegment();
    GSRaySegment(GSVector start, GSVector end, GSRay * parent=0, GSRaySegment * segbefore=0);

    GSVector &GetStart();
    GSVector &GetEnd();
    GSVector  GetDelta();
    GSVector  GetDirection();

    GSRaySegment * GetSegmentBefore(){return fBefore;}
    GSRaySegment * GetSegmentAfter(){return fAfter;}
    GSRay        * GetRayParent(){return fParent;}

    std::string Print(bool quite=false, bool information=false);
    protected:
    private:
    GSVector fStart;
    GSVector fEnd;

    GSRaySegment * fBefore;
    GSRaySegment * fAfter;
    GSRay        * fParent;

    friend class GSRay;
};

#endif