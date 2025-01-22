#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "printVec.h"

template<typename Comparable>
void quickSortUnstableRec(vector<Comparable> &vec, int startIndex, int endIndex) {
    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[startIndex];

    // Loop through vec from startIndex to endIndex
    // Keep track of where the > partition elements start
    int i;
    int largerElementIndex = startIndex+1;
    Comparable temp;
    for (i = startIndex+1; i <= endIndex; ++i) {
        if (vec[i] <= partition) {
            // Swap the smaller/equal item to the left of the larger items
            temp = vec[i];
            vec[i] = vec[largerElementIndex];
            vec[largerElementIndex] = temp;
            // Update largerElementIndex
            ++largerElementIndex;
        }
    }
    // Swap the partition element into place
    temp = vec[startIndex];
    vec[startIndex] = vec[largerElementIndex-1];
    vec[largerElementIndex-1] = temp;

    printVec(vec);

    // Recursive calls for two halves
    quickSortUnstableRec(vec, startIndex, largerElementIndex-2);
    quickSortUnstableRec(vec, largerElementIndex, endIndex);
}

template<typename Comparable>
void quickSortUnstable(vector<Comparable> vec) {
    quickSortUnstableRec(vec, 0, vec.size() - 1);
}

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec, int& reads, int& writes) {

    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }

    // Choose a partition element
    Comparable partition = vec[0];
    reads++;
    writes++;

    vector<Comparable> smaller, equal, larger;
    // Loop through vec and populate smaller, equal, larger
    int i;
    for (i = 0; i < vec.size(); ++i) {
        //Each if statement will be evaluated, so 4 reads since vec[i], partition are comparables
        reads+=4;
        if (vec[i] < partition) {
            smaller.push_back(vec[i]);
            reads++;
            writes++;
        } else if (vec[i] > partition) {
            larger.push_back(vec[i]);
            reads++;
            writes++;
        } else {
            equal.push_back(vec[i]);
            reads++;
            writes++;
        }
    }

    // Recursive calls
    quickSortStableRec(smaller, reads, writes);
    quickSortStableRec(larger, reads, writes);

    // Copy elements from smaller, equal, and larger back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
            reads++;
            writes++;
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
            reads++;
            writes++;
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
            reads++;
            writes++;
        }
    }
}

template<typename Comparable>
void quickSortStable(vector<Comparable> vec, int &reads, int &writes) {
    reads = 0;
    writes = 0;
    quickSortStableRec(vec, reads, writes);
}

#endif
