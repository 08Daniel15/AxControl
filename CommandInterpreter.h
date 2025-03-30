
#include <string>
#include <fstream> // Fuer File eingefuegt
std::ofstream axisFile;

class CommandInterpreter
{
    public:

        int a = 5;
        //void CommandInterpreter;
        void readCommand(std::string input);




    private:
        int state = 0; 
        std::string command= "";
        void getState(std::string command);
        void standardMode();
        void keyboardMode();


};