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

List* Core::stage1_create_pixel_list(TinyImageJM* img)
{
    List* pixel_list = new List();

    for (unsigned int row = 0; row < img->getHeight(); row++)
    {
        for (unsigned int col = 0; col < img->getWidth(); col++)
        {
            RGBPixelXY* pixel = new RGBPixelXY(col, row);
            pixel->getFromRaw(img->getImagePointertoInternal(),
                    img->getWidth(), img->getHeight(), col, row);

            pixel_list->insertRear(pixel);
        }
    }

    return pixel_list;
}

void Core::stage1(std::string img_name)
{
    // stage2 needs all of the data structures returned
    TinyImageJM* img = new TinyImageJM(img_name);

    if (img->loadImageFromDisk())
    {
        // Load to a single RGBPixel list for simplicity and insert to all data structures from the list to
        // avoid duplicating the same loop to insert into different data structures
        List* pixel_list = stage1_create_pixel_list(img);

        delete pixel_list;
    }

    delete img;
}

void Core::start()
{
    con->printString("Enter image name: ");
    std::string img_name = con->readString();

    stage1(img_name);
}