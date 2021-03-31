// #include "TROOT.h"
// #include "TCanvas.h"
// #include "TH1D.h"

#include "GSVector.hpp"
// #include "GSVector.cpp"

#include "math.h"
#include "iostream"

// void procedureCode(double posX = -10.0, double posY = -10.0, double mu = 0.8){

//     GSVector RInc_X = GSVector( -posX,  -posY, 0);
//     GSVector RInc_D = GSVector(  posX,   posY, 0);

//     // Incident at (0,0);

//     // Normal Vector on interface
//     GSVector NInterface = GSVector(0,+1,0);

//     GSVector RInt_X = GSVector( 0, 0, 0);


//     // std::cout<<"3-1"<<std::endl;
//     // std::cout<<NInterface*RInc_D<<std::endl;

//     // std::cout<<"3-2"<<std::endl;
//     // std::cout<<(NInterface*RInc_D)<<std::endl;

//     // std::cout<<"3-3"<<std::endl;

//     // std::cout<<"3-4"<<std::endl;
//     // GSVector RInt_D = sqrt(1-pow(mu,2)*(1-pow(NInterface*RInc_D,2)))*NInterface + mu * (RInc_D - (NInterface*RInc_D)*NInterface);

//     // std::cout<<"3"<<std::endl;
//     // std::cout<<"Incident [x,y,z] = " << RInc_X.Print(true) << std::endl;
//     // std::cout<<"Refracted [x,y,z] = " << RInt_D.Print(true) << std::endl;
//     std::cout<<"Test1\t"<< (NInterface.Cross(RInc_D)).Print(true) <<std::endl;
//     std::cout<<"Test2\t"<< (NInterface+RInc_D).Print(true) <<std::endl;
//     std::cout<<"Test3\t"<< (NInterface-RInc_D).Print(true) <<std::endl;
//     std::cout<<"Test4\t"<< (NInterface.Dot(RInc_D)) <<std::endl;
//     std::cout<<"Test5\t"<< (NInterface*3).Print(true) <<std::endl;

//     return;
// }

// void procedureCode(){
//     std::cout<<"hello"<<std::endl;
//     Refraction(-10, -10, -0.8);
//     std::cout<<"world"<<std::endl;
// }


int main(){

    double posX = -10.0;
    double posY = -10.0;
    double mu = 0.8;

    GSVector RInc_X = GSVector( -posX,  -posY, 0);
    GSVector RInc_D = GSVector(  posX,   posY, 0);

    // Incident at (0,0);

    // Normal Vector on interface
    GSVector NInterface = GSVector(0,+1,0);

    GSVector RInt_X = GSVector( 0, 0, 0);


    // std::cout<<"3-1"<<std::endl;
    // std::cout<<NInterface*RInc_D<<std::endl;

    // std::cout<<"3-2"<<std::endl;
    // std::cout<<(NInterface*RInc_D)<<std::endl;

    // std::cout<<"3-3"<<std::endl;

    // std::cout<<"3-4"<<std::endl;
    GSVector RInt_D = sqrt(1-pow(mu,2)*(1-pow(NInterface*RInc_D,2)))*NInterface + mu * (RInc_D - (NInterface*RInc_D)*NInterface);

    // std::cout<<"3"<<std::endl;
    std::cout<<"Incident [x,y,z] = " << RInc_X.Print(true) << std::endl;
    std::cout<<"Refracted [x,y,z] = " << RInt_D.Print(true) << std::endl;
    // std::cout<<"Test1\t"<< (NInterface.Cross(RInc_D)).Print(true) <<std::endl;
    // std::cout<<"Test2\t"<< (NInterface+RInc_D).Print(true) <<std::endl;
    // std::cout<<"Test3\t"<< (NInterface-RInc_D).Print(true) <<std::endl;
    // std::cout<<"Test4\t"<< (NInterface.Dot(RInc_D)) <<std::endl;
    // std::cout<<"Test5\t"<< (NInterface*3).Print(true) <<std::endl;

    return 0;
}