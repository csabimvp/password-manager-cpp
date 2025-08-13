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
    std::string m_EncryptedPassword;
public:
    Password();
    Password(int length, bool special_c);
    Password(const std::string& encrypted_password);
    ~Password();
    void RandomPassword();
    std::string GetPassword();
    std::string GetEncryptedPassword();
    std::string EncryptPassword();
    // This function takes an rvalue reference
    // Useful for efficiently moving resources from temporary objects
    std::string DecryptPassword(const std::string& encrypted_password);
};

#endif
