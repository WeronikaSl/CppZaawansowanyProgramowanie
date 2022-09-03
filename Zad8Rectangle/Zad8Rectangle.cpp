#include "Rectangle.hpp"
#include "RectangleGenerator.hpp"
#include "RectangleManager.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //RectangleGenerator rg;
    //Rectangle rec1 = rg.generateRectangle();
    //std::cout << rec1 << std::endl;
    //std::cout << rec1.isSquare() << std::endl;
    RectangleManager rm;

    printRectangles(rm.getRectangles());

    std::cout << std::endl << std::endl;

    std::cout << "Pole większe od 50: " << rm.countRectangleBiggerThan(50) << std::endl;

    std::cout << std::endl << std::endl << "Kwadraty: " << std::endl;

    std::vector<Rectangle> squares = rm.copyRectangles();
    printRectangles(squares);
    std::cout << std::endl << std::endl << "Malejące pole: " << std::endl;
    
    rm.sortAreaDescending();
    printRectangles(rm.getRectangles());

    std::cout << std::endl << std::endl << "Usunięte prostokąty o boku 0:" << std::endl;
    rm.deleteInvalid();
    printRectangles(rm.getRectangles());


}
