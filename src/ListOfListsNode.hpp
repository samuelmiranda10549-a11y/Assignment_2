#ifndef LISTOFLISTSNODE_HPP
#define LISTOFLISTSNODE_HPP

#include "List.hpp"

class ListOfListsNode
{
    List* data;
    ListOfListsNode* next;

public:
    ListOfListsNode(List* pdata);
    ~ListOfListsNode();

    ListOfListsNode* getNext();
    void setNext(ListOfListsNode* pnext);
    List* getData();
};

#endif // LISTOFLISTSNODE_HPP
