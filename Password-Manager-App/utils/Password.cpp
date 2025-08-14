//
//  Password.cpp
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#include "Password.h"
#include <iostream>
#include <random>


// m_Password -> m_EncryptedPassword
void Password::EncryptPassword()
{
    const std::string specialCharacterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@£$%&*-_+=";
    unsigned seed = (int)std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(specialCharacterList.length()) - 1);
    
    for (auto c : m_Password)
    {
        for (auto i = 0; i <= 8; i += 2)
        {
            if (i == 4)
            {
                m_EncryptedPassword += c;
            }
            else
            {
                m_EncryptedPassword += specialCharacterList[distribution(generator)];
            }
        }
    }
    
}


// m_EncryptedPassword -> m_Password
void Password::DecryptPassword()
{
    for (auto i = 2; i <= m_EncryptedPassword.length(); i += 5)
    {
        m_Password += m_EncryptedPassword[i];
    }
}


void Password::RandomPassword(const int& length, const bool& special_c)
{
    const std::string characterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const std::string specialCharacterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@£$%&*-_+=";
    std::string password;
    std::string encryptedPassword;
    
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = (int)std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    
    if (special_c)
    {
        std::uniform_int_distribution<int> distribution(0, static_cast<int>(specialCharacterList.length()) - 1);
        for (int i = 0; i < length; i ++)
        {
            char ch = specialCharacterList[distribution(generator)];
            password += ch;
        }
    }
    else
    {
        std::uniform_int_distribution<int> distribution(0, static_cast<int>(characterList.length()) - 1);
        for (int i = 0; i < length; i ++)
        {
            char ch = characterList[distribution(generator)];
            password += ch;
        }
    }
    
    m_Password = password;
    m_EncryptedPassword = encryptedPassword;
}


// User True = User enters Password for Existing Account vi the UI.
// User False = Loading from Database.
Password::Password(const bool user_input, const std::string&& password)
{
    if (user_input == false)
    {
        m_EncryptedPassword = password;
        DecryptPassword();
    }
    else
    {
        m_Password = password;
        EncryptPassword();
    }
}


Password::Password(const int& length, const bool& special_c)
{
    RandomPassword(length, special_c);
    EncryptPassword();
}


Password::~Password()
{
    std::cout << m_Password << " was deleted." << std::endl;
}


Password::Password(Password& other)
{
    std::cout << m_Password << " was copied." << std::endl;
}


std::string Password::GetPassword()
{
    return m_Password;
}


std::string Password::GetEncryptedPassword()
{
    return m_EncryptedPassword;
}
