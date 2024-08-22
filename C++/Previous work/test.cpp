#include <iostream>
using namespace std;

int main()
{
    char a = 'a';
    int num;

    cout<<"Please enter a number"<<endl;
    cin>>num;

    for(int i = 1; i<=num; i++){
        for(int j = 1; j<=2*num-1; j++)
        {
            if((i+j)==(num+1) || (i+j)==(num+i+(i-1)))
                cout<<(char)(a+(i-1));
                
            else
                cout<<" ";
        }
       cout<<endl;

    }

    for(int i = 2; i<=num; i++){
        for(int j = 1; j<=2*num-1; j++)
        {
            if(i==j || i+j == 2*num)
                cout<<(char)(a+(num-i));
                
            else
                cout<<" ";
        }
       cout<<endl;

    }
    

    return 0;




}