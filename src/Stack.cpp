#include "Stack.hpp"

Stack::Stack()
{
    top = nullptr;
    var_length = 0; 
}

void Stack::push(RGBPixelXY* pixel)
{
    var_length++;
    StackNode* new_node = new StackNode(pixel);
    new_node->setNext(top);
    top = new_node;
}
RGBPixelXY* Stack::pop()
{
    if (top == nullptr)
    {
        return nullptr; // Stack is empty
    }

    var_length--;
    RGBPixelXY* pixel=top->getPixel();
    StackNode* nextTop=top->getNext();
    delete top;
    top=nextTop;
    return pixel;

}
bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::makenull()
{
    while (top != nullptr)
    {
        StackNode* tmp_next = top->getNext();
        delete top;
        top = tmp_next;
    }
    var_length = 0;
}

unsigned int Stack::length()
{
    return var_length;
}



