#include "ListNode.hpp"

ListNode::ListNode(RGBPixelXY* pdata)
{
    data = pdata;
    next = nullptr;
}

ListNode* ListNode::getNext()
{
    return next;
}

void ListNode::setNext(ListNode* pnext)
{
    next = pnext;
}

RGBPixelXY* ListNode::getData()
{
    return data;
}

ListNode::~ListNode()
{
}
