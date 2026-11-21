#include "Core.hpp"
#include "TinyImageJM.hpp"
#include "RGBPixelXY.hpp"

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