#ifndef CORE_HPP
#define CORE_HPP

#include "ConsoleIO.hpp"
#include "ListOfLists.hpp"
#include "TinyImageJM.hpp"
#include "Stack.hpp"

class Core
{
    ConsoleIO* con;

    ListOfLists* stage1_create_pixel_list(TinyImageJM* img);
    Stack* stage1_create_stack(ListOfLists* pixel_list);
    void stage1(std::string img_name);
public:
    Core();
    ~Core();

    void start();
};

#endif // CORE_HPP
