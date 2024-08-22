#include <iostream>
#include "Lecturer.h"
using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;

    Lecturer l1;
    Lecturer l2("Michael", "Innovation", 21, 21, 21, 124);

    cout<<l1.getName()<<endl;
    cout<<l2.getName()<<endl;

    l1.addClass(64);
    cout<<l1.getClass(1)<<endl;

    vector<Lecturer> lecs;
    string fileName = "../CS_Lecturers.csv"; // can't call this because don't have the file in folder currently

    getLecturersFromFile(fileName, &lecs);



    return 0;
}
