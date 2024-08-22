#include <iostream>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
void printYearCalendar(int year, int startingDay);

int main()
{
    int userYear;
    int userStartDate;
    int userDaysInMonth;
    int userMonthStart;

    cout<<"Enter the number of days in the month and a number from 1-7 for the day of the week";
    cout<<" the month will start on, separated by a space"<<endl;
    cin>>userDaysInMonth>>userMonthStart;

    printMonthCalendar(userDaysInMonth, userMonthStart);

    cout<<"Enter the year and the day of the week the year starts on (as a number from 1-7)";
    cout<<" separated by a space:"<<endl;
    cin>>userYear>>userStartDate;

    printYearCalendar(userYear, userStartDate);
    

    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay)
{
    int count = 1;
    int finalDay;
    
    if(startingDay == 0)
        startingDay = 7;

    cout<<"Mon\tTue\tWed\tThr\tFri\tSat\tSun"<<endl;
    
    //spaces for before starting day
    for(int m = 1; m<startingDay; m++)
    {
        cout<<" \t";
        if(count % 7 == 0){
            cout<<endl;
        }
        count++;
        
    }
    
    for(int x = 1; x <= numOfDays; x++)
    {
        cout<<x<<"\t";
        if(count % 7 == 0){
            cout<<endl;
        }
        count++;
    }
    cout<<endl<<endl;

    //final day will be count % 7.  
    finalDay = (count-1) % 7;
    
    if(finalDay == 0)
        finalDay = 7;

    return finalDay;
}

void printYearCalendar(int year, int startingDay)
{
    int calYear = year;
    int startDay = startingDay;
    int nextStartDay;
    int numDays;
    int displayMonth;
    bool leapYear = false;

    //leap year logic.  x = year.  ((x % 4 == 0 && !(x % 100 == 0)) || x % 400 == 0) --> x is a leap year
        //calculate leap year y or n
    if((calYear % 4 == 0 && !(calYear % 100 == 0))|| calYear % 400 == 0)
        leapYear = true;
    
    //for loop 1-12 for months
    //"30 days have september, april, june, and november"
    for(int x = 1; x<=12; x++){
        if(x == 1){
            cout<<"January "<<calYear<<endl;
            numDays = 31;
            displayMonth = printMonthCalendar(numDays, startDay);
        }
        else if(x==2){
            cout<<"February "<<calYear<<endl;
            if(leapYear == true){
                numDays = 29;
            }
            else
                numDays = 28;
            
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==3){
            cout<<"March "<<calYear<<endl;
            numDays = 31;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==4){
            cout<<"April "<<calYear<<endl;
            numDays = 30;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==5){
            cout<<"May "<<calYear<<endl;
            numDays = 31;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==6){
            cout<<"June "<<calYear<<endl;
            numDays = 30;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==7){
            cout<<"July "<<calYear<<endl;
            numDays = 31;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==8){
            cout<<"August "<<calYear<<endl;
            numDays = 31;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==9){
            cout<<"September "<<calYear<<endl;
            numDays = 30;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==10){
            cout<<"October "<<calYear<<endl;
            numDays = 31;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==11){
            cout<<"November "<<calYear<<endl;
            numDays = 30;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }
        else if(x==12){
            cout<<"December "<<calYear<<endl;
            numDays = 31;
            nextStartDay = (displayMonth + 1)%7;
            displayMonth = printMonthCalendar(numDays, nextStartDay);
        }

    }

    


}

