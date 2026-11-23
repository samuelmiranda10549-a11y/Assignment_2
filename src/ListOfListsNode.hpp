#ifndef LISTOFLISTSNODE_HPP
#define LISTOFLISTSNODE_HPP

#include "RGBPixelXY.hpp"

class ListOfListsNode
{
    RGBPixelXY* data;
    ListOfListsNode* next;

public:
    ListOfListsNode(RGBPixelXY* pdata);
    ~ListOfListsNode();

    ListOfListsNode* getNext();
    void setNext(ListOfListsNode* pnext);
    RGBPixelXY* getData();
};

#endif // LISTOFLISTSNODE_HPP
