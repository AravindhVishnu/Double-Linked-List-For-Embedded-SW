#include "../inc/ExampleApplication.h"

// Description: Class constructor
ExampleApplication::ExampleApplication()
{
}

// Description: Class destructor
ExampleApplication::~ExampleApplication()
{
}

// Description: Print all program option commands
void ExampleApplication::printOptions()
{
    std::cout << "\n";
    std::cout << "Program options:\n";
    std::cout << "[0] - Print all team members \n";
    std::cout << "[1] - Add team member \n";
    std::cout << "[2] - Remove team member \n";
    std::cout << "[3] - Find team member \n";
    std::cout << "[4] - End program \n";
    std::cout << "\n";
}

// Description: Print the number nd name of all team members
void ExampleApplication::printTeamMembers()
{
    if (_list.isListEmpty() == true)
    {
        std::cout << "Team has no members\n";
    }
    else
    {
        const DoubleLinkedList::ListItem* tempPtr = _list.getHeadItemPtr()->_nextPtr;

        while (tempPtr != _list.getTailItemPtr())
        {
            if (tempPtr != NULL)
            {
                std::cout << "Team member " << tempPtr->_nbr << ": " << tempPtr->_name << "\n";
            }
            tempPtr = tempPtr->_nextPtr;
        }
    }
}

// Description: Add team member
void ExampleApplication::addTeamMember(uint32_t nbr, std::string name)
{
    const DoubleLinkedList::ListItem* tempOnePtr = _list.findItem(nbr);
    const DoubleLinkedList::ListItem* tempTwoPtr = _list.findItem(name);

    if (tempOnePtr != NULL)
    {
        std::cout << "Number occupied by another team member\n";
    }
    else if (tempTwoPtr != NULL)
    {
        std::cout << "Name occupied by another team member\n";
    }
    else
    {
        DoubleLinkedList::ListItem* itemPtr = _list.allocateItem();
        if (itemPtr == NULL)
        {
            std::cout << "Team is full - Max capacity is: " << DoubleLinkedList::MAX_LIST_ITEMS << "\n";
        }
        else
        {
            itemPtr->_nbr = nbr;
            itemPtr->_name = name;

            _list.addItemFirst(itemPtr);

            std::cout << "Team member " << nbr << ": " << name << " has been added\n";
        }
    }
}

// Description: Remove team member based on number
void ExampleApplication::removeTeamMember(uint32_t nbr)
{
    DoubleLinkedList::ListItem* tempPtr = _list.findItem(nbr);
    if (tempPtr == NULL)
    {
        std::cout << "No team member has that number\n";
    }
    else
    {
        _list.removeItem(tempPtr);
        _list.freeItem(tempPtr);

        std::cout << "Team member " << nbr << " has been removed\n";
    }
}

// Description: Remove team member based on name
void ExampleApplication::removeTeamMember(std::string name)
{
    DoubleLinkedList::ListItem* tempPtr = _list.findItem(name);
    if (tempPtr == NULL)
    {
        std::cout << "No team member has that name\n";
    }
    else
    {
        _list.removeItem(tempPtr);
        _list.freeItem(tempPtr);

        std::cout << "Team member " << name << " has been removed\n";
    }
}

// Description: Find team member based on number
void ExampleApplication::findTeamMember(uint32_t nbr)
{
    const DoubleLinkedList::ListItem* tempPtr = _list.findItem(nbr);
    if (tempPtr == NULL)
    {
        std::cout << "No team member has that number\n";
    }
    else
    {
        std::cout << "Team member with that number exists and has name:" << tempPtr->_name << "\n";
    }
}

// Description: Find team member based on name
void ExampleApplication::findTeamMember(std::string name)
{
    const DoubleLinkedList::ListItem* tempPtr = _list.findItem(name);
    if (tempPtr == NULL)
    {
        std::cout << "No team member has that name\n";
    }
    else
    {
        std::cout << "Team member with that name exists and has number:" << tempPtr->_nbr << "\n";
    }
}