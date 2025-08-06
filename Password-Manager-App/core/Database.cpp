//
//  Database.cpp
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#include "Database.h"
#include "../utils/Account.h"
#include <fstream>

std::vector<std::string> Database::ParseLine(std::string&& row)
{
    // Creating a vector for each row, and reserving 5 items to increase performance.
    // This 5 needs to be incremented once we are adding more data into the rows.
    std::vector<std::string> rowData;
    rowData.reserve(5);
    size_t start = 0;
    bool inQuotes = false;
    
    for (size_t i = 0; i < row.length(); i++)
    {
        if (!inQuotes && row[i] == ',')
        {
            rowData.push_back(row.substr(start, i - start));
            start = i + 1;
        }
        else if (row[i] == '"')
        {
            inQuotes = true;
        }
    }
    rowData.push_back(row.substr(start));
    return rowData;
}

std::vector<std::vector<std::string>> Database::LoadDatabase(const std::string& fileName)
{
    std::vector<std::vector<std::string>> data;
    data.reserve(20);
    std::ifstream file(fileName);
    
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << fileName << std::endl;
    }
    
    std::string line;
    while (std::getline(file, line))
    {
        data.push_back(ParseLine(std::move(line)));
    }
    
    file.close();
    return data;
}

Database::Database(const std::string& file_name)
:m_FileName(file_name)
{
    m_RawData = LoadDatabase(m_FileName);
    std::cout << "Database loaded from: " << file_name << std::endl;
    
    for (auto item : m_RawData)
    {
        Account* acc_ptr = new Account(std::move(item[0]), std::move(item[1]), std::move(item[2]), std::move(item[3]));
        m_Accounts.push_back(acc_ptr);
    }
    
    std::cout << "#" << m_RawData.size() << " Accounts loaded." << std::endl;
}

Database::Database(Database& other)
{
    std::cout << "Database was copied." << std::endl;
}

Database::~Database()
{
    int accounts_size = static_cast<int>(m_Accounts.size());
    for (int x = 0; x < accounts_size; x++)
    {
        delete m_Accounts[x];
    }
    std::cout << "#" << std::to_string(accounts_size) << " Accounts deleted." << std::endl;
    std::cout << "Database removed." << std::endl;
}


void Database::PrintAll()
{
    std::cout << std::left << std::setw(4) << std::setfill(' ')
    << "#id";
    std::cout << std::left << std::setw(20) << std::setfill(' ')
    << "Account Name";
    std::cout << std::left << std::setw(25) << std::setfill(' ')
    << "Account User Name";
    std::cout << std::left << std::setw(50) << std::setfill(' ')
    << "Password";
    std::cout << std::left << std::setw(50) << std::setfill(' ')
    << "URL"
    << "\n";
    
    for (int i = 0; i < m_Accounts.size(); i++)
    {
        std::cout << std::left << std::setw(4) << std::setfill(' ')
        << i;
        std::cout << std::left << std::setw(20) << std::setfill(' ')
        << (*m_Accounts[i]).GetAccountName();
        std::cout << std::left << std::setw(25) << std::setfill(' ')
        << (*m_Accounts[i]).GetAccountuserName();
        std::cout << std::left << std::setw(50) << std::setfill(' ')
        << (*m_Accounts[i]).GetAccountPassword();
        std::cout << std::left << std::setw(50) << std::setfill(' ')
        << (*m_Accounts[i]).GetAccountUrl()
        << "\n";
    }
}

void Database::AddAccount(Account* acc_ptr)
{
    m_Accounts.push_back(acc_ptr);
}

void Database::DeleteAccount(const int& acc_index)
{
    delete m_Accounts[acc_index];
    m_Accounts.erase(m_Accounts.begin()+acc_index);
}

void Database::SaveDatabase()
{
    std::ofstream file(m_FileName, std::ios::out);
    if (file.is_open())
    {
        for (auto const& account : m_Accounts)
        {
            file << (*account).GetAccountName();
            file << ",";
            file << (*account).GetAccountuserName();
            file << ",";
            file << (*account).GetAccountPassword();
            file << ",";
            file << (*account).GetAccountUrl();
            file << "\n";
        }
        file.close();
        std::cout << "Database has been saved." << std::endl;
    }
    else
    {
        std::cerr << "Failed to open file: " << m_FileName << std::endl;
    }
}
