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
    std::cout << "Velocity = " << c_vMax << std::endl;
    std::cout << "Acceleration = " << c_aMax << std::endl;

}

void Interpolator::DetermineValues(double startPos, double endPos)
{
    std::cout << " "<< std::endl;
    std::cout << "Methode Determine Values" << std::endl;

    c_state = 0;

    c_startPos = startPos;
    c_endPos = endPos;

    // Delta Pos
    c_deltaPos =  c_endPos - c_startPos;
    std::cout << "Delta Pos = " << c_deltaPos << std::endl;

    c_ticks = 0;

    if(c_deltaPos > 0.0)
    {
        
        // Acceleration Time / Length 
        c_timeAcc = c_vMax / c_aMax;
        c_s_Acc = 0.5 * c_aMax * c_timeAcc*c_timeAcc;

        if(c_deltaPos > 2*c_s_Acc)
        {
            c_state = 11;
            c_z_Acc = (int)(c_timeAcc / c_ts);

                // Constant Velocity 
            c_s_Con = c_deltaPos - 2 * c_s_Acc;
            c_time_Con = c_s_Con / c_vMax;
            c_z_Con = (int)(c_time_Con/c_ts);
            std::cout << " " << std::endl;
            std::cout << "ConstTime = " << c_time_Con << std::endl;
            std::cout << "ConstLeng = " << c_s_Con << std::endl;
            std::cout << "ConstCoun = " << c_z_Con << std::endl;
        }
        else
        {
            c_state = 31;
            std::cout << "Pos Weg zu kurz" << std::endl;


            c_s_Con = c_deltaPos;
            c_z_Con = (int)((c_s_Con / (c_vMax / 4))/c_ts);
            std::cout << "ConstLeng = " << c_s_Con << std::endl;
            std::cout << "ConstCoun = " << c_z_Con << std::endl;
            
        }

        
    }
    else
    {
        c_deltaPos = abs(c_endPos - c_startPos);
        c_timeAcc = c_vMax / c_aMax;
        c_s_Acc = 0.5 * c_aMax * c_timeAcc*c_timeAcc;
        
        if(c_deltaPos > 2*c_s_Acc)
        {
            c_state =21;
        }
        else
        {
            c_state = 41;
            std::cout << "Neg Weg zu kurz" << std::endl;
        }



    }

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
            //c_state = 11;
            break;

        case 11:
            sollPos = 0.5 * c_aMax * (c_ticks * c_ts) * (c_ticks * c_ts) + c_startPos;

            c_ticks = c_ticks + 1;

            if(c_ticks == c_z_Acc)
            {
                c_state = 12;
                c_ticks = 1;
                sollPos_0 = sollPos;
                //jobDone = true;
            }
            break;
        
        case 12:
            sollPos = c_vMax * c_ts + sollPos;
            if(c_ticks == c_z_Con +1)
            {
                c_state = 13;
                jobDone = false;
                sollPos_0 = sollPos;
                c_ticks = 1;
                break;
            }
            c_ticks = c_ticks + 1;
            break;

        case 13:
            sollPos = sollPos_0 + c_vMax * (c_ticks * c_ts) - 0.5 * c_aMax * (c_ticks * c_ts) * (c_ticks * c_ts);
            
            if(c_ticks == c_z_Acc)
            {
                jobDone = true;
                c_state = 99;
                sollPos = c_endPos;
                c_ticks = 1;
                
                break;
            }
            c_ticks = c_ticks + 1;
            break;

        case 31:
            sollPos = c_startPos + c_vMax / 4 * (c_ticks * c_ts);

            if(c_ticks ==  c_z_Con)
            {
                c_ticks = 1;
                c_state = 32;
                break;
            }
            c_ticks = c_ticks + 1;
            break;

        case 32:


        case 99:
            std::cout << "stop doing anything " << std::endl;
            break;

        default:
            break;

            
        //return sollPos;

    }


    return sollPos;
}

double Interpolator::Command(double startPos, double endPos)
{
    jobDone = false;
    c_startPos = startPos;
    c_endPos = endPos;

    DetermineValues(c_startPos , c_endPos);
    
    return 0.0;
}


void Interpolator::DebugValues()
{
    
}
    

bool Interpolator::JobDone()
{
    return jobDone;
}