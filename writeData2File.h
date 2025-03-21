std::ofstream myfile;
#include <string>

class writeData2File
{
    public:
    writeData2File(double data1);
    writeData2File(double data1, std::string name1, double data2, std::string name2);
    void writeData(double data1, double data2);
    void closeFile();
    

    private:
    double daten1;
    double daten2;


};
