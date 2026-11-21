#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include "RGBPixelXY.hpp"

class ListNode
{
    RGBPixelXY* data;
    ListNode* next;

public:
    ListNode(RGBPixelXY* pdata);
    ~ListNode();

    ListNode* getNext();
    void setNext(ListNode* pnext);
    RGBPixelXY* getData();
};

#endif // LISTNODE_HPP
