#include "StackNode.hpp"

StackNode::StackNode(RGBPixelXY* p)
{
    pixel = p;
    next = nullptr;
}

StackNode* StackNode::getNext()
{
    return next;
}

void StackNode::setNext(StackNode* pnext)
{
    next = pnext;
}

RGBPixelXY* StackNode::getPixel()
{
    return pixel;
}
