#ifndef CORE_HPP
#define CORE_HPP

#include "ConsoleIO.hpp"

class Core
{
    ConsoleIO* con;

    void stage1(std::string img_name);
public:
    Core();
    ~Core();

    void start();
};

#endif // CORE_HPP
