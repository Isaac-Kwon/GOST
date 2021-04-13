#ifndef __GSMATRIX__
#define __GSMATRIX__ 1

#include "string"
#include "vector"
#include "GSVector.hpp"

class GSMatrix{
    public:
    GSMatrix(); //Null Matrix
    GSMatrix(const int n); //n x n Unit Matrix
    // GSMatrix(const int m, const int n); //Arb matrix of n x m, zero matrix
    GSMatrix(const int m, const int n);  //Arb matrix of n x m, selected number, Zero Matrix
    GSMatrix(const int m, const int n, const int npassed, ...); //Arb matrix of n x m
    GSMatrix(GSVector& vec); // GSVector (3) -> GSMatrix (1x4)
    GSMatrix(const GSMatrix& other); //Copy Construction
    GSMatrix& operator=(const GSMatrix&);

    ~GSMatrix();
    void     Freeing();
    GSMatrix Transpose();
    double   At(int i);
    double   At(int i, int j);
    double&  operator[](int i);
    double&  operator()(int i);
    double&  operator()(int i, int j);
    bool     IsInside(int i);
    bool     IsInside(int i, int j);
    bool     IsSameShape(GSMatrix & other);
    bool     IsTransShape(GSMatrix & other);
    std::string Print(bool quite=false);

    friend GSMatrix operator*(GSMatrix , double  );
    friend GSMatrix operator*(double  , GSMatrix );
    friend GSMatrix operator*(GSMatrix   , GSMatrix   );
    friend GSMatrix operator+(GSMatrix &  , GSMatrix  & );
    friend GSMatrix operator-(GSMatrix &  , GSMatrix  & );

    inline GSMatrix& operator*=(const double& other); //Scaling


    protected:
    void     Freeing();

    private:
    void Init();
    double * fElement;
    int fM=1;
    int fN=1;

    double nval=-1;
};

GSMatrix operator*(GSMatrix , double   );
GSMatrix operator*(double   , GSMatrix );
GSMatrix operator*(GSMatrix , GSMatrix );
GSMatrix operator+(GSMatrix & , GSMatrix & );
GSMatrix operator-(GSMatrix & , GSMatrix & );

inline GSMatrix& GSMatrix::operator*=(const double&   other){
    for(int i=0; i<fM*fN; i++){
        fElement[i] *= other;
    }
    return (*this);
}

#endif