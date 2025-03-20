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
    double endPos = 20;
    double vMax = 10.0;
    double aMax = 100.0;
    double ts = 0.001;
    double wert = 0.0;
    double wert2 = 0.0;
    bool test = false;
    double sollPos = 0.0;
    std::string command = "";

    Interpolator axis(vMax, aMax, ts);
    writeData2File debugData(sollPos, vMax);
    debugData.writeData(sollPos,vMax);
    
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
                axis.Command(0.0 ,10.0);
                state = 20;
                std::cout << "state = " << state << std::endl;
                std::cout << "itr   = " << itr << std::endl;
                //state = std::stoi(command);
                //std::cout << "state 0 "<< std::endl;
                break;


            case 20:
                std::cout << " " << std::endl;
                std::cout << "state 20 "<< std::endl;
                sollPos = axis.InterpolationStep();
                test = axis.JobDone();
                //std::cout << "Test = " << test << std::endl;
                
                if(axis.JobDone())
                {
                    state = 99;
                    break;
                }
                
                
                break;

                
            case 99:
                std::cout <<" state 21 - Beschleunigen "<< std::endl;
                break;
            /*
            case 22:
                std::cout <<" state 22 - Konstante Geschwindigkeit" << std::endl;
                break;


            case 23:
                std::cout << " state 23 - Verzoegern" << std::endl;
                break;

                */


            default:
                break;

        }


        


        itr = itr + 1;
        std::cout << "itr = " << itr << std::endl;
        std::cout << "sollPos = " << sollPos << std::endl;
        std::cout << "Hallo File " << std::endl;
        debugData.writeData(sollPos, vMax);
        debugData.closeFile();

        if(itr == 1)
        {
            break;
        }


    }

    

    //std::cout << "Hallo File" << std::endl;
    //std::cout << "  " << std::endl;
    


    /*
    std::ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile << "Write this also to a file.\n";
    myfile << "And so on.\n";
    myfile.close();
    */

    return 0;



}
