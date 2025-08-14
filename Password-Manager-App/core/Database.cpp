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
    // Creating a vector for each row, and reserving 10 items to increase performance.
    // This 10 is to capture all class member data.
    std::vector<std::string> rowData;
    rowData.reserve(10);
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

void Database::LoadDatabase()
{
    std::vector<std::string> data;
//    data.reserve(10);
    std::ifstream file(m_FilePath);
    
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << m_FilePath << std::endl;
    }
    
    std::string line;
    while (std::getline(file, line))
    {
        // Read Line
        data = ParseLine(std::move(line));
        
        // Create Account object from row
        Password* pw = new Password(false, std::move(data[6]));
        Account* acc = new Account(
                                   std::move(data[0]),
                                   std::move(data[1]),
                                   std::move(data[2]),
                                   std::move(data[3]),
                                   std::move(data[4]),
                                   std::move(data[5]),
                                   pw
                                   );
        m_Accounts.push_back(acc);
    }
    
    file.close();
}

static bool SortAccounts(Account* acc1, Account* acc2)
{
    return (*acc1).GetAccountLowerCaseTitle() < (*acc2).GetAccountLowerCaseTitle();
}

Database::Database(const std::string& file_path)
:m_FilePath(file_path)
{
    LoadDatabase();
    std::cout << "Database loaded from: " << file_path << std::endl;
    std::sort(m_Accounts.begin(), m_Accounts.end(), SortAccounts);
    std::cout << "#" << m_Accounts.size() << " Accounts loaded." << std::endl;
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
        << (*m_Accounts[i]).GetAccountTitle();
        std::cout << std::left << std::setw(25) << std::setfill(' ')
        << (*m_Accounts[i]).GetAccountUserName();
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
    std::ofstream file(m_FilePath, std::ios::out);
    if (file.is_open())
    {
        for (auto const& account : m_Accounts)
        {
            file << (*account).GetAccountTitle();
            file << ",";
            file << (*account).GetAccountUserName();
            file << ",";
            file << (*account).GetAccountEmail();
            file << ",";
            file << (*account).GetAccountUrl();
            file << ",";
            file << (*account).GetAccountNotes();
            file << ",";
            file << (*account).GetAccountCreatedTime();
            file << ",";
            file << (*account).GetAccountEncryptedPassword();
            file << "\n";
        }
        file.close();
        std::cout << "Database has been saved." << std::endl;
    }
    else
    {
        std::cerr << "Failed to open file: " << m_FilePath << std::endl;
    }
}
