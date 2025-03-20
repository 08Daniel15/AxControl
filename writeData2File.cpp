writeData2File::writeData2File(double data1)
{
    
    myfile.open ("myData.txt");
    myfile << "Writing this to a file.\n";
    myfile << "Write this also to a file.\n";
    myfile << "And so on.\n";
    

}

writeData2File::writeData2File(double data1, double data2)
{
    
    myfile.open ("myData.txt");
    myfile << "Writing this to a file.\n";
    myfile << "Write this also to a file.\n";
    myfile << "And so on.\n";
    

}


void writeData2File::writeData(double data1, double data2)
{
    myfile << data1 << ";" << data2 << "\n";
    daten1 = data1;
    daten2 = data2;

}
    


void writeData2File::closeFile()
{
    myfile.close();
}
    