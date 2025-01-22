#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H
#include <vector>
#include <iostream>
#include "printVec.h"


template<typename Comparable>
void insertionSort(std::vector<Comparable> vec, int& reads, int& writes) {
    reads = 0;
    writes = 0;
    int unsortedStartIndex, insertIndex;
    Comparable toBeInserted;
    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex];
        reads++;
        writes++;
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;
        while (insertIndex >= 0 && vec[insertIndex] > toBeInserted) {
            reads+=2;
            vec[insertIndex + 1] = vec[insertIndex];
            reads++;
            writes++;
            --insertIndex;
        }
        // Put toBeInserted back into vec
        vec[insertIndex + 1] = toBeInserted;
        reads++;
        writes++;
    }
}

#endif
