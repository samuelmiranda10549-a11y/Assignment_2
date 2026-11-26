#ifndef CORE_HPP
#define CORE_HPP

#include "ConsoleIO.hpp"
#include "ListOfLists.hpp"
#include "TinyImageJM.hpp"
#include "Stack.hpp"
#include "HashTable.hpp"

class Core
{
    ConsoleIO* con;

    ListOfLists* stage1_create_pixel_list(TinyImageJM* img);
    Stack* stage1_create_stack(ListOfLists* pixel_list);
    Stack* stage1(std::string img_name, ListOfLists** out_DS_B,
        List** out_DS_C, HashTable** out_DS_D);

    void cleanup(Stack* DS_A, ListOfLists* DS_B, List* DS_C, HashTable* DS_D);

public:
    Core();
    ~Core();

    void start();
};

#endif // CORE_HPP
