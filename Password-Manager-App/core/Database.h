//
//  Database.h
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#ifndef CORE_DATABASE_H
#define CORE_DATABASE_H

#include "../utils/Account.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Database
{
public:
    enum DatabaseFormat
    {
        COMMA_SEPERATED = 1,
        TAB_SEPERATED,
        OTHER
    };
    
    Database(const std::string& file_path);
    Database(Database& other);
    ~Database();
    std::vector<std::string> ParseLine(std::string&& row);
//    bool SortAccounts(Account* acc1, Account* acc2);
    void LoadDatabase();
    void PrintAll();
    void AddAccount(Account* acc_ptr);
    void DeleteAccount(const int& acc_index);
    void SaveDatabase();

private:
    std::string m_FilePath;
    std::vector<Account*> m_Accounts;
    DatabaseFormat m_Format;
};

#endif
