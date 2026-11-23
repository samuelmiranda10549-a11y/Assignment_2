#include "ListOfLists.hpp"

// Copied from List implementation

ListOfLists::ListOfLists()
{
    head = nullptr;
    end = nullptr; // insertRear in a loop with n elements
                   // is too slow (O(n^2)) without a pointer to the end
    var_length = 0;
}

ListOfLists::~ListOfLists()
{
    makenull();
}

void ListOfLists::insert(ListOfListsNode* node, RGBPixelXY* data)
{
    var_length++;
    ListOfListsNode* new_node = new ListOfListsNode(data);

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

    if (end == node)
    {
        end = node; // If inserting at end, this is the new end of list
    }
}

RGBPixelXY* ListOfLists::retrieve(unsigned int index)
{
    return retrieveNode(index)->getData();
}

ListOfListsNode* ListOfLists::retrieveNode(unsigned int index)
{
    ListOfListsNode* curr = head;

    for (unsigned int curr_index = 0; curr_index < index; curr_index++)
    {
        curr = curr->getNext();
    }

    return curr;
}

unsigned int ListOfLists::length()
{
    return var_length;
}

void ListOfLists::insertRear(RGBPixelXY* data)
{
    if (head == nullptr)
    {
        var_length++;
        head = new ListOfListsNode(data);
        end = head;
    }
    else
    {
        insert(end, data);
    }
}

void ListOfLists::makenull()
{
    ListOfListsNode* curr = head;

    while (curr != nullptr)
    {
        ListOfListsNode* tmp_next = curr->getNext();
        delete curr;
        curr = tmp_next;
    }

    var_length = 0;
    head = nullptr;
    end = nullptr;
}