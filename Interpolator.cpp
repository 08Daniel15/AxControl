/*
Interpolator::Interpolator(double c_startPos, double c_endPos){
    startPos = c_startPos; 
    endPos = c_endPos;
}*/
    
Interpolator::Interpolator(double vMax, double aMax, double ts)
{
    c_vMax = vMax;
    c_aMax = aMax;
    c_ts = ts;
    std::cout << c_vMax << std::endl;
    std::cout << c_aMax << std::endl;

}

void Interpolator::DetermineValues(double startPos, double endPos)
{
    std::cout << "Methode Determine Values" << std::endl;

    c_state = 0;

    c_startPos = startPos;
    c_endPos = endPos;

    // Delta Pos
    c_deltaPos =  c_endPos - c_startPos;
    std::cout << "DeltaPos  = " << c_deltaPos << std::endl;

    // Acceleration Time / Length 
    c_timeAcc = c_vMax / c_aMax;
    c_s_Acc = 1/2 * c_aMax * c_aMax * c_timeAcc + c_startPos;
    c_z_Acc = (int)(c_timeAcc / c_ts);
    std::cout << "AccTime   = " << (double)c_timeAcc << std::endl;
    std::cout << "AccLength = " << c_s_Acc << std:: endl; 
    std::cout << "AccCounts = " << c_z_Acc << std::endl;

    // Constant Velocity 
    c_s_Con = c_deltaPos - 2 * c_s_Acc;
    c_time_Con = c_s_Con / c_vMax;
    c_z_Con = (int)(c_time_Con/c_ts);
    std::cout << " " << std::endl;
    std::cout << "ConstTime = " << c_time_Con << std::endl;
    std::cout << "ConstLeng = " << c_s_Con << std::endl;
    std::cout << "ConstCoun = " << c_z_Con << std::endl;

}

double Interpolator::InterpolationStep()
{
    //std::cout << "Hallo Interpolation Step" << std::endl;
    std::cout << "c_state = " << c_state << std::endl;
    std::cout << "c_ticks = "<< c_ticks << std::endl;

    switch(c_state)
    {
        case 0:
            // Ueberprüfe welche Interpolationsmodus aktiv ist
            c_state = 11;
            break;

        case 11:
            sollPos = 0.5 * c_aMax * (c_ticks * c_ts) * (c_ticks * c_ts);

            c_ticks = c_ticks + 1;
            break;



    }


    return 10.5;
}