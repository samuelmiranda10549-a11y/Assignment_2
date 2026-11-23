#ifndef LISTOFLISTS_HPP
#define LISTOFLISTS_HPP

#include "ListOfListsNode.hpp"
#include "List.hpp"

class ListOfLists
{
    ListOfListsNode* head;
    ListOfListsNode* end;
    unsigned int var_length;

    ListOfListsNode* retrieveNode(unsigned int index);
public:
    ListOfLists();
    ~ListOfLists();

    void insert(ListOfListsNode* node, List* data);
    List* retrieve(unsigned int index);
    void insertRear(List* data);
    unsigned int length();
    void makenull();
};

#endif // LISTOFLISTS_HPP
