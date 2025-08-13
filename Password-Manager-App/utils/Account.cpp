//
//  Account.cpp
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#include "Account.h"

//#include <algorithm>
//#include <cctype>
//#include <string>
//
// should try to do this with a lambda function.
//std::string data = "Abc";
//std::transform(data.begin(), data.end(), data.begin(),
//    [](unsigned char c){ return std::tolower(c); });

Account::Account(
                 std::string&& name,
                 std::string&& user_name,
                 std::string&& url,
                 Password* pw
                 )
: m_AccountName(name), m_AccountUserName(user_name), m_PasswordPtr(pw), m_URL(url)
{
    m_Created = std::chrono::system_clock::now();
}

Account::Account(Account& other)
{
    std::cout << m_AccountName << " was copied." << std::endl;
}

Account::~Account()
{
    delete m_PasswordPtr;
    std::cout << m_AccountName << " was deleted." << std::endl;
}

void Account::PrintAccountDetails()
{
    std::cout
    << m_AccountName
    << ", "
    << m_AccountUserName
    << ", "
//    << m_Password
    
    << ", "
    << m_URL
    << ", "
    << m_Created
    << std::endl;
}

std::string Account::GetAccountName() { return m_AccountName; }
std::string Account::GetAccountuserName() { return m_AccountUserName; }
//std::string Account::GetAccountPassword() { return m_Password; }
std::string Account::GetAccountPassword() { return (*m_PasswordPtr).GetPassword(); }
std::string Account::GetAccountUrl() { return m_URL; }
