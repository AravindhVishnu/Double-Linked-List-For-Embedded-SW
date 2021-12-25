#include <iostream>
#include "../inc/ExampleApplication.h"

int main(int argc, char *argv[])
{
    ExampleApplication obj;

    bool exec = true;

    while(exec)
    {
        obj.printOptions();

        int32_t input = 0;
        std::cin >> input;
        std::cout << "\n";

        switch(input)
        {
        case 0:
        {
            obj.printTeamMembers();
            break;
        }
        case 1:
        {
            std::cout << "Enter new team member number:\n";
            uint32_t nbr = 0;
            std::cin >> nbr;
            std::cout << "Enter new team member name:\n";
            std::string name;
            std::cin >> name;
            std::cout << "\n";
            obj.addTeamMember(nbr, name);
            break;
        }
        case 2:
        {
            std::cout << "Remove team number by number or name:\n";
            std::cout << "[0] - Remove by number \n";
            std::cout << "[1] - Remove by name \n";
            uint32_t option = 0;
            std::cin >> option;
            std::cout << "\n";
            if (option == 0)
            {
                std::cout << "Enter number of the team member to remove:\n";
                uint32_t nbr = 0;
                std::cin >> nbr;
                std::cout << "\n";
                obj.removeTeamMember(nbr);
            }
            else if (option == 1)
            {
                std::cout << "Enter name of the team member to remove:\n";
                std::string name;
                std::cin >> name;
                std::cout << "\n";
                obj.removeTeamMember(name);
            }
            else
            {
                std::cout << "Incorrect option - Please try again\n";
            }
            break;
        }
        case 3:
        {
            std::cout << "Find team number by number or name:\n";
            std::cout << "[0] - Find by number \n";
            std::cout << "[1] - Find by name \n";
            uint32_t option = 0;
            std::cin >> option;
            std::cout << "\n";
            if (option == 0)
            {
                std::cout << "Enter number of the team member to find:\n";
                uint32_t nbr = 0;
                std::cin >> nbr;
                std::cout << "\n";
                obj.findTeamMember(nbr);
            }
            else if (option == 1)
            {
                std::cout << "Enter name of the team member to find:\n";
                std::string name;
                std::cin >> name;
                std::cout << "\n";
                obj.findTeamMember(name);
            }
            else
            {
                std::cout << "Incorrect option - Please try again\n";
            }
            break;
        }
        case 4:
        {
            exec = false;
            break;
        }
        default:
        {
            std::cout << "Incorrect option - Please try again./n";
            break;
        }
        }
    }
    return 0;
}