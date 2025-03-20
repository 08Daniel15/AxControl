writeData2File::writeData2File(double data1)
{
    std::ofstream myfile;
    myfile.open ("myData.txt");
    myfile << "Writing this to a file.\n";
    myfile << "Write this also to a file.\n";
    myfile << "And so on.\n";
    

}

writeData2File::writeData2File(double data1, double data2)
{
    daten1 = data1;
    daten2 = data2;

}


void writeData2File::writeData(double data1, double data2)
{
    daten1 = data1;
    daten2 = data2;

}
    

/*
writeData2File::closeFile()
{
    daten1 = daten2;
}
    */