#ifndef __GSVECTOR__
#define __GSVECTOR__ 1

#include "string"

class GSVector{
    public:
    GSVector();
    GSVector(double x, double y);
    GSVector(double x, double y, double z);
    GSVector(const GSVector& other);

    //Get
    double    X();
    double    Y();
    double    Z();
    void      Get(double& x, double& y, double& z);
    GSVector  Unit();

    //Operator, returning result
    inline double    Dot(GSVector other) const;
    inline GSVector  Cross(GSVector other) const;
    GSVector  Scale(double& number);
    double    Norm();
    double    Norm2();

    //Operator, Self operation 
    void      AddThis(const GSVector& other);
    void      SubstractThis(const GSVector& other);
    void      CrossThis(const GSVector& other);
    void      ScaleThis(const double& number);

    //Operator, Coveniences
    // GSVector& operator+(const GSVector& other); //Add
    // GSVector& operator-(const GSVector& other); //Substract
    // double    operator*(const GSVector& other); //Dot product
    // GSVector& operator*(const double&   other); //Scaling
    // GSVector& operator^(const GSVector& other); //Cross product

    inline GSVector & operator=(const GSVector& other);

    friend GSVector operator+(GSVector& a, GSVector& b);
    friend GSVector operator+(GSVector  a, GSVector  b);
    // friend GSVector operator-(GSVector& a, GSVector& b);
    friend GSVector operator-(GSVector  a, GSVector  b);
    // friend GSVector operator^(GSVector& a, GSVector& b);
    friend GSVector operator^(GSVector  a, GSVector  b);
    // friend GSVector operator* (GSVector &vec,   double  other);
    // friend GSVector operator* (double    other, GSVector& vec);
    friend GSVector operator* (GSVector vec,   double  other);
    friend GSVector operator* (double    other, GSVector vec);
    // friend double   operator* (GSVector& other, GSVector& vec);
    friend double   operator* (GSVector other, GSVector vec);

    inline GSVector& operator+=(const GSVector& other); //Add
    inline GSVector& operator-=(const GSVector& other); //Substract
    inline GSVector& operator*=(const double&   other); //Scaling
    inline GSVector& operator^=(const GSVector& other); //Cross product

    double    GetAngle(GSVector other);
    double    GetAngleDegree(GSVector other);

    std::string Print(bool quite=false);

    protected:
    private:
    double fX=0., fY=0., fZ=0;

};

inline GSVector& GSVector::operator=(const GSVector& other){
    fX = other.fX;
    fY = other.fY;
    fZ = other.fZ;
    return *this;
}

inline GSVector& GSVector::operator+=(const GSVector& other){
    fX += other.fX;
    fY += other.fY;
    fZ += other.fX;
    return (*this);
}

inline GSVector& GSVector::operator-=(const GSVector& other){
    fX -= other.fX;
    fY -= other.fY;
    fZ -= other.fX;
    return (*this);
}

inline GSVector& GSVector::operator*=(const double&   other){
    fX *= other;
    fY *= other;
    fZ *= other;
    return (*this);
}

inline GSVector& GSVector::operator^=(const GSVector& other){
    fX = fY*other.fZ-fY*other.fZ;
    fY = fZ*other.fX-fX*other.fZ;
    fZ = fX*other.fY-fY*other.fX;
    return (*this);
}

inline double    GSVector::Dot(GSVector other) const{
    return fX*other.fX + fY*other.fY + fZ*other.fZ;
}

inline GSVector  GSVector::Cross(GSVector other) const{
    return GSVector(fY*other.fZ-other.fY*fZ, fZ*other.fX-other.fZ*fX, fX*other.fY-other.fX*fY);
}

// GSVector operator+ ( GSVector &, GSVector & );
GSVector operator+ ( GSVector  , GSVector   );
// GSVector operator- ( GSVector &, GSVector & );
GSVector operator- ( GSVector  , GSVector   );
// GSVector operator^ ( GSVector &, GSVector & );
GSVector operator^ ( GSVector  , GSVector   );

// GSVector operator* ( GSVector & ,  double  a );
// GSVector operator* ( double   a ,  GSVector & );
// double   operator* ( GSVector & ,  GSVector & );

GSVector operator* ( GSVector  ,  double  a );
GSVector operator* ( double   a ,  GSVector  );
double   operator* ( GSVector  ,  GSVector  );

#endif