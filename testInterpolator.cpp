#include <iostream>
#include "Interpolator.cpp"

int main() {

    std::cout<<"Hallo World"<< std::endl;

    
    //double ts = 0.001;
    
    double startPos = 0.0;
    double endPos = 0.0;
    double deltaPos = 0.0;
    deltaPos = endPos - startPos;
    
    std::cout << deltaPos << std::endl;
    
    Interpolator Interpolator1;

    std::cout<<Interpolator1.endPos << std::endl;



    return 0;

}
