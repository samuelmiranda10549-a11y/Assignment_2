#include "List.hpp"

List::List()
{
    head = nullptr;
    var_length = 0;
}

List::~List()
{
    //makenull();
}

void List::insert(ListNode* node, RGBPixelXY* data)
{
    var_length++;
    ListNode* new_node = new ListNode(data);

    if (node == nullptr)
    {
        // Insert at beginning of list
        new_node->setNext(head);
        head = new_node;
    }
    else
    {
        new_node->setNext(node->getNext());
        node->setNext(new_node);
    }

    if (head == nullptr)
    {
        head = new_node;
    }
}

RGBPixelXY* List::retrieve(unsigned int index)
{
    return retrieveNode(index)->getData();
}

ListNode* List::retrieveNode(unsigned int index)
{
    ListNode* curr = head;

    for (unsigned int curr_index = 0; curr_index < index; curr_index++)
    {
        curr = curr->getNext();
    }

    return curr;
}

unsigned int List::length()
{
    return var_length;
}

void List::insertRear(RGBPixelXY* data)
{
    if (head == nullptr)
    {
        var_length++;
        head = new ListNode(data);
    }
    else
    {
        // The last index of a list is one less than the length
        insert(retrieveNode(var_length - 1), data);
    }
}