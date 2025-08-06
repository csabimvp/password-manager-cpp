//
//  UserInterface.h
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#ifndef CORE_USERINTERFACE_H
#define CORE_USERINTERFACE_H

#include "Database.h"

class UserInterface
{
public:
    enum MenuItem
    {
        SHOW_ACCOUNTS       = 1,
        ADD_ACCOUNT,        // 2
        EDIT_ACCOUNT,       // 3
        DELETE_ACCOUNT,     // 4
        GENERATE_PASSWORD,  // 5
        SAVE_DATABASE,      // 6
        EXIT                // 7
    };
    
    UserInterface(Database* db_pointer);
    ~UserInterface();
    
    MenuItem GetMenu();
    void SetMenu(int input);
    void PrintMenu();
    void ActionMenu();
private:
    Database* m_Database_ptr;
    MenuItem m_Menu;
};

#endif
