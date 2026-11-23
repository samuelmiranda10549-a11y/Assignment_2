#ifndef LISTOFLISTS_HPP
#define LISTOFLISTS_HPP

#include "ListOfListsNode.hpp"
#include "RGBPixelXY.hpp"

class ListOfLists
{
    ListOfListsNode* head;
    ListOfListsNode* end;
    unsigned int var_length;

    ListOfListsNode* retrieveNode(unsigned int index);
public:
    ListOfLists();
    ~ListOfLists();

    void insert(ListOfListsNode* node, RGBPixelXY* data);
    RGBPixelXY* retrieve(unsigned int index);
    void insertRear(RGBPixelXY* data);
    unsigned int length();
    void makenull();
};

#endif // LISTOFLISTS_HPP
