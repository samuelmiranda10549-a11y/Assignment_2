#include "Core.hpp"

Core::Core()
{
    con = new ConsoleIO();
}

Core::~Core()
{
    delete con;
}

void Core::start()
{
    con->printString("Enter image name: ");
    std::string img_name = con->readString();
    con->printString(img_name);
}