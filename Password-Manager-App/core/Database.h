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

class Database
{
private:
    std::string m_FileName;
    std::vector<std::vector<std::string>> m_RawData;
    std::vector<Account*> m_Accounts;
public:
    Database(const std::string& file_name);
    Database(Database& other);
    ~Database();
    std::vector<std::string> ParseLine(std::string&& row);
    std::vector<std::vector<std::string>> LoadDatabase(const std::string& fileName);
    void PrintAll();
    void AddAccount(Account* acc_ptr);
    void DeleteAccount(const int& acc_index);
    void SaveDatabase();
};

#endif
