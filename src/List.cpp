#include "List.hpp"

List::List()
{
    head = nullptr;
    end = nullptr; // insertRear in a loop with n elements
                   // is too slow (O(n^2)) without a pointer to the end
    var_length = 0;
}

List::~List()
{
    makenull();
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

    if (end == node)
    {
        end = node; // If inserting at end, this is the new end of list
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
        end = head;
    }
    else
    {
        insert(end, data);
    }
}

void List::makenull()
{
    ListNode* curr = head;

    while (curr != nullptr)
    {
        ListNode* tmp_next = curr->getNext();
        delete curr;
        curr = tmp_next;
    }

    var_length = 0;
    head = nullptr;
    end = nullptr;
}