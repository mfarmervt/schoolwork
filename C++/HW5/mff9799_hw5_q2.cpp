#include <iostream>
#include <cmath>
using namespace std;


void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main()
{
    char y;
    int pineTreeSize;
    

    cout<<"Please enter the size of your printed pine tree and the character you would like to use: "<<endl;
    cin>>pineTreeSize>>y;
    cout<<endl;

    printPineTree(pineTreeSize, y);


    return 0;

}

void printShiftedTriangle(int n, int m, char symbol)
{
    int outerSpaces = (m+n)-1;
    int numChar = 1;
    char space = ' ';
    char x = symbol;

    for(int p = 1; p <= n; p++){
        //for loop to print outer spaces, shifted by m.
        for(int x = 0; x<outerSpaces; x++){
            cout<<space;
         }

        //for loop to print char.  1-->n times
        for(int y = 1; y<=numChar; y++){
            cout<<x;
            
        }
        //line break
        cout<<endl;
        numChar+=2;
        outerSpaces --;

    }
}

void printPineTree(int n, char symbol)
{
    int triangleSize = 2;
    int spaces = n-1;
    for(int x = 1; x <= n; x++){
        printShiftedTriangle(triangleSize, spaces, symbol);
        triangleSize++;
        spaces--;


    }
    
}