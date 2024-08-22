#include <iostream>
#include <cmath>
using namespace std;


void printDivisors(int num);
int main()
{
    int userNum;

    cout<<"Please enter a number >=2: "<<endl;
    cin>>userNum;
    printDivisors(userNum);

}

void printDivisors(int num)
{
    for(int x = 1; x< sqrt(num); x++)
    {
        if(num % x == 0)
        {
            cout<<x<<" ";
        }
    }
    for(int y = sqrt(num); y>=1; y--)
    {
        if(num % y == 0)
        {
            cout<<num/y<<" ";
           
        }
    }
}