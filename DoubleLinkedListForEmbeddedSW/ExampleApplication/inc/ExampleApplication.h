#pragma once
#include "../lib/inc/DoubleLinkedList.h"

// Example application implementing a team member directory.
class ExampleApplication
{
public:

    // Description: Class constructor
    ExampleApplication();

    // Description: Class destructor
    ~ExampleApplication();

    // Description: Print all program option commands
    void printOptions();

    // Description: Print the number nd name of all team members
    void printTeamMembers();

    // Description: Add team member
    void addTeamMember(uint32_t nbr, std::string name);

    // Description: Remove team member based on number
    void removeTeamMember(uint32_t nbr);

    // Description: Remove team member based on name
    void removeTeamMember(std::string name);

    // Description: Find team member based on number
    void findTeamMember(uint32_t nbr);

    // Description: Find team member based on name
    void findTeamMember(std::string name);

private:

    // DoubleLinkedList object
    DoubleLinkedList _list;
    
};
