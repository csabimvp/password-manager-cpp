//
//  UserInterface.cpp
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#include "UserInterface.h"
#include "../utils/Password.h"
#include <string>
#include <iostream>

UserInterface::UserInterface(Database* db_pointer)
:m_Database_ptr(db_pointer)
{
    std::cout << "User Interface initialised." << std::endl;
}

UserInterface::~UserInterface()
{
    delete m_Database_ptr;
    std::cout << "UI deleted." << std::endl;
}

std::string GeneratePasswordUI()
{
    std::string pw_length;
    std::string special_character_input;
    bool special_character;
    
    std::cout << "Password length? ():" ;
    std::getline(std::cin, pw_length);
    std::cout << "Include special characters? (y) - (n)";
    std::getline(std::cin, special_character_input);
    
    if (special_character_input == "y" || special_character_input == "yes")
    { special_character = true; }
    else { special_character = false; }
    
    Password pw = Password(std::stoi(pw_length), special_character);
    return pw.GetPassword();
}

void UserInterface::PrintMenu()
{
    std::cout << "--- MENU ---" << std::endl;
    std::cout << "#1 - SHOW ACCOUNTS" << std::endl;
    std::cout << "#2 - ADD ACCOUNT" << std::endl;
    std::cout << "#3 - EDIT ACCOUNT" << std::endl;
    std::cout << "#4 - DELETE ACCOUNT" << std::endl;
    std::cout << "#5 - GENERATE PASSWORD" << std::endl;
    std::cout << "#6 - SAVE DATABASE" << std::endl;
    std::cout << "#7 - EXIT" << std::endl;
    std::cout << "#";
}

Account* ActionAddAccount()
{
    std::string account_name;
    std::string account_user_name;
    std::string password;
    std::string passwordRequest;
    std::string url;
    
    std::cout << "Enter Account Name: ";
    std::getline(std::cin, account_name);
    std::cout << "Enter Account User Name: ";
    std::getline(std::cin, account_user_name);
    std::cout << "Generate new Password? ()";
    std::getline(std::cin, passwordRequest);
    if (passwordRequest == "y" || passwordRequest == "yes")
    {
        password = GeneratePasswordUI();
    }
    else
    {
        std::cout << "Enter Account Password: ";
        std::getline(std::cin, password);
    }
    std::cout << "Enter URL: ";
    std::getline(std::cin, url);
    
    Account* acc_ptr = new Account(std::move(account_name), std::move(account_user_name), std::move(password), std::move(url));
    return acc_ptr;
}

void UserInterface::SetMenu(int input)
{
    switch(input)
    {
        case 1:
            m_Menu = MenuItem::SHOW_ACCOUNTS;
            break;
        case 2:
            m_Menu = MenuItem::ADD_ACCOUNT;
            break;
        case 3:
            m_Menu = MenuItem::EDIT_ACCOUNT;
            break;
        case 4:
            m_Menu = MenuItem::DELETE_ACCOUNT;
            break;
        case 5:
            m_Menu = MenuItem::GENERATE_PASSWORD;
            break;
        case 6:
            m_Menu = MenuItem::SAVE_DATABASE;
            break;
        case 7:
            m_Menu = MenuItem::EXIT;
            break;
    }
}

void UserInterface::ActionMenu()
{
    switch (m_Menu) {
        case MenuItem::SHOW_ACCOUNTS:
            (*m_Database_ptr).PrintAll();
            break;
            
        case MenuItem::ADD_ACCOUNT:
        {
            Account* accptr = ActionAddAccount();
            (*m_Database_ptr).AddAccount(accptr);
            break;
        }
            
        case MenuItem::EDIT_ACCOUNT:
            std::cout << "Edit Account..." << std::endl;
            break;
            
        case MenuItem::DELETE_ACCOUNT:
        {
            std::string account_index;
            std::cout << "Enter Account ID for deletion: ()";
            std::getline(std::cin, account_index);
            (*m_Database_ptr).DeleteAccount(std::stoi(account_index));
            break;
        }
            
        case MenuItem::SAVE_DATABASE:
        {
            std::cout << "Saving Database..." << std::endl;
            (*m_Database_ptr).SaveDatabase();
            break;
        }
            
        case MenuItem::GENERATE_PASSWORD:
        {
            std::string password = GeneratePasswordUI();
            std::cout << password << std::endl;
            break;
        }
            
        case MenuItem::EXIT:
            std::cout << "Exiting..." << std::endl;
    }
}

UserInterface::MenuItem UserInterface::GetMenu()
{
    return m_Menu;
}
