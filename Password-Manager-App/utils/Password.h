//
//  Password.h
//  Password-Manager-App
//
//  Created by Csaba Keller on 06/08/2025.
//

#ifndef UTILS_PASSWORD_H
#define UTILS_PASSWORD_H

#include <string>

class Password
{
private:
    int m_Length;
    bool m_SpecialCharacter;
    std::string m_Password;
public:
    Password();
    Password(int length, bool special_c);
    ~Password();
    void RandomPassword();
    std::string GetPassword();
};

#endif
