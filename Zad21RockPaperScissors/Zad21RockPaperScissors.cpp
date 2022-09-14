#include "RockPaperScissorsWIthComputerClass.hpp"
#include <iostream>


int main()
{
    unsigned short usersInput = 0;
    std::shared_ptr<RockPaperScissorsAbstract> game = nullptr;
    std::cout << "Chcesz grać z komputerem czy drugą graczką? Podaj numer(1.Komputer 2.Graczka): ";
    std::cin >> usersInput;
    switch (usersInput)
    {
    case 1:
        game = std::make_shared<RockPaperScissorsWithComputer>();
        break;
    //case 2: //zrobić opcję do gry z druga osoba

    }
    game->game();

}