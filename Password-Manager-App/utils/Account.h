//
//  Account.h
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#ifndef UTILS_ACCOUNT_H
#define UTILS_ACCOUNT_H

#include "Password.h"
#include <string>
#include <chrono>
#include <iostream>

class Account
{
private:
    std::string m_Title;
    std::string m_LowerCaseTitle;
    std::string m_UserName;
    std::string m_Email;
    std::string m_URL;
    std::string m_Notes;
//    std::chrono::system_clock::time_point m_CreatedTime;
    std::string m_CreatedTime;
    Password* m_PasswordPointer;
public:
    Account(
            const std::string&& title,
            const std::string&& user_name,
            const std::string&& email,
            const std::string&& url,
            const std::string&& notes,
            const std::string&& created_time,
            Password* pw
    );
    // Copy constructor
    Account(Account& other);
    ~Account();
    
    void PrintAccountDetails();
    std::string GetAccountTitle();
    std::string GetAccountLowerCaseTitle();
    std::string GetAccountUserName();
    std::string GetAccountPassword();
    std::string GetAccountEmail();
    std::string GetAccountUrl();
    std::string GetAccountNotes();
    std::string GetAccountCreatedTime();
    std::string GetAccountEncryptedPassword();
};

#endif
