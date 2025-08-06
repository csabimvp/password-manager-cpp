//
//  Account.h
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#ifndef UTILS_ACCOUNT_H
#define UTILS_ACCOUNT_H

#include <string>
#include <chrono>
#include <iostream>

class Account
{
private:
    std::string m_AccountName;
    std::string m_AccountUserName;
    std::string m_Password;
    std::string m_URL;
    std::chrono::system_clock::time_point m_Created;
public:
    Account(std::string name, std::string user_name, std::string pw, std::string url);
    ~Account();
    void PrintAccountDetails();
    
    std::string GetAccountName();
    std::string GetAccountuserName();
    std::string GetAccountPassword();
    std::string GetAccountUrl();
};

#endif
