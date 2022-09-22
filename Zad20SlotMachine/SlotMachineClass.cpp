#include "SlotMachineClass.hpp"

std::ostream& operator<<(std::ostream& s, const Symbols& other)
{
    switch (other)
    {
    case Symbols::EXCLAMATIONMARK:
        s << '!';
        break;
    case Symbols::AT:
        s << '@';
        break;
    case Symbols::HASH:
        s << '#';
        break;
    case Symbols::DOLAR:
        s << '$';
        break;
    case Symbols::PERCENT:
        s << '%';
        break;
    case Symbols::CARET:
        s << '^';
        break;
    case Symbols::AMPERSANT:
        s << '&';
        break;
    case Symbols::ASTERISK:
        s << '*';
        break;
    default:
        s << "Error";
        break;
    }
    return s;
}

std::vector<Symbols> SlotMachine::drawSymbols() const
{
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> distr(1, 8);

    std::vector<Symbols> symbols (5, Symbols::EXCLAMATIONMARK);    
    std::for_each(symbols.begin(), symbols.end(), [&distr, &e](Symbols& s) {s = static_cast<Symbols>(distr(e));});
   
    return symbols;
}

void SlotMachine::countPoints()
{
    std::map<Symbols, unsigned short> amountsOfSymbols = {};
    unsigned short amountOfEach = 0;
    for (size_t i = 1; i <= 8; ++i)
    {
        amountOfEach = std::count(_drawnSymbols.cbegin(), _drawnSymbols.cend(), static_cast<Symbols>(i));

        if (static_cast<Symbols>(i) == Symbols::ASTERISK)
        {
            _points += amountOfEach * _pointsForEachSymbol[Symbols::ASTERISK];
        }
        else if (amountOfEach > 2)
        {
            _points += amountOfEach * _pointsForEachSymbol[static_cast<Symbols>(i)];
        }

    }
    std::cout << "Ilość zdobytych punktów to: " << _points << std::endl;

}

void SlotMachine::printSymbols() const
{
    std::cout << "Wylosowane elementy" << std::endl;
    for (const auto& elem : _drawnSymbols)
    {
        std::cout << elem << " ";
    }
}

SlotMachine::SlotMachine()
{
    _drawnSymbols = drawSymbols();
}

void SlotMachine::game()
{
    printSymbols();
    std::cout << std::endl;
    countPoints();
}

SlotMachine SlotMachine::getInstance()
{
    return SlotMachine();
}
