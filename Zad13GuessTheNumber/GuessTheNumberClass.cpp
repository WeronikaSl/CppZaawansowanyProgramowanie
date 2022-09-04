#include "GuessTheNumberClass.hpp"


int GuessTheNumber::generateNumberToGuess() const
{
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> distr(1, 100);
    return distr(e);
}

int GuessTheNumber::getUserInput() const
{
    int guess = 0;
    std::cout << "Podaj liczbę: " << std::endl;
    std::cin >> guess;
    return guess;
}


void GuessTheNumber::isClose(int guess) const
{
    int value = _numberToGuess - guess;
    bool condition1 = ((value > 0) && (value <= 3));
    bool condition2 = ((value <  0) && (value >= -3));
    if(condition1 || condition2)
    {
        std::cout << "Jesteś już blisko!" << std::endl;
    }
}

GuessTheNumber::GuessTheNumber()
{
    _numberToGuess = generateNumberToGuess();
}

void GuessTheNumber::guess() const
{
    int guess = 0;
    do
    {
        guess = getUserInput();

        if (guess > _numberToGuess)
        {
            std::cout << "Liczba jest mniejsza" << std::endl;
            isClose(guess);
        }
        else if (guess < _numberToGuess)
        {
            std::cout << "Liczba jest większa" << std::endl;
            isClose(guess);
        }
        else
        {
            std::cout << "Gratuluję, zgadłaś!" << std::endl;

        }
    } while (guess != _numberToGuess);
}
