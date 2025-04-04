void CommandInterpreter::readCommand(std::string input)
{
    command = input;
    std::cout << command << std::endl;

    getState(command);



    switch(state)
    {
        case 0: // Standard Mode
            std::cout << "state = " << state << "   Standard Mode" << std::endl;
            standardMode();
            break;

        case 1: // Keyboard Mode
            std::cout << "state = " << state << "   Keyboard Mode" << std::endl;
            keyboardMode();
            break;

        default:
            std::cout << "default : No aktive Mode!" << std::endl;

    }

    //for(int itr = 0; itr < input.length(); itr++ )
    //{

       //std::cout << input[itr] << std::endl;


    //}

}



void CommandInterpreter::getState(std::string command)
{

    if(command == "Keyboard")
    {
        state = 1;
    }
    else
    {
        state = 0;
    }

}



void CommandInterpreter::standardMode()
{
    std::cout << "Standard Mode" << std::endl;

    // G-Code
    gCode = std::string() + command[0] + command[1] + command[2];
    std::cout << "G-Code = " << gCode << std::endl;

    if(gCode == "G02")
    {
        std::cout << "Method = G02" << std::endl;
        G02();
    }
    else
    {
        std::cout << "G-Code not implemented "<< std::endl;
    }

}

void CommandInterpreter::G02()
{

    axis = command[3];

    for(int itr = 4 ; itr < command.length(); itr++)
    {
        str_pos = std::string() + str_pos + command[itr];
    }

    //std::cout << str_pos << std::endl;
    pos = stod(str_pos); // string to double string2double
    //std::cout << pos << std::endl;

    std::cout << "Axis       = " << axis << std::endl;
    std::cout << "targrt Pos = " << pos << std::endl;

}

void CommandInterpreter::keyboardMode()
{
    std::cout <<"Keyboard Mode" << std::endl;
}