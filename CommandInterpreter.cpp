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

    for(int itr = 0; itr < input.length(); itr++ )
    {

        std::cout << input[itr] << std::endl;


    }

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
}

void CommandInterpreter::keyboardMode()
{
    std::cout <<"Keyboard Mode" << std::endl;
}