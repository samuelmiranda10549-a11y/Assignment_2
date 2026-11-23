#include "ListOfListsNode.hpp"

ListOfListsNode::ListOfListsNode(RGBPixelXY* pdata)
{
    data = pdata;
    next = nullptr;
}

ListOfListsNode* ListOfListsNode::getNext()
{
    return next;
}

void ListOfListsNode::setNext(ListOfListsNode* pnext)
{
    next = pnext;
}

RGBPixelXY* ListOfListsNode::getData()
{
    return data;
}

ListOfListsNode::~ListOfListsNode()
{
}
