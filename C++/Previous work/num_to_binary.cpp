#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numericValue;
    int modulus;
    string binary = "";

    cout<<"Please enter a numeric value: ";
    cin>>numericValue;

    while(numericValue != 0)
    {
        modulus = numericValue % 2;
        binary  += to_string(modulus);
        numericValue /= 2;
    }

    string temporary = "";
    for(int x = binary.length(); x >= 0; x--)
        temporary += binary[x];

        
    cout<<temporary;

    return 0;

}