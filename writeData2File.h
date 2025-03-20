std::ofstream myfile;

class writeData2File
{
    public:
    writeData2File(double data1);
    writeData2File(double data1, double data2);
    void writeData(double data1, double data2);
    void closeFile();
    



    private:
    double daten1;
    double daten2;


};
