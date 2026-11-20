#include "Core.hpp"

int main()
{
    Core* c = new Core();
    c->start();
    delete c;

    return 0;
}