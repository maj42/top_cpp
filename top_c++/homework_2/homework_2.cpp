#include <iostream>
#include <iomanip>

using namespace std;

void task1Seconds();
void task2Dollars();
void task3Days();
void task4Speed();
void task5Deposit();

void main()
{
    int choice;
    cout << "Please enter your choice:\n\
        1. Calculate hours and minutes from seconds.\n\
        2. Calculate the amount of dollars and cents from a floating point decimal.\n\
        3. Calculate weeks and days from days.\n\
        4. Calculate speed from distance and time.\n\
        5. Calculats bank's monthly payment for a deposit.\n\n";
    cin >> choice;

    switch (choice) {
    case 1:
        task1Seconds();
        break;
    case 2:
        task2Dollars();
        break;
    case 3:
        task3Days();
        break;
    case 4:
        task4Speed();
        break;
    case 5:
        task5Deposit();
        break;
    default:
        cout << "Unknown option.";
    }
}

void task1Seconds() {
    int input_seconds, hours, minutes, seconds;
    cout << "Enter the amount of seconds: " << endl;
    cin >> input_seconds;
    hours = input_seconds / 3600;
    minutes = (input_seconds - hours * 3600) / 60;
    seconds = ((input_seconds - hours * 3600) - minutes * 60) % 60;
    cout << input_seconds << " second(s) is " << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s)" << endl;
}

void task2Dollars() {
    float input_dollars;
    int dollars, cents;
    cout << "Enter the sum in dollars with a floating point: " << endl;
    cin >> input_dollars;
    dollars = int(input_dollars);
    cents = (int)(input_dollars * 100) % 100;
    cout << input_dollars << " dollar(s) is " << dollars << " dollar(s) and " << cents << " cent(s)" << endl;
}

void task3Days() {
    int input_days, weeks, days;
    cout << "Enter the amount of days: " << endl;
    cin >> input_days;
    weeks = input_days / 7;
    days = input_days % 7;
    cout << input_days << " day(s) is " << weeks << " week(s) and " << days << " day(s)" << endl;
}

void task4Speed() {
    int minutes, seconds;
    float input_distance, input_time, speed, hours;
    cout << "Enter the distance in meters: " << endl;
    cin >> input_distance;
    cout << "Enter time (min.sec): " << endl;
    cin >> input_time;
    minutes = (int)input_time;
    seconds = (int)(input_time * 100) % 100;
    hours = (float)minutes / 60 + (float)seconds / 3600;
    speed = (input_distance / 1000.0) / hours;
    cout << setprecision(2) << "Distance: " << input_distance / 1000.0 << " km\nTime: " << minutes << " min " << seconds << "sec = " 
        << minutes * 60 + seconds << " seconds\nSpeed: " << speed << " km/h" << endl;
}

void task5Deposit() {
    int deposit, rate;
    float yearly_payment;
    cout << "Enter the amount on your deposit (without decimals): ";
    cin >> deposit;
    cout << "Enter the bank rate (without decimals): ";
    cin >> rate;
    yearly_payment = (float)deposit * (float)rate / 100;
    cout << setprecision(2) << "Monthly bank's payment on the deposit " << deposit << " with rate " << rate << "% is " << yearly_payment / 12;
}