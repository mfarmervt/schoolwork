#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H
#include <vector>
#include <iostream>
#include "printVec.h"

template<typename Comparable>
void bubbleSort(std::vector<Comparable> vec, int& reads, int& writes) {
    reads = 0;
    writes = 0;
    int numPasses = 0, i;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i + 1 < vec.size() - numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            reads += 2;
            if (vec[i] > vec[i + 1]) {
                temp = vec[i];
                reads++;
                writes++;
                vec[i] = vec[i + 1];
                reads++;
                writes++;
                vec[i + 1] = temp;
                reads++;
                writes++;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;
    }
}

#endif
