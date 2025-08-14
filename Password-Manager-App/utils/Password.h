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
    std::string m_Password;
    std::string m_EncryptedPassword;
public:
    // Default - This should not be used.
    Password();
    
    // User Generates a Password via the UI.
    Password(const int& length, const bool& special_c);
    
    // User True = Enters Password for Existing Account vi the UI.
    // User False = Loading from Database.
    Password(const bool user_input, const std::string&& password);
    
    // Copy Constructor
    Password(Password& other);
    
    // Delete Constructor
    ~Password();
    
    // Getter functions.
    std::string GetPassword();
    std::string GetEncryptedPassword();
    void RandomPassword(const int& length, const bool& special_c);
    
    // m_Password -> m_EncryptedPassword
    void EncryptPassword();
    
    // m_EncryptedPassword -> m_Password
    void DecryptPassword();
};

#endif
