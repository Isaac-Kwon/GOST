#include "GSVector.hpp"

#include "math.h"
#include "GSConstants.hpp"

#include <iostream>
#include <string>
#include <sstream>

GSVector::GSVector(): fX(0), fY(0), fZ(0){}
GSVector::GSVector(double x, double y): fX(x), fY(y), fZ(0){}
GSVector::GSVector(double x, double y, double z): fX(x), fY(y), fZ(z){}
GSVector::GSVector(const GSVector& other): fX(other.fX), fY(other.fY), fZ(other.fZ){;}

//Get
double    GSVector::X(){return fX;}
double    GSVector::Y(){return fY;}
double    GSVector::Z(){return fZ;}
void      GSVector::Get(double& x, double& y, double& z){x = fX; y = fY; z=fZ;}

GSVector  GSVector::Unit(){
    double norm = Norm();
    return GSVector(fX/norm, fY/norm, fZ/norm);
}

//Operator, returning result

GSVector GSVector::Scale(double& number){
    // return GSVector(number*fX, number*fY, number*fZ);
    return GSVector(number*fX, number*fY, number*fZ);
}

double    GSVector::Norm(){
    return sqrt(fX*fX + fY*fY + fZ*fZ);
}

double    GSVector::Norm2(){
    return fX*fX + fY*fY + fZ*fZ;
}

//Operator, Self Closed operation 
void      GSVector::AddThis(const GSVector& other){
    // fX += other.fX;
    // fY += other.fY;
    // fZ += other.fZ;
    (*this)+=other;
}
void      GSVector::SubstractThis(const GSVector& other){
    // fX -= other.fX;
    // fY -= other.fY;
    // fZ -= other.fZ;
    (*this)-=other;
}
void      GSVector::CrossThis(const GSVector& other){
    (*this)^=other;
}

void      GSVector::ScaleThis(const double& number){
    (*this).operator*=(number);
}

//Operator, Coveniences

// double    GSVector::operator*(const GSVector& other){
//     return sqrt(fX*other.fX + fY*other.fY + fZ*other.fZ);
// }

// GSVector& GSVector::operator*(const double&   other){
//     return * new GSVector(fX*other, fY*other, fZ*other);
// }

// GSVector& GSVector::operator^(const GSVector& other){
//     double x = fY*other.fZ-fY*other.fZ;
//     double y = fZ*other.fX-fX*other.fZ;
//     double z = fX*other.fY-fY*other.fX;
//     return * new GSVector(x,y,z);
// }

double    GSVector::GetAngle(GSVector other){ //Get Angle [0, Pi]
    return acos(Unit().Dot(other.Unit()));
}

double    GSVector::GetAngleDegree(GSVector other){
    return GetAngle(other)*180/GSConstant::Pi();
}

std::string GSVector::Print(bool quite){
    std::ostringstream anss;

    anss << "[" << fX << "," << fY << "," << fZ << "]";

    std::string ans = anss.str();
    if(!quite){
        // std::cout<<fX<<"\t"<<fY<<"\t"<<fZ<<std::endl;
        std::cout<<"[x,y,z] = " << ans << std::endl;
    }
    
    return ans;
}

// GSVector operator+ ( GSVector& a,  GSVector& b) {
//     return GSVector(a.fX+b.fX, a.fY+b.fY, a.fZ+b.fZ);
// }

GSVector operator+ ( GSVector  a,  GSVector  b) {
    return GSVector(a.fX+b.fX, a.fY+b.fY, a.fZ+b.fZ);
}

// GSVector operator- ( GSVector& a,  GSVector& b) {
//     return GSVector(a.fX-b.fX, a.fY-b.fY, a.fZ-b.fZ);
// }

GSVector operator- ( GSVector  a,  GSVector  b) {
    return GSVector(a.fX-b.fX, a.fY-b.fY, a.fZ-b.fZ);
}

// GSVector operator^ ( GSVector& a,  GSVector& b) {
//     double x = a.fY*b.fZ-a.fY*b.fZ;
//     double y = a.fZ*b.fX-a.fX*b.fZ;
//     double z = a.fX*b.fY-a.fY*b.fX;
//     return GSVector(x,y,z);
// }

GSVector operator^ ( GSVector  a,  GSVector  b) {
    double x = a.fY*b.fZ-a.fZ*b.fY;
    double y = a.fZ*b.fX-a.fX*b.fZ;
    double z = a.fX*b.fY-a.fY*b.fX;
    return GSVector(x,y,z);
}

// GSVector operator* ( GSVector &vec, double other) {
//     return GSVector(other*vec.fX, other*vec.fY, other*vec.fZ);
// }

GSVector operator* ( GSVector vec, double other) {
    return GSVector(other*vec.fX, other*vec.fY, other*vec.fZ);
}

// double   operator* ( GSVector& other,  GSVector& vec) {
//     return vec.Dot(other);
// }

// GSVector operator* (double other,  GSVector &vec) {
//     return GSVector(other*vec.fX, other*vec.fY, other*vec.fZ);
// }

GSVector operator* (double other,  GSVector vec) {
    return GSVector(other*vec.fX, other*vec.fY, other*vec.fZ);
}

double   operator* ( GSVector  other,  GSVector  vec) {
    return vec.Dot(other);
}