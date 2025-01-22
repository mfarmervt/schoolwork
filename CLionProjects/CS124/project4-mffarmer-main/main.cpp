#include "bubbleSort.h"
#include "insertionSort.h"
#include "heapSort.h"
#include "quickSort.h"
#include <vector>
#include "ATPMatches.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include "twoSort.h"
#include "selectionSort.h"

using namespace std::chrono;
using namespace std;

int main() {

    //initialize variables for reads and writes to be passed by reference into functions
    int reads = 0;
    int writes = 0;

    //Create vector for storing ATPMatch data.

    vector<ATPMatch> matches;
    string fileName = "../atp_matches_2022.csv";

    //Verify that file was read successfully.
    if(loadFromFile(fileName, matches)){
        std::cout<<"File read successfully"<<std::endl;
    }
    else {
        std::cout << "File unable to be read";
    }

    //Resize vector down to 1000
    matches.resize(1000);

    cout<<"Reads/writes for sorting algorithms on vector of 1000 ATP Matches"<<endl<<endl;

    //Bubble sort:
    auto start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    auto stop = high_resolution_clock::now();
    //output time taken to sort
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 900
    matches.resize(900);

    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 900 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 800
    matches.resize(800);

    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 800 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 700
    matches.resize(700);

    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 700 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 600
    matches.resize(600);
    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 600 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 500
    matches.resize(500);
    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 500 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 400
    matches.resize(400);
    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 400 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 300
    matches.resize(300);
    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 300 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 200
    matches.resize(200);
    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 200 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 100
    matches.resize(100);
    cout<<"Reads/writes for sorting algorithms on vector of ATP Matches with 100 elements"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<<endl;
    cout<<"Number of writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    cout << string(100, '*') << endl;
    cout << string(100, '*') << endl;

    /**
     * Experiment with halving the vector size instead of reducing it by a 100 each time
     */

    vector<ATPMatch> matches2;
    string newFileName = "../atp_matches_2022.csv";

    //Verify that file was read successfully.
    if(loadFromFile(newFileName, matches2)){
        std::cout<<"File read successfully"<<std::endl;
    }
    else {
        std::cout << "File unable to be read";
    }
    int vectorSize = matches2.size();
    cout<<endl;

    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 900
    vectorSize /= 2;
    matches2.resize(vectorSize);

    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size: 800
    vectorSize /= 2;
    matches2.resize(vectorSize);
    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size
    vectorSize /= 2;
    matches2.resize(vectorSize);
    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size
    vectorSize /= 2;
    matches2.resize(vectorSize);
    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size
    vectorSize /= 2;
    matches2.resize(vectorSize);
    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size
    vectorSize /= 2;
    matches2.resize(vectorSize);
    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size
    vectorSize /= 2;
    matches2.resize(vectorSize);
    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size
    vectorSize /= 2;
    matches2.resize(vectorSize);
    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    cout << string(100, '*') << endl;
    //Vector size
    vectorSize /= 2;
    matches2.resize(vectorSize);
    cout<<"Reads/writes for sorting algorithms on vector of "<<vectorSize<< " ATP Matches"<<endl<<endl;

    //Bubble sort:
    start = high_resolution_clock::now();
    bubbleSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Bubble Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Insertion sort
    start = high_resolution_clock::now();
    insertionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Insertion Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Quick sort
    start = high_resolution_clock::now();
    quickSortStable(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Quick Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Heap sort
    start = high_resolution_clock::now();
    heapSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Heap Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Two sort
    start = high_resolution_clock::now();
    twoSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"TwoSort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    //Extra: Selection Sort
    start = high_resolution_clock::now();
    selectionSort(matches2, reads, writes);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout<<"Selection Sort: "<<endl;
    cout<<"Number of reads: "<<reads<< ".  Number of Writes: "<<writes<<endl;
    cout<<"Vector sorted in "<< duration.count() <<" microseconds."<<endl<<endl;

    return 0;
}