
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
        std::string axis = "";
        std::string str_pos = "";
        std::string gCode = "";
        double pos;
        void getState(std::string command);
        void standardMode();
        void keyboardMode();
        void G02();


};