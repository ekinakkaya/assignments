#include <iostream>
#include <string>

using namespace std;


class HeartRates {
    public:
        HeartRates();

        string firstName;
        string lastName;
        int dateOfBirthDay, dateOfBirthMonth, dateOfBirthYear;

        int age, maxHR, targetHR;


        int getAge();

        // get attribute functions
        string getFirstName();
        string getLastName();
        int    getMaximumHeartRate();
        int    getTargetHeartRate_lowerbound();
        int    getTargetHeartRate_upperbound();

        // set attribute functions
        void setFirstName(string s);
        void setLastName(string s);
        void setMaximumHeartRate(int r);
        void setTargetHeartRate(int r);
};

