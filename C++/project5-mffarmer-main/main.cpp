#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "ATPMatches.h"
#include <string>
#include <iostream>
using namespace std;

// Global functions
string getWinName(ATPMatch match) {
    string winName = to_string(match.getRowId()) + match.getWinnerName();
    return winName;
}
string getLoseName(ATPMatch match) {
    string loserName = to_string(match.getRowId()) + match.getLoserName();
    return loserName;
}

int main() {

    int reads = 0;

    //Create vector of ATP matches
    vector<ATPMatch> matches;
    string fileName = "../atp_matches_2022.csv";

    //Verify that file was read successfully.
    if(loadFromFile(fileName, matches)){
        std::cout<<"File read successfully"<<std::endl;
    }
    else {
        std::cout << "File unable to be read";
    }

    //initialize table size
    int tableSize = matches.size()+ 100;

    //Create 10 SeparateChaining objects: 5 with getWinName, 5 with getLoseNames
    SeparateChaining<ATPMatch> sepChainingWin1(tableSize, getWinName);
    SeparateChaining<ATPMatch> sepChainingLose1(tableSize, getLoseName);

    SeparateChaining<ATPMatch> sepChainingWin2((tableSize+=500), getWinName);
    SeparateChaining<ATPMatch> sepChainingLose2(tableSize, getLoseName);

    SeparateChaining<ATPMatch> sepChainingWin3((tableSize+=1000), getWinName);
    SeparateChaining<ATPMatch> sepChainingLose3(tableSize, getLoseName);

    SeparateChaining<ATPMatch> sepChainingWin4((tableSize+=2000), getWinName);
    SeparateChaining<ATPMatch> sepChainingLose4(tableSize, getLoseName);

    SeparateChaining<ATPMatch> sepChainingWin5((tableSize+=2000), getWinName);
    SeparateChaining<ATPMatch> sepChainingLose5(tableSize, getLoseName);


    //Create 10 OpenAddressing objects: 5 for each getKey type

    //reset tableSize
    tableSize = matches.size()+100;


    ExponentialProbing<ATPMatch> exProbWin1(tableSize, getWinName);
    ExponentialProbing<ATPMatch> exProbLose1(tableSize, getLoseName);

    ExponentialProbing<ATPMatch> exProbWin2((tableSize += 500), getWinName);
    ExponentialProbing<ATPMatch> exProbLose2(tableSize, getLoseName);

    ExponentialProbing<ATPMatch> exProbWin3((tableSize += 1000), getWinName);
    ExponentialProbing<ATPMatch> exProbLose3(tableSize, getLoseName);

    ExponentialProbing<ATPMatch> exProbWin4((tableSize += 2200), getWinName);
    ExponentialProbing<ATPMatch> exProbLose4(tableSize, getLoseName);

    ExponentialProbing<ATPMatch> exProbWin5((tableSize += 2200), getWinName);
    ExponentialProbing<ATPMatch> exProbLose5(tableSize, getLoseName);

    //Initial table sizes for Exponential Probing
    cout<<exProbWin1.getTableSize()<<endl;
    cout<<exProbWin2.getTableSize()<<endl;
    cout<<exProbWin3.getTableSize()<<endl;
    cout<<exProbWin4.getTableSize()<<endl;
    cout<<exProbWin5.getTableSize()<<endl;




    // open/create files

    //Separate Chaining, getkey function 1
    ofstream outFileSepChainWin1;
    outFileSepChainWin1.open("../data/SepChainWin1.txt");

    ofstream outFileSepChainWin2;
    outFileSepChainWin2.open("../data/SepChainWin2.txt");

    ofstream outFileSepChainWin3;
    outFileSepChainWin3.open("../data/SepChainWin3.txt");

    ofstream outFileSepChainWin4;
    outFileSepChainWin4.open("../data/SepChainWin4.txt");

    ofstream outFileSepChainWin5;
    outFileSepChainWin5.open("../data/SepChainWin5.txt");

    //Separate Chaining, getkey function 2
    ofstream outFileSepChainLose1;
    outFileSepChainLose1.open("../data/SepChainLose1.txt");

    ofstream outFileSepChainLose2;
    outFileSepChainLose2.open("../data/SepChainLose2.txt");

    ofstream outFileSepChainLose3;
    outFileSepChainLose3.open("../data/SepChainLose3.txt");

    ofstream outFileSepChainLose4;
    outFileSepChainLose4.open("../data/SepChainLose4.txt");

    ofstream outFileSepChainLose5;
    outFileSepChainLose5.open("../data/SepChainLose5.txt");


    //Exponential probing, getkey function 1
    ofstream outFileExProbWin1;
    outFileExProbWin1.open("../data/ExProbWin1.txt");

    ofstream outFileExProbWin2;
    outFileExProbWin2.open("../data/ExProbWin2.txt");

    ofstream outFileExProbWin3;
    outFileExProbWin3.open("../data/ExProbWin3.txt");

    ofstream outFileExProbWin4;
    outFileExProbWin4.open("../data/ExProbWin4.txt");

    ofstream outFileExProbWin5;
    outFileExProbWin5.open("../data/ExProbWin5.txt");

    //Exponential probing, getkey function 2
    ofstream outFileExProbLose1;
    outFileExProbLose1.open("../data/ExProbLose1.txt");

    ofstream outFileExProbLose2;
    outFileExProbLose2.open("../data/ExProbLose2.txt");

    ofstream outFileExProbLose3;
    outFileExProbLose3.open("../data/ExProbLose3.txt");

    ofstream outFileExProbLose4;
    outFileExProbLose4.open("../data/ExProbLose4.txt");

    ofstream outFileExProbLose5;
    outFileExProbLose5.open("../data/ExProbLose5.txt");


    //Loop through the vector and add objects to every hash table
    for(int i = 0; i < matches.size(); i++){

        //Separate chaining insertions for global function 1
        sepChainingWin1.insert(matches[i], reads);
        outFileSepChainWin1 << reads << endl;

        sepChainingWin2.insert(matches[i], reads);
        outFileSepChainWin2 << reads << endl;

        sepChainingWin3.insert(matches[i], reads);
        outFileSepChainWin3 << reads << endl;

        sepChainingWin4.insert(matches[i], reads);
        outFileSepChainWin4 << reads << endl;

        sepChainingWin5.insert(matches[i], reads);
        outFileSepChainWin5 << reads << endl;

        //Separate chaining inserts for global function 2
        sepChainingLose1.insert(matches[i], reads);
        outFileSepChainLose1 << reads << endl;

        sepChainingLose2.insert(matches[i], reads);
        outFileSepChainLose2 << reads << endl;

        sepChainingLose3.insert(matches[i], reads);
        outFileSepChainLose3 << reads << endl;

        sepChainingLose4.insert(matches[i], reads);
        outFileSepChainLose4 << reads << endl;

        sepChainingLose5.insert(matches[i], reads);
        outFileSepChainLose5 << reads << endl;


        //Exponential probing inserts for global function 1
        exProbWin1.insert(matches[i], reads);
        outFileExProbWin1 << reads << endl;

        exProbWin2.insert(matches[i], reads);
        outFileExProbWin2 << reads << endl;

        exProbWin3.insert(matches[i], reads);
        outFileExProbWin3 << reads << endl;

        exProbWin4.insert(matches[i], reads);
        outFileExProbWin4 << reads << endl;

        exProbWin5.insert(matches[i], reads);
        outFileExProbWin5 << reads << endl;

//        //Exponential probing inserts for global function 2
        exProbLose1.insert(matches[i], reads);
        outFileExProbLose1 << reads << endl;

        exProbLose2.insert(matches[i], reads);
        outFileExProbLose2 << reads << endl;

        exProbLose3.insert(matches[i], reads);
        outFileExProbLose3 << reads << endl;

        exProbLose4.insert(matches[i], reads);
        outFileExProbLose4 << reads << endl;

        exProbLose5.insert(matches[i], reads);
        outFileExProbLose5 << reads << endl;

    }
    cout<<"Average reads for separate chaining using getkey function 1." <<endl;
    cout<< sepChainingWin1.calculateAverageReads("../data/SepChainWin1.txt", matches.size())<< endl;
    cout<< sepChainingWin2.calculateAverageReads("../data/SepChainWin2.txt", matches.size())<< endl;
    cout<< sepChainingWin3.calculateAverageReads("../data/SepChainWin3.txt", matches.size())<< endl;
    cout<< sepChainingWin4.calculateAverageReads("../data/SepChainWin4.txt", matches.size())<< endl;
    cout<< sepChainingWin5.calculateAverageReads("../data/SepChainWin5.txt", matches.size())<< endl;

    cout<<"Average reads for separate chaining using getkey function 2." <<endl;
    cout<< sepChainingLose1.calculateAverageReads("../data/SepChainLose1.txt", matches.size())<< endl;
    cout<< sepChainingLose2.calculateAverageReads("../data/SepChainLose2.txt", matches.size())<< endl;
    cout<< sepChainingLose3.calculateAverageReads("../data/SepChainLose3.txt", matches.size())<< endl;
    cout<< sepChainingLose4.calculateAverageReads("../data/SepChainLose4.txt", matches.size())<< endl;
    cout<< sepChainingLose5.calculateAverageReads("../data/SepChainLose5.txt", matches.size())<< endl;

    cout<<"Average reads for exponential probing using getkey function 1." <<endl;
    cout<< exProbWin1.calculateAverageReads("../data/exProbWin1.txt", matches.size())<< endl;
    cout<< exProbWin2.calculateAverageReads("../data/exProbWin2.txt", matches.size())<< endl;
    cout<< exProbWin3.calculateAverageReads("../data/exProbWin3.txt", matches.size())<< endl;
    cout<< exProbWin4.calculateAverageReads("../data/exProbWin4.txt", matches.size())<< endl;
    cout<< exProbWin5.calculateAverageReads("../data/exProbWin5.txt", matches.size())<< endl;

    cout<<"Average reads for exponential probing using getkey function 2." <<endl;
    cout<< exProbLose1.calculateAverageReads("../data/exProbLose1.txt", matches.size())<< endl;
    cout<< exProbLose2.calculateAverageReads("../data/exProbLose2.txt", matches.size())<< endl;
    cout<< exProbLose3.calculateAverageReads("../data/exProbLose3.txt", matches.size())<< endl;
    cout<< exProbLose4.calculateAverageReads("../data/exProbLose4.txt", matches.size())<< endl;
    cout<< exProbLose5.calculateAverageReads("../data/exProbLose5.txt", matches.size())<< endl;


    //New table sizes
    cout<<"Table sizes: Separate Chaining, getkey function 1"<< endl;
    cout<<sepChainingWin1.getTableSize()<<endl;
    cout<<sepChainingWin2.getTableSize()<<endl;
    cout<<sepChainingWin3.getTableSize()<<endl;
    cout<<sepChainingWin4.getTableSize()<<endl;
    cout<<sepChainingWin5.getTableSize()<<endl;

    cout<<"Table sizes: Separate Chaining, getkey function 2"<< endl;
    cout<<sepChainingLose1.getTableSize()<<endl;
    cout<<sepChainingLose2.getTableSize()<<endl;
    cout<<sepChainingLose3.getTableSize()<<endl;
    cout<<sepChainingLose4.getTableSize()<<endl;
    cout<<sepChainingLose5.getTableSize()<<endl;


    cout<<"Table sizes: Exponential probing, getkey function 1"<< endl;
    cout<<exProbWin1.getTableSize()<<endl;
    cout<<exProbWin2.getTableSize()<<endl;
    cout<<exProbWin3.getTableSize()<<endl;
    cout<<exProbWin4.getTableSize()<<endl;
    cout<<exProbWin5.getTableSize()<<endl;

    cout<<"Table sizes: Exponential probing, getkey function 2" << endl;
    cout<<exProbLose1.getTableSize()<<endl;
    cout<<exProbLose2.getTableSize()<<endl;
    cout<<exProbLose3.getTableSize()<<endl;
    cout<<exProbLose4.getTableSize()<<endl;
    cout<<exProbLose5.getTableSize()<<endl;


    //Close files
    outFileSepChainWin1.close();
    outFileSepChainWin2.close();
    outFileSepChainWin3.close();
    outFileSepChainWin4.close();
    outFileSepChainWin5.close();

    outFileSepChainLose1.close();
    outFileSepChainLose2.close();
    outFileSepChainLose3.close();
    outFileSepChainLose4.close();
    outFileSepChainLose5.close();

    outFileExProbWin1.close();
    outFileExProbWin2.close();
    outFileExProbWin3.close();
    outFileExProbWin4.close();
    outFileExProbWin5.close();

    outFileExProbLose1.close();
    outFileExProbLose2.close();
    outFileExProbLose3.close();
    outFileExProbLose4.close();
    outFileExProbLose5.close();


    return 0;
}



