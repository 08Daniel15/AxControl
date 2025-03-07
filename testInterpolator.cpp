#include <iostream>
#include "Interpolator.cpp"
#include <string>

//int state = 0;

int main() {

    std::cout<<"Start up"<< std::endl;
    //std::cout <<"hallo"<< std::endl;
    //std::string test = "";
    //std::cout << deltaPos << std::endl;
    //Interpolator Interpolator1(10.0);
    //std::cout<<Interpolator1.endPos << std::endl;

    int itr = 0;
    int state = 0;
    std::string command = "";
    
    while(true)
    {
        std::cout<< "In While Loop : Count = "<< itr <<  std::endl;

        
        
        switch(state){
            case 0:
                std::cin >> command;
                state = std::stoi(command);
                std::cout << "state 0 "<< std::endl;
                break;

            case 1:
                std::cout << "state 1 "<< std::endl;
                break;

            default:
                break;

        }
        


        itr = itr + 1;

        if(itr == 10)
        {
            break;
        }

    }



    return 0;



}
