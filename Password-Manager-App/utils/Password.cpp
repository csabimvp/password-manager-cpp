//
//  Password.cpp
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#include "Password.h"
#include <iostream>
#include <random>

void Password::RandomPassword()
{
    const std::string characterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const std::string specialCharacterList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@£$%&*-_+=";
    std::string password;
    
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(1, static_cast<int>(specialCharacterList.size()) - 1);
    
    if (m_SpecialCharacter)
    {
        std::uniform_int_distribution<int> distribution(1, static_cast<int>(specialCharacterList.size()) - 1);
        for (int i = 0; i < m_Length; i ++)
        {
            password += specialCharacterList[distribution(generator)];
        }
    }
    else
    {
        std::uniform_int_distribution<int> distribution(1, static_cast<int>(characterList.size()) - 1);
        for (int i = 0; i < m_Length; i ++)
        {
            password += characterList[distribution(generator)];
        }
    }
    
    m_Password = password;
}

std::string Password::GetPassword()
{
    return m_Password;
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
