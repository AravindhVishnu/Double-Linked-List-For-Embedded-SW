#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

// Double link list implementation for use in Embedded SW.
class DoubleLinkedList
{
public:

    // Max number of items supported in the list
    static const uint32_t MAX_LIST_ITEMS = 10U;

    struct ListItem
    {
    public:
        uint32_t _nbr;  // List item number
        std::string _name;  // List item name
        struct ListItem* _prevPtr;  // Pointer to the previous list item
        struct ListItem* _nextPtr;  // Pointer to the next list item
    };

    // Description: Class constructor
    DoubleLinkedList();

    // Description: Class destructor
    ~DoubleLinkedList();

    // Description: Object initialization function
    void init();

    // Description: Function returns true if the list is empty, otherwise false.
    bool isListEmpty();

    // Description: Allocates one item from the free item list. Returns pointer
    // to allocated list item or NULL if no items are available.
    DoubleLinkedList::ListItem* allocateItem();

    // Description: Free an item allocated with allocateItem function.
    // Parameters: ListItem* listItemPtr - Pointer to the item to free
    void freeItem(ListItem* listItemPtr);

    // Description: Removes the specific item from the list.
    // Parameters: ListItem* listItemPtr - Pointer to the item to remove from the list.
    void removeItem(ListItem* listItemPtr);

    // Description: Add an item to the start of the list
    // Parameters: ListItem* listItemPtr - Pointer to the item to add to the start of the list.
    void addItemFirst(ListItem* listItemPtr);

    // Description: Add an item to the end of list
    // Parameters: ListItem* listItemPtr - Pointer to the item to add to the end of the list.
    void addItemLast(ListItem* listItemPtr);

    // Description: Finds a specific item in the list.
    // Returns pointer to the list item is NULL if the item was not found.
    // Parameters: uint32_t nbr - List item number
    DoubleLinkedList::ListItem* findItem(uint32_t nbr);

    // Description: Finds a specific item in the list.
    // Returns pointer to the list item is NULL if the item was not found.
    // Parameters: std::string name - List item name
    DoubleLinkedList::ListItem* findItem(std::string name);

    // Description: Get pointer to the head item in the list
    const DoubleLinkedList::ListItem* getHeadItemPtr();

    // Description: Get pointer to the tail item in the list
    const DoubleLinkedList::ListItem* getTailItemPtr();

private:

    // Static initialization of all list items
    ListItem _listItems[MAX_LIST_ITEMS] = {};
    // First list item
    ListItem _firstListItem = {};
    // Last list item
    ListItem _lastListItem = {};
    // Pointer to the last list item
    ListItem* _tailPtr;
    // Pointer to the first list item
    ListItem* _headPtr;
    // Pointer to the free item list
    ListItem* _freePtr;

};