#include <iostream>

#include "HeartRates.h"

using namespace std;

int main() {
    HeartRates heartrates;

    cout << "First Name        : " << heartrates.getFirstName() << "\n";
    cout << "Last Name         : " << heartrates.getLastName() << "\n";
    cout << "Date of Birth     : " << heartrates.dateOfBirthDay << "/" << heartrates.dateOfBirthMonth <<
        "/" << heartrates.dateOfBirthYear << "\n";

    cout << "Age               : " << heartrates.age << "\n";
    cout << "Maximum Heart Rate: " << heartrates.getMaximumHeartRate() << "\n";
    cout << "Target Heart Rate : " << heartrates.getTargetHeartRate_lowerbound() << "-" << heartrates.getTargetHeartRate_upperbound() << "\n";


    return 0;

}
