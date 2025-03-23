#include <iostream>
#include <fstream> // Fuer File eingefuegt
#include <string>
#include "Interpolator.h"
#include "Interpolator.cpp"
#include "writeData2File.h"
#include "writeData2File.cpp"

//using namespace std; // Fuer File eingefuegt


int main() {

    std::cout<<"Start up"<< std::endl;

    int itr = 0;
    int state = 0;

    double startPos = 0.0;
    double endPos = 10.0;
    double vMax = 10.0;
    double aMax = 100.0;
    double ts = 0.01;
    double wert = 0.0;
    double wert2 = 0.0;
    bool test = false;
    double sollPos = 0.0;
    double sollVel = 0.0;
    std::string command = "";
    std::string n_sollPos = "sollPos"; // Name
    std::string n_sollVel = "sollVel"; // Name

    Interpolator axis(vMax, aMax, ts);
    writeData2File debugData(sollPos,n_sollPos, vMax, n_sollVel);
    //debugData.writeData(sollPos,sollVel);
    
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
                axis.Command(startPos , endPos);
                state = 20;
                std::cout << "state = " << state << std::endl;
                std::cout << "itr   = " << itr << std::endl;
                //state = std::stoi(command); // string2int
                break;


            case 20:
                std::cout << "state 20 "<< std::endl;
                sollPos = axis.InterpolationStep();
                sollPos = axis.sollPos;
                sollVel = axis.sollVel;
                test = axis.JobDone();
                
                if(axis.JobDone())
                {
                    state = 99;
                    //state = 0 // erst wenn Commando EIngabe inplementiert ist
                    break;
                }
                
                break;

                
            case 99:
                
                break;

            default:
                break;

        }


        itr = itr + 1;
        std::cout << "sollPos = " << sollPos << std::endl;

        debugData.writeData(sollPos, sollVel);
        
        if(itr == 200)
        {
            debugData.closeFile();
            break;
        }

    }

   
    return 0;

}
