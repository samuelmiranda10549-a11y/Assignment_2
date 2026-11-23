#include "ListOfListsNode.hpp"

ListOfListsNode::ListOfListsNode(List* pdata)
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

List* ListOfListsNode::getData()
{
    return data;
}

ListOfListsNode::~ListOfListsNode()
{
}
