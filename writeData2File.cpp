writeData2File::writeData2File(double data1)
{
    
    myfile.open ("myData.txt");
    myfile << "Writing this to a file.\n";
    myfile << "Write this also to a file.\n";
    myfile << "And so on.\n";
    

}

writeData2File::writeData2File(double data1, std::string name1, double data2, std::string name2)
{
    
    myfile.open ("myData.csv");
    myfile << name1 << "," << name2 << "\n";

}


void writeData2File::writeData(double data1, double data2)
{
    myfile << data1 << "," << data2 << "\n";
}
    


void writeData2File::closeFile()
{
    myfile.close();
}
    