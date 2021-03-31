
#include "GSRay.hpp"
#include "GSVector.hpp"

#include "deque"
#include "sstream"
#include "iostream"

// ====================================================
// GSRay

GSRay::GSRay(): fStart(), fDir(){;}

GSRay::GSRay(const GSVector start, const GSVector direction): fStart(start), fDir(direction){;}

GSRay::~GSRay(){
    for(std::deque<GSRaySegment*>::iterator it = fSegments.begin(); it != fSegments.end(); ++it ){
        delete (*it);
    }
    fSegments.clear();
}

void  GSRay::MakeNextStep(GSVector next){
    GSRaySegment* last = nullptr;
    if(GetN() != 0) last = GetLast();
    if(last==nullptr){
        std::cout<<"Spanning inital segment from " << fStart.Print(true) << " to " << next.Print(true) << " with parent " << this << " and last segment " << last <<std::endl;
        fSegments.emplace_back(new GSRaySegment(fStart, next, this, last));
        // last->fAfter = 0x0;
        return;
    }
    fSegments.emplace_back(new GSRaySegment(last->GetEnd(), next, this, last));
    last->fAfter = GetLast();
    return;
}

std::string GSRay::Print(bool quite, bool entrybreak){
    std::ostringstream stream;
    stream << "GSRAY [";
    
    if(entrybreak) stream << std::endl;
    
    for(std::deque<GSRaySegment*>::iterator it = fSegments.begin(); it != fSegments.end(); ++it){
        stream << "{" << (*it)->Print(true) << "}";
        if(entrybreak) stream << std::endl;
    }

    stream << "]";

    if(!quite) std::cout << stream.str() << std::endl;


    return stream.str();

}

GSVector& GSRay::GetStartPosition(){
    return fStart;
}

GSVector& GSRay::GetPosition(){
    return GetLast()->GetEnd();
}

GSVector  GSRay::GetDirection(){
    if(GetN() == 0){
        return fDir;
    }
    
    return fSegments.at(0)->GetDirection();
    
    
}

// ====================================================
// GSRaySegment

GSRaySegment::GSRaySegment(){;}

GSRaySegment::GSRaySegment(GSVector start, GSVector end, GSRay * parent, GSRaySegment * segbefore): fStart(start), fEnd(end), fBefore(segbefore), fAfter(0), fParent(parent) {
}

GSVector& GSRaySegment::GetStart(){
    return fStart;
}

GSVector& GSRaySegment::GetEnd(){
    return fEnd;
}

GSVector GSRaySegment::GetDelta(){
    return fEnd-fStart;
}

GSVector GSRaySegment::GetDirection(){
    return GetDelta().Unit();
}

std::string GSRaySegment::Print(bool quite, bool information){
    std::ostringstream stream;
    stream << GetStart().Print(true) << " - " << GetEnd().Print(true) ;

    if( !quite ) std::cout<<stream.str()<<std::endl;

    return stream.str();
}