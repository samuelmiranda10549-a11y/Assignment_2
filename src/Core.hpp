#ifndef CORE_HPP
#define CORE_HPP

#include "ConsoleIO.hpp"

class Core
{
    ConsoleIO* con;

public:
    Core();
    ~Core();

    void start();
};

#endif // CORE_HPP
