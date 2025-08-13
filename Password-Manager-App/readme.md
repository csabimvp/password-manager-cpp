# Password Manager App


## To Do's:
Code the below.

### Account:
class members:
- Title,
-- generate LowerCaseTitle for sorting
- Username,
- Password pointer for Password class
- URL,
- Created Time,
- Email,
- Notes

### Passwords:
- EncryptedPassword,
- DecryptedPassword,
- Length,
- SpecialCharacters

### Database:
- FilePath,
- RawData -- we should not need this, increase memory performance
- Accounts

- Reading and Exporting files to match specific formats, CSV, Tabular, json?

## User Interface:
### Main menu:
        SHOW_ACCOUNTS       = 1,
        ADD_ACCOUNT,        // 2
        EDIT_ACCOUNT,       // 3
        DELETE_ACCOUNT,     // 4
        GENERATE_PASSWORD,  // 5
        SAVE_DATABASE,      // 6
        EXIT                // 7
        
We don't need to show all Account class members for #1 SHOW_ACCOUNTS, however would we need a menu item to show everything for one specific account?

### Sub Menus
**ADD_ACCOUNT** and ** EDIT_ACCOUNT** could be the same code, as the functionality is similar. We just need to Select an account for the edit version.
- Title,
- Username,
- Password,
- URL,
- Created Time,
- Email,
- Notes

**DELETE_ACCOUNT**
- Select an account to DELETE

**SAVE_DATABASE**
- Format specific sub_menu?


## Key Learning
Scope the project before writing any code. It's nightmare to refactor C++ code in a clean and tidy way.
