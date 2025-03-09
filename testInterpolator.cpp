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
    double vMax = 10.0;
    double aMax = 100.0;
    double ts = 0.001;
    double wert = 0.0;
    double wert2 = 0.0;
    std::string command = "";

    Interpolator axis(vMax, aMax, ts);

    while(true)
    {
        // Sensor Werte einlesen
        
        switch(state)
        {
            case 0:
                //std::cin >> command;

                /*
                    Kommando Auswertung 
                        - G02 ...
                        - Taster ...
                        - Automatik Betrieb ...
                */
                axis.DetermineValues(0.0 ,10.0);
                state = 20;
                std::cout << "state = " << state << std::endl;
                //state = std::stoi(command);
                //std::cout << "state 0 "<< std::endl;
                break;


            case 20:
                std::cout << "state 20 "<< std::endl;
                
                wert = axis.InterpolationStep();
                //std::cout << "wert = " << wert << std::endl;

                wert2 = axis.sollPos;
                std::cout << "Wert2 = " << wert2 << std::endl;
                
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

        if(itr == 1000)
        {
            break;
        }

    }

    return 0;



}
