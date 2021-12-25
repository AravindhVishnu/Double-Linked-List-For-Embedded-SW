#include "../inc/DoubleLinkedList.h"
#include <cassert>

// Description: Class constructor
DoubleLinkedList::DoubleLinkedList()
{
    // Initialize items and insert into free list
    for (uint32_t i = 0U; i < MAX_LIST_ITEMS; i++)
    {
        if((i + 1U) < MAX_LIST_ITEMS)
        {
            _listItems[i]._nextPtr = &_listItems[i + 1U];
        }
        else
        {
            _listItems[i]._nextPtr = NULL;
        }
        _listItems[i]._prevPtr = NULL;
    }
    _freePtr = &_listItems[0];

    // Intialize head- and tail pointer
    _firstListItem._prevPtr = NULL;
    _lastListItem._nextPtr = NULL;
    _firstListItem._nextPtr = &_lastListItem;
    _lastListItem._prevPtr = &_firstListItem;
    _headPtr = &_firstListItem;
    _tailPtr = &_lastListItem;
}

// Description: Class destructor
DoubleLinkedList::~DoubleLinkedList()
{
}

// Description: Function returns true if the list is empty, otherwise false.
bool DoubleLinkedList::isListEmpty()
{
    if (_headPtr->_nextPtr == _tailPtr) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Description: Allocates one item from the free item list. Returns pointer
// to allocated list item or NULL if no items are available.
DoubleLinkedList::ListItem* DoubleLinkedList::allocateItem()
{
    ListItem* returnPtr = _freePtr;
    if(_freePtr != NULL)
    {
        _freePtr = returnPtr->_nextPtr;
        returnPtr->_nextPtr = NULL;
    }
    return returnPtr;
}

// Description: Free an item allocated with allocateItem function.
// Parameters: ListItem* listItemPtr - Pointer to the item to free
void DoubleLinkedList::freeItem(ListItem* listItemPtr)
{
    assert(listItemPtr != NULL);

    listItemPtr->_nbr = 0U;
    listItemPtr->_name = "";

    listItemPtr->_nextPtr = _freePtr;
    _freePtr = listItemPtr;
    listItemPtr->_prevPtr = NULL;
}

// Description: Removes the specific item from the list.
// Parameters: ListItem* listItemPtr - Pointer to the item to remove from the list.
void DoubleLinkedList::removeItem(ListItem* listItemPtr)
{
    assert(listItemPtr != NULL);

    (listItemPtr->_prevPtr)->_nextPtr = listItemPtr->_nextPtr;
    (listItemPtr->_nextPtr)->_prevPtr = listItemPtr->_prevPtr;
}

// Description: Add an item to the start of the list
// Parameters: ListItem* listItemPtr - Pointer to the item to add to the start of the list.
void DoubleLinkedList::addItemFirst(ListItem* listItemPtr)
{
    listItemPtr->_nextPtr = _headPtr->_nextPtr;
    listItemPtr->_prevPtr = _headPtr;
    (listItemPtr->_nextPtr)->_prevPtr = listItemPtr;
    _headPtr->_nextPtr = listItemPtr;
}

// Description: Add an item to the end of list
// Parameters: ListItem* listItemPtr - Pointer to the item to add to the end of the list.
void DoubleLinkedList::addItemLast(ListItem* listItemPtr)
{
    listItemPtr->_prevPtr = _tailPtr->_prevPtr;
    listItemPtr->_nextPtr = _tailPtr;
    (listItemPtr->_prevPtr)->_nextPtr = listItemPtr;
    _tailPtr->_prevPtr = listItemPtr;
}

// Description: Finds a specific item in the list. 
// Returns pointer to the list item is NULL if the item was not found.
// Parameters: uint32_t nbr - List item number
DoubleLinkedList::ListItem* DoubleLinkedList::findItem(uint32_t nbr)
{
    ListItem* returnPtr = NULL;
    ListItem* tempPtr = _headPtr->_nextPtr;

    // Deterministic execution time is preferred so always loop through the entire list
    while(tempPtr != _tailPtr)
    {
        if(returnPtr == NULL)
        {
            if(tempPtr->_nbr == nbr)
            {
                returnPtr = tempPtr;  // List item found
            }
        }
        tempPtr = tempPtr->_nextPtr;
    }
    return returnPtr;
}

// Description: Finds a specific item in the list.
// Returns pointer to the list item is NULL if the item was not found.
// Parameters: std::string name - List item name
DoubleLinkedList::ListItem* DoubleLinkedList::findItem(std::string name)
{
    ListItem* returnPtr = NULL;
    ListItem* tempPtr = _headPtr->_nextPtr;

    // Deterministic execution time is preferred so always loop through the entire list
    while(tempPtr != _tailPtr)
    {
        if(returnPtr == NULL)
        {
            if(name.compare(tempPtr->_name) == 0)
            {
                returnPtr = tempPtr;  // List item found
            }
        }
        tempPtr = tempPtr->_nextPtr;
    }
    return returnPtr;    
}

// Description: Get pointer to the head item in the list
const DoubleLinkedList::ListItem* DoubleLinkedList::getHeadItemPtr()
{
    return _headPtr;
}

// Description: Get pointer to the tail item in the list
const DoubleLinkedList::ListItem* DoubleLinkedList::getTailItemPtr()
{
    return _tailPtr;
}