#include <iostream>
#include <string>
using namespace std;

int main()
{
    //declare variables
    int userNum, i, j;

    //get user input for number positive integer.
    cout<<"Please input a positive integer: "<<endl;
    cin>>userNum;

    for (int i = 1; i <= userNum; i++) {
        for (j= 1; j <= 2 * userNum -1; j++)
            //(i,j) like coordinates or rows/columns in a matrix.   
            if((i-j>0)||(i + j >=2 * userNum + 1))
            {
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        cout<<endl;
    }

    for (int i = 1; i <= userNum; i++) {
        for (j= 1; j <= 2 * userNum -1; j++)
            if(((i+j<= userNum))||(j-i>=userNum))
            {
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        cout<<endl;
    }
    
    return 0;

}
