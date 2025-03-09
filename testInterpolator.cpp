#include <iostream>
#include <string>
#include "Interpolator.h"
#include "Interpolator.cpp"


int main() {

    std::cout<<"Start up"<< std::endl;
    //std::cout <<"hallo"<< std::endl;
    //std::string test = "";
    //std::cout << deltaPos << std::endl;
    //Interpolator Interpolator1(10.0);
    //std::cout<<Interpolator1.endPos << std::endl;

    Interpolator test1(5, 10);
    Interpolator test2(5,10,1);
    int itr = 0;
    int state = 0;
    std::string command = "";
    //std::cout << test1.startPos << std::endl;
    std::cout << "test 1" << std::endl;
    std::cout << test1.startPos << std::endl;
    std::cout << test1.endPos << std::endl;
    std::cout << "test 2" << std::endl;
    std::cout << test2.startPos << std::endl;
    std::cout << test2.endPos << std::endl;
    std::cout << test2.deltaPos << std::endl;

    

    while(true)
    {
        std::cout<< "In While Loop : Count = "<< itr <<  std::endl;

        
        
        switch(state){
            case 0:
                std::cin >> command;
                state = std::stoi(command);
                std::cout << "state 0 "<< std::endl;
                break;

            case 20:
                std::cout << "state 20 "<< std::endl;
                std::cout << "Berechne Werte" << std::endl;
                break;

            case 21:
                std::cout <<" state 21 - Beschleunigen "<< std::endl;
                break;

            case 22:
                std::cout <<" state 22 - Konstante Geschwindigkeit" << std::endl;
                break;

            case 23:
                std::cout << " state 23 - Verzoegern" << std::endl;
                break;


            default:
                break;

        }
        


        itr = itr + 1;

        if(itr == 10)
        {
            std::cout << "State[0] eingeben oder [n] um das Programm zu beenden" << std::endl;
            std::cin >> command;

            if(command == "n")
            {
                std::cout << "Programm wird abgebrochen";
                break;
            }
            else
            {
                state = 0;
                itr = 0;
            }
            
        }

    }



    return 0;



}
