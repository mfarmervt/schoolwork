#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    /******************************* Part 1 *******************************/

    cout<<"Section A"<<endl;

    //declare variables
    double seqLen;
    double input;
    double product = 1.0;

    //set precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    //user input for length of sequence
    cout<<"Please enter the length of the sequence: ";
    cin>>seqLen;

    //for loop to get user input for sequence
        //product *= pow(input, 1/length)
    cout<<"Please enter your sequence: "<<endl;
    for(int x = 0; x<seqLen; x++)
    {
        cin>>input;
        product *= (pow(input,(1/seqLen)));
        
    }

   // geoMean = pow((double)product, (1/seqLen));

    cout<<"The geometric mean is: "<<product<<endl;


    /******************************* PART 2 ******************************************/

    cout<<"Section B"<<endl;
   
    //declare variables
    double input2;
    int counter = 0;
    double geoMean;
    double product2 = 1.0;
    bool flag = false;

    //set precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    //for loop to get user input for sequence
        //product *= pow(input, 1/length)
    cout<<"Please enter a non-empty sequence of positive integers, each on a separate line.  End your sequence by typing -1: "<<endl;
    while(flag == false)
    {
        cin>>input2;
        
        if(input2 == -1)
            flag = true;
        else if(input2 < -1 || input2 == 0)
            cout<<"Please enter a positive integer."<<endl;
        else
        {
            flag = false;
            product2 *= input2;
            counter++;      
        } 
         
       
    }

    //geoMean = pow((double)product, (1/seqLen));
    if(counter != 0){
        geoMean = pow(product2,(1.0/counter));
        cout<<"The geometric mean is: "<<geoMean<<endl;
    }
    else{
        cout<<"Empty sequence";
    }
    




}