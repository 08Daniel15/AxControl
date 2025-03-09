#include <iostream>
#include <string>
#include "Interpolator.h"
#include "Interpolator.cpp"


int main() {

    std::cout<<"Start up"<< std::endl;

    int itr = 0;
    int state = 0;

    double startPos = 0.0;
    double endPos = 20;
    double vMax = 10;
    double aMax = 100;
    double ts = 0.001;
    std::string command = "";

    Interpolator axis(vMax, aMax, ts);

    while(true)
    {
        
        switch(state)
        {
            case 0:
                std::cin >> command;
                axis.Interpolate(0.0 ,10.0);

                //state = std::stoi(command);
                //std::cout << "state 0 "<< std::endl;
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

        if(itr == 3)
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
