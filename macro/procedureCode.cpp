#include "TROOT.h"
#include "TCanvas.h"
// #include "TH1D.h"

#include "GSVector.hpp"
// #include "GSVector.cpp"

#include "TGraph.h"
#include "TMultiGraph.h"

#include "math.h"
#include "TLine.h"


GSVector GetNextVector(GSVector D, double mu, GSVector N){

    GSVector d = D.Unit();
    GSVector n = N.Unit();

    if(d.Dot(n) < 0){ // If Direction is opposite, inverse parameters/
        n = -1*n;
        mu = 1/mu;
    }

    double k = d.Dot(n);
    double a,b;
    if(mu*mu*k*k - mu*mu + 1 < 0){ //Total Internal Refection 
        a = 1;
        b = -2*k;
    }else{ //Refraction
        a = mu;
        b = - mu * k + sqrt(mu*mu*k*k - mu*mu + 1);
    }
    return a*d+b*n;
}

TGraph * RayOne(double posX = -30.0, double posY =  +20.0, double mu = 0.8, const char* gname = "g1"){
    
    GSVector X = GSVector(  posX,   posY, 0);
    GSVector D1 = GSVector( -posX,  -posY, 0).Unit();
    GSVector N = GSVector(0,+1,0);
    
    TGraph * g1 = new TGraph();
    g1->SetName(gname);

    g1->SetPoint(0,posX,posY);
    g1->SetPoint(1,0,0);

    GSVector D2 = GetNextVector(D1, mu, N)*X.Norm();

    // std::cout<<"C "<<D2.Print(true)<<std::endl;

    g1->SetPoint(2,D2.X(),D2.Y());

    double n1 = (D1.Unit()^N.Unit()).Norm();
    double n2 = (D2.Unit()^N.Unit()).Norm();

    std::cout<< D1.Print(true) << " >> " << D2.Print(true) << "\tEstimated\t" << n1/n2 << "\t|\t" << n2/n1 << std::endl;

    return g1;
}

void procedureCode(){

    Color_t colors[] = {1,2,3,4,5,6,7,8,9,40, 41, 42, 43, 44, 46, 48, 49} ;
    TCanvas * c1 = new TCanvas("c1", "c1", 1200, 1200);

    TMultiGraph * mg = new TMultiGraph("mg", "rays");
    GSVector N = GSVector(0,-1,0);

    for(int i=0; i<13; i++){
        TGraph * g = RayOne(-10*sin(3.141592/13*i), 10*cos(3.141592/13*i), 1.25, TString::Format("g%d", i).Data());
        // TGraph * g = RayOne(-10*sin(3.141592/10*i), 10*cos(3.141592/10*i), 2.8, TString::Format("g%d", i).Data());
        g->SetLineColor(colors[i]);
        mg->Add(g);
    }

    mg->Draw("APL");
    c1->BuildLegend();

    return 0;
}

int main(){
    procedureCode();
    return 0;
}