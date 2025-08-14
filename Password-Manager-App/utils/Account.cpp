//
//  Account.cpp
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#include "Account.h"

Account::Account(
                 // User / Database Inputs
                 const std::string&& title,
                 const std::string&& user_name,
                 const std::string&& email,
                 const std::string&& url,
                 const std::string&& notes,
                 const std::string&& created_time,
                 // Password Pointer
                 Password* pw
                 )
: m_Title(title), m_UserName(user_name), m_PasswordPointer(pw), m_URL(url), m_Email(email), m_Notes(notes)
{
    // Creating lower case Title for sorting purposes.
    m_LowerCaseTitle.resize(m_Title.length());
    std::transform(m_Title.begin(), m_Title.end(), m_LowerCaseTitle.begin(), [](unsigned char c) { return std::tolower(c); });
    m_CreatedTime = created_time;
}

Account::Account(Account& other)
{
    std::cout << m_Title << " was copied." << std::endl;
}

Account::~Account()
{
    delete m_PasswordPointer;
    std::cout << m_Title << " was deleted." << std::endl;
}

void Account::PrintAccountDetails()
{
    std::cout
    << m_Title
    << ", "
    << m_UserName
    << ", "
//    << m_Password
    
    << ", "
    << m_URL
    << ", "
    << m_CreatedTime
    << std::endl;
}

std::string Account::GetAccountTitle() { return m_Title; }
std::string Account::GetAccountLowerCaseTitle() { return m_LowerCaseTitle; }
std::string Account::GetAccountUserName() { return m_UserName; }
std::string Account::GetAccountEmail() { return m_Email; }
std::string Account::GetAccountUrl() { return m_URL; }
std::string Account::GetAccountNotes()
{
    if (m_Notes.empty())
    {
        return "None";
    }
    else
    {
        return m_Notes;
    }
}
std::string Account::GetAccountCreatedTime() { return m_CreatedTime; }
std::string Account::GetAccountPassword() { return (*m_PasswordPointer).GetPassword(); }
std::string Account::GetAccountEncryptedPassword() { return (*m_PasswordPointer).GetEncryptedPassword(); }
