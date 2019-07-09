#include <iostream>
#include <string>

class user {
public:
    user(std::string fN, std::string lN, double w, int h){
        firstName = fN;
        lastName = lN;
        weight = w;
        height = h;

        // calculate BMI
        bmi = (weight * 703) / (height * height);
        healthy = (bmi >= 18.5 && bmi < 25);
    }

    std::string getFirstName(){ return firstName; }

    void setFirstName(std::string newFirst){ firstName = newFirst; }

    std::string getLastName(){ return lastName; }

    void setLastName(std::string newLast){ lastName = newLast; }

    double getWeight(){ return weight; }

    void setWeight(double newWeight){ weight = newWeight; }

    double getHeight(){ return height; }

    void setHeight(double newHeight){ height = newHeight; }

    double getBMI(){ return bmi; }

    bool getHealth(){ return healthy; }

private:
    std::string firstName;
    std::string lastName;
    double weight;
    int height;
    double bmi;
    bool healthy;
};
