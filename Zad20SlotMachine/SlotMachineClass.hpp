#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <map>
#include <stdint.h>

enum class Symbols { EXCLAMATIONMARK = 1, AT, HASH, DOLAR, PERCENT, CARET, AMPERSANT, ASTERISK }; 

class SlotMachine 
{
private:

	SlotMachine(const SlotMachine& other) = default;
	SlotMachine& operator= (const SlotMachine& other) = default;

	std::map<Symbols, uint16_t> _pointsForEachSymbol = {{Symbols::EXCLAMATIONMARK, 1}, {Symbols::AT, 5}, {Symbols::HASH, 10}, {Symbols::DOLAR, 25}, {Symbols::PERCENT, 50}, {Symbols::CARET, 100}, {Symbols::AMPERSANT, 200}, {Symbols::ASTERISK, 1000}};
	std::vector<Symbols> _drawnSymbols = {};
	uint16_t _points = 0;
	std::vector<Symbols> drawSymbols() const;
	void countPoints();
	void printSymbols() const;
	//static SlotMachine game;
public:
	SlotMachine();
	void game();
	//static SlotMachine& getInstance();
};


std::ostream& operator<<(std::ostream& s, const Symbols& other);

