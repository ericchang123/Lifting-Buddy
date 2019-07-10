#include <iostream>
#include <string>
#include <stdio.h>

std::string validatePass(){
    std::string pass;
    std::string confirmPass;
    char c;

    std::cout << "Enter a password. Must contain an uppercase, a digit,"
        "and a special character.\n";
    createPass:
        bool hasUpper = false, hasNumeric = false, hasSpecial = false;
        pass.clear();

        std::cin >> pass;
        for(auto c : pass){
            if(!isalnum(c)) hasSpecial = true;
            else if(isupper(c)) hasUpper = true;
            else if(isdigit(c)) hasNumeric = true;
        }

        if(!hasUpper || !hasNumeric || !hasSpecial){
            std::cout << "Password does not meet requirements. Please try again.\n";
            goto createPass;
        }

    //ask user to reenter password for validation
    check:
        std::cout << "Please re-enter password.\n";

        std::cin >> confirmPass;
        if(confirmPass != pass){
            std::cout << "Passwords do not match.\n";
            goto check;
        }
    return pass;
}
