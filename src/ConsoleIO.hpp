#ifndef CONSOLEIO_HPP
#define CONSOLEIO_HPP

#include <string>

class ConsoleIO
{
public:
    ConsoleIO();
    ~ConsoleIO();

    void printString(std::string str);
    std::string readString();
};

#endif // CONSOLEIO_HPP
