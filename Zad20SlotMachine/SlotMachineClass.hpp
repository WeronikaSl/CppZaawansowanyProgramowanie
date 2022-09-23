#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <map>

enum class Symbols { EXCLAMATIONMARK = 1, AT, HASH, DOLAR, PERCENT, CARET, AMPERSANT, ASTERISK }; 

class SlotMachine 
{
private:
	SlotMachine();
	SlotMachine(const SlotMachine& other) = default;
	SlotMachine& operator= (const SlotMachine& other) = default;

	std::map<Symbols, unsigned short> _pointsForEachSymbol = {{Symbols::EXCLAMATIONMARK, 1}, {Symbols::AT, 5}, {Symbols::HASH, 10}, {Symbols::DOLAR, 25}, {Symbols::PERCENT, 50}, {Symbols::CARET, 100}, {Symbols::AMPERSANT, 200}, {Symbols::ASTERISK, 1000}};
	std::vector<Symbols> _drawnSymbols = {};
	unsigned short _points = 0;
	std::vector<Symbols> drawSymbols() const;
	void countPoints();
	void printSymbols() const;
	static SlotMachine game;
public:
	void game();
	static SlotMachine& getInstance();
};


std::ostream& operator<<(std::ostream& s, const Symbols& other);

