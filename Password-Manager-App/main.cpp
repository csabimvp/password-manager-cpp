#include "core/UserInterface.h"
#include <iostream>
#include <filesystem>

int main()
{
    auto path = std::filesystem::path{"/Users/csabimvp/dev/projects/xcode-projects/Password-Manager-App/Passwords.txt"};
    Database* db_pointer = new Database(path);
    UserInterface ui(db_pointer);
    
    while (ui.GetMenu() != UserInterface::MenuItem::EXIT)
    {
        ui.PrintMenu();
        std::string MenuOption;
        std::getline(std::cin, MenuOption);
        ui.SetMenu(std::stoi(MenuOption));
        ui.ActionMenu();
        std::cout << "\n" << std::endl;
    }
}
