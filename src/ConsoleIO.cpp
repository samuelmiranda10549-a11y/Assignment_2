#include "ConsoleIO.hpp"
#include <iostream>

ConsoleIO::ConsoleIO()
{
}

ConsoleIO::~ConsoleIO()
{
}

void ConsoleIO::printString(std::string str)
{
    std::cout << str;
}

std::string ConsoleIO::readString()
{
    std::string str;
    std::cin >> str;

    return str;
}