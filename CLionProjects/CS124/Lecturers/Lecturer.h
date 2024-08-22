//
// Created by Michael Farmer on 9/2/22.
//

#ifndef LECTURERS_LECTURER_H
#define LECTURERS_LECTURER_H
using namespace std;
#include <vector>
#include <fstream>

class Lecturer{
    //Set private fields
private:
    string name;
    string office;
    vector<int> classNums;

    //create public methods
public:
    Lecturer(){
        name = "New Instructor";
        office = "Not yet assigned";
    }

    Lecturer(string n, string o, int c1, int c2, int c3, int c4){
        name = n;
        office = o;
        classNums.push_back(c1); //adds to the end of the vector
        classNums.push_back(c2);
        classNums.push_back(c3);
        classNums.push_back(c4);
    }

    void addClass(int c){
        classNums.push_back(c);
    }

    int getClass(int index) const{
        int class1 = 0;
        if(classNums.size() >= index){
            class1 = classNums[index - 1];
        }

        return class1;
    }

    bool changeClass(int index, int newClass){
        bool worked = false;
        if(classnums.size() >= index){
            classnums[index - 1] = newClass;
            worked = true;
        }
        return worked;
    }

    string getName(){
        return name;
    }

    void setName(string n){
        name = n;
    }

    string getOffice() const{
        return office;
    }

    void setOffice(string o){
        office = o;
    }

};

//global function.  Exists outside of lecturer class.  In c++ you can do this
void getLecturersFromFile(string fileName, vector<Lecturer> &lecs){
    ifstream f_in;
    f_in.open(fileName);

    string line;
    string name;
    char comma;
    int class1, class2, class3, class4 = 0;

    if(!f_in){
        cout<<"Could not find file"<<endl;
    }
    else{
        while(f_in){
            //reading in name
            getline(f_in, name, ',');
            //getting rid of comma after name
            f_in >> comma;
            f_in >> class1;
            f_in >> comma;
            f_in >> class2;
            f_in >> comma;
            f_in >> class3;
            f_in >> comma;
            f_in >> class4;
            f_in >> comma;


        }
    }


}

#endif //LECTURERS_LECTURER_H
