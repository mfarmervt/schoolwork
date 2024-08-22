/*This program will ask for user input for number of days traveled and
    print a line indicating the amount of time they traveled in the format
    of weeks and days. */

#include <iostream>
using namespace std;

const int DAYS_IN_A_WEEK = 7;  //constants can be declared outside of main

int main()
{
    int inputDays;
    int weeks;
    int days;


    cout<<"Please enter number of days traveled"<<endl;

    cin>>inputDays;

    weeks = inputDays/DAYS_IN_A_WEEK;
    days = inputDays % DAYS_IN_A_WEEK;
    cout<<"You traveled for "<<weeks<<" weeks and "<<days<<" days."<<endl;

    return 0;
    


}