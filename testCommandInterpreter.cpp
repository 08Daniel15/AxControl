#include <iostream>
#include "CommandInterpreter.h"
#include "CommandInterpreter.cpp"
#include <string>
#include <conio.h> //Fuer _kbhit


int main()
{
    std::string test = "";
    //CommandInterpreter commando("Hallo");
    CommandInterpreter commando;

    //std::string test = "";

    //std::cin >> test;
    //commando.readCommand(test);
    commando.readCommand("G02A100");
    //commando.readCommand("Keyboard");

    
       /* Display message until key is pressed. */
       //while( !_kbhit() )
       //{
       //     _cputs( "Hit me!! " );
       //}
    

    /* Use _getch to throw key away. */
    //printf( "\nKey struck was '%c'\n", _getch() );
    
    

}