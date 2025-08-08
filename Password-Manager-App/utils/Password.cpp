//
//  Password.cpp
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#include "Password.h"
#include <iostream>
#include <random>

static std::string Encrypt(const char& diff, const char& c)
{
    const std::string specialCharacterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@£$%&*-_+=";
    std::string interim;
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(specialCharacterList.size()) - 1);
    
    for (char i = 0; i <= diff; i += 2)
    {
        if (i == 4)
        {
            interim += c;
        }
        else
        {
            interim += specialCharacterList[distribution(generator)];
        }
    }
    return interim;
}

void Password::RandomPassword()
{
    const std::string characterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const std::string specialCharacterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@£$%&*-_+=";
    std::string password;
    std::string encryptedPassword;
    
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    
    if (m_SpecialCharacter)
    {
        std::uniform_int_distribution<int> distribution(0, static_cast<int>(specialCharacterList.size()) - 1);
        for (int i = 0; i < m_Length; i ++)
        {
            char ch = specialCharacterList[distribution(generator)];
            password += ch;
            encryptedPassword += Encrypt(8, ch);
        }
    }
    else
    {
        std::uniform_int_distribution<int> distribution(0, static_cast<int>(characterList.size()) - 1);
        for (int i = 0; i < m_Length; i ++)
        {
            char ch = characterList[distribution(generator)];
            password += ch;
            encryptedPassword += Encrypt(8, ch);
        }
    }
    
    m_Password = password;
    m_EncryptedPassword = encryptedPassword;
}

std::string Password::GetPassword()
{
    return m_Password;
}

std::string Password::GetEncryptedPassword()
{
    std::cout << m_EncryptedPassword << std::endl;
    return m_EncryptedPassword;
}

Password::Password()
: m_Length(30), m_SpecialCharacter(false)
{
    RandomPassword();
}

Password::Password(int length, bool special_c)
: m_Length(length), m_SpecialCharacter(special_c)
{
    RandomPassword();
}

Password::~Password()
{
    std::cout << m_Password << " was deleted." << std::endl;
}

std::string Password::EncryptPassword()
{
    // size 62
    const std::string characterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    std::cout << characterList.size() << std::endl;
    
    return "hello";
}

std::string Password::DecryptPassword(const std::string&& encrypted_password)
{
    std::string decrypted_password;
    for (char i = 2; i <= encrypted_password.size(); i += 5)
    {
        decrypted_password += encrypted_password[i];
    }
    return decrypted_password;
}
