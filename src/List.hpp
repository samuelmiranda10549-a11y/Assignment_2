#ifndef LIST_HPP
#define LIST_HPP

#include "ListNode.hpp"
#include "RGBPixelXY.hpp"

class List
{
    ListNode* head;
    unsigned int var_length;

    ListNode* retrieveNode(unsigned int index);
public:
    List();
    ~List();

    void insert(ListNode* node, RGBPixelXY* data);
    RGBPixelXY* retrieve(unsigned int index);
    void insertRear(RGBPixelXY* data);
    unsigned int length();
};

#endif // LIST_HPP
