#ifndef CORE_HPP
#define CORE_HPP

#include "ConsoleIO.hpp"
#include "List.hpp"
#include "TinyImageJM.hpp"

class Core
{
    ConsoleIO* con;

    List* stage1_create_pixel_list(TinyImageJM* img);
    void stage1(std::string img_name);
public:
    Core();
    ~Core();

    void start();
};

#endif // CORE_HPP
