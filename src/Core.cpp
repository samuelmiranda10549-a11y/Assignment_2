#include "Core.hpp"
#include "TinyImageJM.hpp"
#include "RGBPixelXY.hpp"

/* DS implementation notes:
 * 1: One of the lessons we learned in the first assignment is consistency in data structure usage.
 * especially about whether a data structure should delete its elements, I argue no, since the user of a DS
 * may not want so, this has been the source of several double-frees and use-after-frees problems. So,
 * on destruction, a DS should not free the elements, they should be freed by the DS user to maintain modularity
 * and consistency.
 *
 * 2: The data structure nodes should point directly to their stored elements unless an abstraction layer is needed
 * (e.g. to compare) we believe this decision is allowed since the assignment statement does not specify this
 * and it is mentioned that every decision is reasonable if clearly explained and does not contradict the requirements.
 * We believe having an extra "Elem" class for every element adds complexity and may be confusing (like getElem()->getElem()
 * on list nodes, which is code we had on the first assignment), this does not impact modularity as, the Professor said
 * that if we need to store different types on a DS, we should copy the code and replace the types, which we have to do
 * anyway, intermediate class or not. It does not affect integrity either, as we can implement clone() directly,
 * although this depends on the object.
 */

Core::Core()
{
    con = new ConsoleIO();
}

Core::~Core()
{
    delete con;
}

ListOfLists* Core::stage1_create_pixel_list(TinyImageJM* img)
{
    ListOfLists* pixel_list = new ListOfLists();

    for (unsigned int row = 0; row < img->getHeight(); row++)
    {
        List* row_list = new List();

        for (unsigned int col = 0; col < img->getWidth(); col++)
        {
            RGBPixelXY* pixel = new RGBPixelXY(col, row);
            pixel->getFromRaw(img->getImagePointertoInternal(),
                    img->getWidth(), img->getHeight(), col, row);

            row_list->insertRear(pixel);
        }

        pixel_list->insertRear(row_list);
    }

    return pixel_list;
}

Stack* Core::stage1_create_stack(ListOfLists* pixel_list)
{
    // DS A
    // The pixel list is already in sequential order
    Stack* s = new Stack();

    for (unsigned int row_num = 0; row_num < pixel_list->length(); row_num++)
    {
        List* row_list = pixel_list->retrieve(row_num);

        for (unsigned int col_num = 0; col_num < row_list->length(); col_num++)
        {
            s->push(row_list->retrieve(col_num));
        }
    }

    return s;
}

Stack* Core::stage1(std::string img_name, ListOfLists** out_DS_B,
        List** out_DS_C, HashTable** out_DS_D)
{
    // stage2 needs all of the data structures returned (also for modularity)
    // - The first return value is DS_A (the Stack), if nullptr, it signals failure

    // The only way to return multiple values in C++ without a list is with a pointer parameter
    // so the called function can set the value. List cannot be used because it's only valid for
    // one data type.
    // Source: https://www.geeksforgeeks.org/c/how-to-return-multiple-values-from-a-function-in-c-or-cpp/
    TinyImageJM* img = new TinyImageJM(img_name);
    Stack* DS_A = nullptr;

    if (img->loadImageFromDisk())
    {
        // Load to a single RGBPixel list for simplicity and insert to all data structures from the list to
        // avoid duplicating the same loop to insert into different data structures
        ListOfLists* DS_B = stage1_create_pixel_list(img);
        con->printString("Stage 1: DS B (List of Lists) created\n");

        DS_A = stage1_create_stack(DS_B);
        con->printString("Stage 1: DS A (Stack) created\n");

        *out_DS_B = DS_B; // return DS_B
    }

    delete img;

    return DS_A;
}

void Core::cleanup(Stack* DS_A, ListOfLists* DS_B, List* DS_C, HashTable* DS_D)
{
    for (unsigned int row = 0; row < DS_B->length(); row++)
    {
        List* row_list = DS_B->retrieve(row);

        for (unsigned int col = 0; col < row_list->length(); col++)
        {
            delete row_list->retrieve(col); // Delete RGBPixelXY
        }

        delete row_list;
    }

    delete DS_A;
    delete DS_B;
    delete DS_C;
    delete DS_D;
}

void Core::start()
{
    // According to requirements, program will ask again any invalid input
    Stack* DS_A = nullptr;
    ListOfLists* DS_B = nullptr;
    List* DS_C = nullptr;
    HashTable* DS_D = nullptr;

    while (DS_A == nullptr)
    {
        con->printString("Enter image name: ");
        std::string img_name = con->readString();

        DS_A = stage1(img_name, &DS_B, &DS_C, &DS_D);
    }

    cleanup(DS_A, DS_B, DS_C, DS_D);
}
