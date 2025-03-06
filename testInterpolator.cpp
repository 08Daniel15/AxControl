#include <iostream>
#include "Interpolator.cpp"
#include <string>

int main() {

    std::cout<<"Hallo World"<< std::endl;
    
    double startPos = 0.0;
    double endPos = 0.0;
    double deltaPos = 0.0;
    deltaPos = endPos - startPos + deltaPos;
    int z = 0;
    int count = 5;
    int itr = 0;
    std::string test = "";

    std::cout << deltaPos << std::endl;
    Interpolator Interpolator1(10.0);
    std::cout<<Interpolator1.endPos << std::endl;

    
    for (int z = 0; itr < count; itr++)
    {
        z = z +1;
        std::cout << z << std::endl;
        std::cin>>test;
        std::cout <<"hallo"<< std::endl;
    }
    

    return 0;

    

}
