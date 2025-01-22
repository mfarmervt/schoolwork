/**
 * Michael Farmer
 * CS 124
 * Section A
 */

#include "Stack.h"
#include "Queue.h"
#include "ATPMatches.h"
#include <string>
#include <vector>


int main() {

    //Show functionality of Queue of ints

    //Initialize queue of ints
    Queue<int> qInt;

    //add items
    qInt.enqueue(12);
    qInt.enqueue(15);
    qInt.enqueue(27);

    //remove items
    qInt.dequeue();
    qInt.dequeue();

    //Add another item.
    qInt.enqueue(29);

    //print queue:  should display 27 29
    qInt.print();

    //Check that two arbitrary elements are in the queue using search method
    std::cout<<std::boolalpha;
    std::cout<<"Is 27 in the queue? " <<qInt.search(27)<<std::endl;
    std::cout<<"Is 13 in the queue? "<<qInt.search(13)<<std::endl<<std::endl;


    //Create queue of strings
    Queue<std::string> qString;
    qString.enqueue("Michael");
    qString.enqueue("Mary");
    qString.enqueue("Brendan");
    qString.enqueue("Rosie");
    qString.enqueue("Catherine");

    qString.dequeue();
    qString.enqueue("Michael");

    //Display queue, should display Mary Brendan Rosie Catherine Michael
    qString.print();
    std::cout<<std::endl;

    //Create vector of ATPMatches
    std::vector<ATPMatch> matches;
    std::string fileName = "../atp_matches_2022.csv";
    if(loadFromFile(fileName, matches)){
        std::cout<<"File read successfully"<<std::endl<<std::endl;
    }
    else{
        std::cout<<"File not read successfully"<<std::endl<<std::endl;
    }

    //Create queue of ATPMatch objects
    Queue<ATPMatch> qATP;

    //Loop through and add objects to queue and display the object being added.
    for(int i = 0; i<10; i++){
        std::cout<<"Object #"<<i+1<<" added to the queue."<<std::endl;
        qATP.enqueue(matches[i]);
        std::cout<<matches[i]<<std::endl;

    }

    //Should add ATPMatches with rowID 0-9 to queue.


    //Create stack object and push dequeued objects from qATP to sATP.
    //Order should be the same as the queue, with object 1 being at bottom, 10 at top.
    Stack<ATPMatch> sATP;
    for(int i = 0; i<10; i++){
        sATP.push(qATP.dequeue());
    }

    std::cout<<"Items have been added to the stack."<<std::endl<<std::endl;

    //Write a few lines of blank output to separate lists of objects being displayed
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Items being popped"<<std::endl<<std::endl;

    //Pop every item off of the stack and print them.
    for(int i = 0; i<10; i++){
        std::cout<<"Item number "<<i+1<<" popped from the stack. "<<std::endl;
        std::cout<<sATP.pop()<<std::endl;
    }


    return 0;
}