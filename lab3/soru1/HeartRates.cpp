#include <iostream>
#include <string>
#include "HeartRates.h"

using namespace std;

HeartRates::HeartRates() {
    cout << "Please enter first and last name: ";
    cin >> firstName >> lastName;
    cout << "Please enter month, day, and year of birth: ";
    cin >> dateOfBirthMonth >> dateOfBirthDay >> dateOfBirthYear;

    age = getAge();
}


string HeartRates::getFirstName() {
    return firstName;
}

string HeartRates::getLastName() {
    return lastName;
}

int HeartRates::getMaximumHeartRate() {
    return 220 - age;
}

int HeartRates::getTargetHeartRate_lowerbound() {
    return getMaximumHeartRate() * 0.5;
}

int HeartRates::getTargetHeartRate_upperbound() {
    return getMaximumHeartRate() * 0.85;
}

void HeartRates::setFirstName(string s) {
    firstName = s;
}
void HeartRates::setLastName(string s) {
    lastName = s;
}
void HeartRates::setMaximumHeartRate(int r) {
    maxHR = r;
}
void HeartRates::setTargetHeartRate(int r) {
    targetHR = r;
}

int HeartRates::getAge() {
    int month, day, year;
    cout << "Please enter today's month, day, and year: ";
    cin >> month >> day >> year;

    if (month >= dateOfBirthMonth)
        return year - dateOfBirthYear;
    else
        return year - dateOfBirthYear - 1;
}

