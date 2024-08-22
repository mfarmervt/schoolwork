#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    int temp;
    string x = "";

    cout<<"Please enter a positive integer: ";
    cin>>num;

    //temporary copy of value of num for final output
    temp = num;

    while(num>=0)
    {
        if(num-1000>=0){
            x+="M";
            num-= 1000;}
        else if(num-500>=0){
            x+="D";
            num -= 500;
        }
        else if(num-100>=0){
            x+="C";
            num -= 100;
        }
        else if(num-50>=0){
            x+="L";
            num -= 50;
        }
        else if(num-10>=0){
            x+="X";
            num -= 10;
        }
        else if(num-5>=0){
            x+="V";
            num-= 5;
        }
        else if(num-1>=0){
            x+="I";
            num -=1;
        }
        else
            break;
    }

    cout<<temp<<" is "<<x;

    return 0;



}