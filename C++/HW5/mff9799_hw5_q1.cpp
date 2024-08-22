#include <iostream>
#include <cmath>
using namespace std;

int fib(int n);

int main()
{
    int num;
    int fibonacci;

    cout<<"Please enter an integer: "<<endl;
    cin>>num;

    fibonacci = fib(num);
    cout<<fibonacci;
    

    return 0;
}


int fib(int n)
{
    double phi = (sqrt(5)+1)/2.0;
    double inversePhi = 1/phi;

    int num = (pow(phi, n)-(pow(-inversePhi,n)))/sqrt(5);

    return num;

}

