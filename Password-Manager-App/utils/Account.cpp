//
//  Account.cpp
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#include "Account.h"


Account::Account(std::string&& name, std::string&& user_name, std::string&& pw, std::string&& url)
: m_AccountName(name), m_AccountUserName(user_name), m_Password(pw), m_URL(url)
{
    m_Created = std::chrono::system_clock::now();
}

Account::Account(Account& other)
{
    std::cout << m_AccountName << " was copied." << std::endl;
}

Account::~Account()
{
    std::cout << m_AccountName << " was deleted." << std::endl;
}

void Account::PrintAccountDetails()
{
    std::cout
    << m_AccountName
    << ", "
    << m_AccountUserName
    << ", "
    << m_Password
    << ", "
    << m_URL
    << ", "
    << m_Created
    << std::endl;
}

std::string Account::GetAccountName() { return m_AccountName; }
std::string Account::GetAccountuserName() { return m_AccountUserName; }
std::string Account::GetAccountPassword() { return m_Password; }
std::string Account::GetAccountUrl() { return m_URL; }
