#include "iostream"
#include "stdlib.h"
#include "stdarg.h"
#include "GSMatrix.hpp"

#include "sstream"


GSMatrix::GSMatrix(): fElement(0), fM(0), fN(0){
    // Init();
}

GSMatrix::GSMatrix(const int n): fElement(0), fM(n), fN(n){
    Init();
}

GSMatrix::GSMatrix(const int m, const int n): fElement(0), fM(m), fN(n){
    Init();
}


GSMatrix::GSMatrix(const int m, const int n, const int npassed, ...): fElement(0), fM(m), fN(n){
    Init();

    va_list vl;
    va_start( vl, npassed );

    for(int i=0; i<m*n && i<npassed; i++){
        fElement[i] = va_arg(vl, double);
    }

    va_end(vl);
}

GSMatrix::GSMatrix(GSVector& vec){

}

GSMatrix::GSMatrix(const GSMatrix& other): fElement(0), fM(other.fM), fN(other.fN){
    Init();
    
    int fMN = fM*fN;
    for(int i=0; i<fMN; i++){
        fElement[i] = other.fElement[i];
    }
}

GSMatrix& GSMatrix::operator=(const GSMatrix& other){
    Freeing();
    fM = other.fM;
    fN = other.fN;

    Init();
    for(int i=0; i<fM*fN; i++){
        fElement[i] = other.fElement[i];
        // std::cout<<"COPIED\t"<<fElement[i]<<"\t"<<At(i)<<std::endl;
    }
    
    return *this;
}

GSMatrix::~GSMatrix(){
    Freeing();
}

void GSMatrix::Init(){
    fElement = (double*) std::malloc(fM*fN*sizeof(double));
    for(int i=0; i<fN*fM; i++){
        fElement[i] = 0.;
    }
}

void GSMatrix::Freeing(){
    // if(fElement == nullptr){
    //     return;
    // }
    std::free(fElement);
}

bool     GSMatrix::IsInside(int i){
    if(i >= 0 && i< fN*fM) return true;
    return false;
}

bool     GSMatrix::IsInside(int i, int j){
    if (i>=0 && i<fM && j>=0 && j<fN){
        return true;
    }
    return false;
}

double  GSMatrix::At(int i){
    if( !IsInside(i) ){
        std::cout<<"GSMatrix::At(1) - Out if index"<<"["<<i<<"]"<<std::endl;
        return -1;
    }
    return fElement[i];
}

double  GSMatrix::At(int i, int j){
    if( !IsInside(i,j) ){
        std::cout<<"GSMatrix::At(2) - Out if index "<<"["<<i<<","<<j<<"]"<<std::endl;
        return -1;
    }
    return fElement[i*fN+j];
}

bool     GSMatrix::IsSameShape(GSMatrix & other){
    if(fN == other.fN && fM == other.fM) return true;
    return false;
}

bool     GSMatrix::IsTransShape(GSMatrix & other){
    if(fN == other.fM && fM == other.fN) return true;
    return false;
}

double&  GSMatrix::operator[](int i){
    if( !IsInside(i) ){
        std::cout<<"GSMatrix::operator[](1) - Out if index"<<"["<<i<<"]"<<std::endl;
        return nval;
    }
    return fElement[i];
}

double&  GSMatrix::operator()(int i){
    if( !IsInside(i) ){
        std::cout<<"GSMatrix::operator()(1) - Out if index"<<"["<<i<<"]"<<std::endl;
        return nval;
    }
    return fElement[i];
}

double&  GSMatrix::operator()(int i, int j){
    if( !IsInside(i, j) ){
        std::cout<<"GSMatrix::operator()(2) - Out if index"<<"["<<i<<"]"<<std::endl;
        return nval;
    }
    return fElement[i*fM+j];
}

GSMatrix GSMatrix::Inverse(){
    GSMatrix ans(fN, fM);

    for(int i=0; i<fM; i++){
        for(int j=0; j<fN; j++){
            ans(i,j) = At(j,i);
        }
    }
    return ans;
} 

GSMatrix operator*(GSMatrix self, double  other){
    GSMatrix ans = GSMatrix(self);
    for(int i=0; i<(self.fN*self.fM); i++){
        ans(i) *= other;
    }
    return ans;
}

GSMatrix operator*(double other, GSMatrix self){
    GSMatrix ans = GSMatrix(self);
    for(int i=0; i<(self.fN*self.fM); i++){
        ans(i) *= other;
    }
    return ans;
}

GSMatrix operator*(GSMatrix & self, GSMatrix & other){
    if(self.fN != other.fM){
        std::cout<<"GSMatrix::operator*()(3) - inner part of 2 matrices are not same : "<<self.fN<<", "<<other.fM<<std::endl;
        return GSMatrix();
    }
    GSMatrix ans = GSMatrix(self.fM, other.fN);
    for(int i=0; i<(ans.fM); i++){
        for(int j=0; j<(ans.fN); j++){
            for(int k=0; k<(self.fN); k++){
                ans(i,j)+= self.At(i,k) * other.At(k,j);
            }
        }
    }
    return ans;
}

GSMatrix operator+(GSMatrix &  self, GSMatrix & other){
    if(! self.IsSameShape(other) ){
        std::cout<<"operator+ (GSMatrix&, GSMatrix&) - Not same shape"<<std::endl;
        return GSMatrix();
    }

    GSMatrix ans = GSMatrix(self.fM, self.fN);

    int length = self.fN * self.fM;
    for(int i=0; i<length; i++){
        ans[i] = self[i] + other[i];
    }

    return ans;

}

GSMatrix operator-(GSMatrix & self, GSMatrix & other){
    if(! self.IsSameShape(other) ){
        std::cout<<"operator- (GSMatrix&, GSMatrix&) - Not same shape"<<std::endl;
        return GSMatrix();
    }

    GSMatrix ans(self.fM, self.fN);

    int length = self.fN * self.fM;
    for(int i=0; i<length; i++){
        ans[i] = self[i] - other[i];
    }

    return ans;

}

std::string GSMatrix::Print(bool quite){
    
    std::ostringstream anss;


    anss.precision(4);

    for(int i=0; i<fM; i++){
        for(int j=0; j<fN; j++){
            anss << At(i,j) << "\t";
        }
        anss<<std::endl;
    }
    anss.unsetf(std::ios::fixed);

    std::string ans = anss.str();

    if(!quite){
        std::cout<<ans;
    }

    return ans;
}

