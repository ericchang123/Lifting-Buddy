#include <iostream>
#include <limits>
#include <unordered_map>
#include <string>
#include <cctype>

#include "md5.h"
#include "password.cpp"
#include "user.cpp"
#include "squat.cpp"
#include "bench.cpp"
#include "deadlift.cpp"

#define M_P "MAIN_PROMPT"
#define P_1 "PROMPT_1"
#define P_2 "PROMPT_2"

int intInput(std::string statement){
    int res;
    std::cout << statement << std::endl;
    while(true){
        std::cin >> res;
        std::cout << "test1\n";
        if(std::cin.fail()){
            std::cout << "test2\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input requires an integer. Try again.\n";
            continue;
        }
        break;
    }
    return res;
}

void print(std::string type){



    if(type == "MAIN_PROMPT"){
        std::cout << "\nEnter '1' to sign up\n"
                     "Enter '2' to sign back in\n"
                     "Enter 'Quit' to quit\n\n";
        return;
    }



    if(type == "PROMPT_1"){
        std::cout << "Enter '1' to get first name\n"
                     "Enter '2' to modify first name\n"
                     "Enter '3' to get last name\n"
                     "Enter '4' to modify last name\n"
                     "Enter 'Quit' to quit\n\n";
        return;
    }



    if(type == "PROMPT_2"){
        std::cout << "Enter '1' to get weight\n"
                     "Enter '2' to modify weight\n"
                     "Enter '3' to get height\n"
                     "Enter '4' to modify height\n"
                     "Enter '5' to get BMI\n"
                     "Enter '6' to check health\n"
                     "Enter 'Quit' to quit\n\n";
        return;
    }



}

int main(){
    std::unordered_map<std::string, user> users;
    std::unordered_map<std::string, std::string> hash;

    std::string s;
    print(M_P);
    while(std::cin >> s){

        if(s == "1"){

            std::string userName, fName, lName;
            double weight;
            int height;
            std::cout << "\nEnter a unique username\n";

            while(std::cin >> userName){

                if(users.find(userName) == users.end()){
                    std::cout << "Username available!\n";

                    std::string passHash = md5(validatePass());
                    std::cout << passHash << std::endl;
                    hash.insert(std::make_pair(userName, passHash));

                    std::cout << "Enter first and last name separated by a space\n";
                    std::cin >> fName >> lName;
                    height = intInput("Enter height (inches, Integer)");
                    weight = 180;
                    /*
                    std::cout << "Enter weight (lbs, Decimal) and height (inches, Integer) separated by a space\n";
                    std::cin >> weight >> height;
                    */
                    users.insert(std::make_pair(userName, user(fName, lName, weight, height)));
                    break;
                }
                else{
                    std::cout << userName << " not available. Please try again.\n";
                }
            }
        }


/*
        else if(s == "2"){
            if(users.empty()){
                std::cout << "No users exist. Exiting.\n";
                break;
            }

            std::cout << "Enter a username\n";
            std::string userName;
            std::cin >> userName;
            if(users.find(userName) != users.end()){
                print("ACCESS/MODIFY_PROMPT");
                while(std::cin >> s){
                    std::string str;
                    double d;
                    int i;

                    if(s == "1"){
                        std::cout << "First Name: " << users.at(userName).getFirstName() << std::endl;
                     }
                    else if(s == "2"){
                        std::cout << "Enter a new first name\n";
                        std::cin >> str;
                        users.at(userName).setFirstName(str);
                    }
                    else if(s == "3"){
                        std::cout << "Last Name: " << users.at(userName).getLastName() << std::endl;
                    }
                    else if(s == "4"){
                        std::cout << "Enter a new last name\n";
                        std::cin >> str;
                        users.at(userName).setLastName(str);
                    }
                    else if(s == "5"){
                        std::cout << "Weight: " << users.at(userName).getWeight() << std::endl;
                    }
                    else if(s == "6"){
                        std::cout << "Enter a new weight\n";
                        std::cin >> d;
                        users.at(userName).setWeight(d);
                    }
                    else if(s == "7"){
                        std::cout << "Height: " << users.at(userName).getHeight() << std::endl;
                    }
                    else if(s == "8"){
                        std::cout << "Enter a new height\n";
                        std::cin >> i;
                        users.at(userName).setHeight(i);
                    }
                    else if(s == "9"){
                        std::cout << "BMI: " << users.at(userName).getBMI() << std::endl;
                    }
                    else if(s == "0"){
                        if(users.at(userName).getHealth()){
                            std::cout << "Healthy\n";
                        }
                        else{
                            std::cout << "Not healthy\n";
                        }
                    }
                    print("ACCESS/MODIFY_PROMPT");
                }
            }
            else{
                std::cout << "Username not found. Exiting\n";
                break;
            }
            break;
        }
*/


        else if(s == "Quit"){ return 0; }

        else{ std::cout << "Invalid input. Please try again\n"; }

        print(M_P);
    }
    return 0;
}
