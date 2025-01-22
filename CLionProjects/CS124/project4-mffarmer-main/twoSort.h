//
// Created by Michael Farmer on 11/7/22.
//

#ifndef PROJECT4_TWOSORT_H
#define PROJECT4_TWOSORT_H

#include "quickSort.h"
#include "ATPMatches.h"
#include "printVec.h"

void twoSort(vector<ATPMatch> vec, int& reads, int& writes){
    reads = 0;
    writes = 0;

    //Selection sort first
    int swapIndex, i, minIndex;
    ATPMatch temp;
    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            reads+=2;
            if (vec[i] < vec[minIndex]) {
                // We have a new minimum
                minIndex = i;
            }
        }
        // Swap min value into swapIndex spot in vector
        temp = vec[swapIndex];
        reads++;
        writes++;
        vec[swapIndex] = vec[minIndex];
        reads++;
        writes++;
        vec[minIndex] = temp;
        reads++;
        writes++;
    }

    //Insertion sort next
    int unsortedStartIndex, insertIndex;
    ATPMatch toBeInserted;
    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex];
        reads++;
        writes++;
        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;
        while (insertIndex >= 0 && vec[insertIndex].getW1stWon() > toBeInserted.getW1stWon()) {
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

#endif //PROJECT4_TWOSORT_H
