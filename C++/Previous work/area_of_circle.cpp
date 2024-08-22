#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double radius, area;

    cout<<"Please enter the radius: "<<endl;

    cin>>radius;

    area = M_PI * (radius*radius);

    cout<<"A circle with radius "<<radius<<" has an area of "<<area<<endl;

    return 0;


}