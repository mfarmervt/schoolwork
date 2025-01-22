#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "ATPMatches.h"
#include <string>

using namespace std;
using namespace std::chrono;

int main() {

    /**
     * Tree structures for integers 1-100
     */
    //Create BST of type integer, add int values from 1-100.
    BinarySearchTree<int> bst;

    //initialize depth variable
    int depth = 0;

    for(int i = 1; i <= 100; i++){
        bst.add(i);
    }


    // Output of BST data to file
    ofstream outFile;
    outFile.open("../data/BST_depths.txt");
    for (int x = 1; x <=100; x++) {
        bst.find(x, depth);
        outFile << depth << endl;
    }
    outFile.close();

    //Test find function
    bst.find(0, depth);
    cout<<depth<<endl;

    bst.find(100, depth);
    cout<<depth<<endl;

    bst.find(101, depth);
    cout<<depth<<endl;


    //AVL tree for integers from 1-100.
    AVLTree<int> avlTree;

    for(int i = 1; i<=100; i++){
        avlTree.add(i);
    }
    // Output of BST data to file
    ofstream outFileAVL;
    outFileAVL.open("../data/AVL_depths.txt");
    for (int x = 1; x <=100; x++) {
        avlTree.find(x, depth);
        outFileAVL << depth << endl;
    }
    outFileAVL.close();

    //Splay tree for integers 1-100.
    SplayTree<int> splayTree;

    for(int i = 1; i<=100; i++){
        splayTree.add(i);
    }

    // Output of BST data to file
    ofstream outFileSplay;
    outFileSplay.open("../data/Splay_depths.txt");
    for (int x = 1; x <=100; x++) {
        splayTree.find(x, depth);
        outFileSplay << depth << endl;
    }
    outFileSplay.close();



    /**
     * Trees for randomized integers from 1-100.
     */
    //BST of random integers from 1-100.

    //Create vector to shuffle
    vector<int> randVec;
    //populate vector
    for(int i = 1; i <= 100; i++){
        randVec.push_back(i);
    }

    //shuffle vector
    // get a time-based seed
    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randVec.begin(), randVec.end(), default_random_engine(seed));

    BinarySearchTree<int> randBST;
    for(int i = 0; i<randVec.size();i++){
        randBST.add(randVec[i]);
    }

    //output to file
    ofstream outFileRandBST;
    outFileRandBST.open("../data/RandomBST_depths.txt");
    for (int x = 1; x <=100; x++) {
        randBST.find(x, depth);
        outFileRandBST << depth << endl;
    }
    outFileRandBST.close();

    //Random AVL tree
    AVLTree<int> randAVL;
    for(int i = 0; i<randVec.size();i++){
        randAVL.add(randVec[i]);
    }
    //output to file
    ofstream outFileRandAVL;
    outFileRandAVL.open("../data/RandomAVL_depths.txt");
    for (int x = 1; x <=100; x++) {
        randAVL.find(x, depth);
        outFileRandAVL << depth << endl;
    }
    outFileRandAVL.close();

    //Random splay tree
    SplayTree<int> randSplay;
    for(int i = 0; i<randVec.size();i++) {
        randSplay.add(randVec[i]);
    }

    //output to file
    ofstream outFileRandSplay;
    outFileRandSplay.open("../data/RandomSplay_depths.txt");
    for (int x = 1; x <=100; x++) {
        randSplay.find(x, depth);
        outFileRandSplay << depth << endl;
    }
    outFileRandSplay.close();


    /**
     * Tree structures for ATPMatch data
     */

    //Create vector for storing ATPMatch data.

    vector<ATPMatch> matches;
    string fileName = "../atp_matches_2022.csv";


    //Verify that file was read successfully.
    if(loadFromFile(fileName, matches)){
        cout<<"File read successfully"<<endl;
    }
    else{
        cout<<"File unable to be read";
    }

    //BST for ATPMatches
    BinarySearchTree<ATPMatch> atpBST;

    for(int i = 0; i<matches.size();i++){
        atpBST.add(matches[i]);
    }

    //output depths to file.
    ofstream outFileAtpBST;
    outFileAtpBST.open("../data/AtpBST_depths.txt");
    for (int x = 0; x<matches.size() ; x++) {
        atpBST.find(matches[x], depth);
        outFileAtpBST << depth << endl;
    }
    outFileAtpBST.close();


    //AVL tree for ATPMatch data
    AVLTree<ATPMatch> atpAVL;

    for(int i = 0; i<matches.size();i++){
        atpAVL.add(matches[i]);
    }

    //output depths to file.
    ofstream outFileAtpAVL;
    outFileAtpAVL.open("../data/AtpAVL_depths.txt");
    for (int x = 0; x<matches.size() ; x++) {
        atpAVL.find(matches[x], depth);
        outFileAtpAVL << depth << endl;
    }
    outFileAtpAVL.close();


    //Splay tree for ATPMatch data
    SplayTree<ATPMatch> atpSplay;

    for(int i = 0; i<matches.size();i++){
        atpSplay.add(matches[i]);
    }

    //output depths to file.
    ofstream outFileAtpSplay;
    outFileAtpSplay.open("../data/AtpSplay_depths.txt");
    for (int x = 0; x<matches.size() ; x++) {
        atpSplay.find(matches[x], depth);
        outFileAtpSplay << depth << endl;
    }
    outFileAtpSplay.close();

    //Splay tree for ATPMatch data with 5 searches/element
    SplayTree<ATPMatch> atpSplayFive;

    for(int i = 0; i<matches.size();i++){
        atpSplayFive.add(matches[i]);
    }

    //output depths to file.
    ofstream outFileAtpSplayFive;
    outFileAtpSplayFive.open("../data/AtpSplayFive_depths.txt");
    for (int x = 0; x<matches.size() ; x++) {
        for(int j = 0; j<5; j++){
            atpSplayFive.find(matches[x], depth);
            outFileAtpSplayFive << depth << endl;
        }
    }
    outFileAtpSplayFive.close();


    /**
     * Extra Credit
     */

    //Time insertion into ordered BST, AVL, and splay
    //BST
    auto start = high_resolution_clock::now();
    bst.add(105);
    auto stop = high_resolution_clock::now();
    //output time taken to insert
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "105 was added to the ordered BST in "<<duration.count()<<" nanoseconds" << endl;
    bst.remove(105);

    //AVL tree
    auto startAVL = high_resolution_clock::now();
    avlTree.add(105);
    auto stopAVL = high_resolution_clock::now();
    //output time taken to insert
    auto durationAVL = duration_cast<nanoseconds>(stopAVL - startAVL);
    cout << "105 was added to the ordered AVL in "<<durationAVL.count()<<" nanoseconds" << endl;
    avlTree.remove(105);

    //Ordered Splay tree
    auto startSplay = high_resolution_clock::now();
    splayTree.add(105);
    auto stopSplay = high_resolution_clock::now();
    //output time taken to insert
    auto durationSplay = duration_cast<nanoseconds>(stopSplay - startSplay);
    cout << "105 was added to the ordered Splay tree in "<<durationSplay.count()<<" nanoseconds" << endl;
    splayTree.remove(105);

    //Time insertion into randomized BST, AVL, and splay
    //BST
    auto startRBST = high_resolution_clock::now();
    randBST.add(105);
    auto stopRBST = high_resolution_clock::now();
    //output time taken to insert
    auto durationRBST = duration_cast<nanoseconds>(stopRBST - startRBST);
    cout << "105 was added to the random-ordered BST in "<<durationRBST.count()<<" nanoseconds" << endl;
    randBST.remove(105);

    //Randomized AVL tree
    auto startRAVL = high_resolution_clock::now();
    randAVL.add(105);
    auto stopRAVL = high_resolution_clock::now();
    //output time taken to insert
    auto durationRAVL = duration_cast<nanoseconds>(stopRAVL - startRAVL);
    cout << "105 was added to the random-ordered AVL in "<<durationRAVL.count()<<" nanoseconds" << endl;
    randAVL.remove(105);

    //Randomized Splay tree
    auto startRSplay = high_resolution_clock::now();
    randSplay.add(105);
    auto stopRSplay = high_resolution_clock::now();
    //output time taken to insert
    auto durationRSplay = duration_cast<nanoseconds>(stopRSplay - startRSplay);
    cout << "105 was added to the random-ordered Splay tree in "<<durationRSplay.count()<<" nanoseconds" << endl;
    randSplay.remove(105);


    /**
     * Create 10 Random BST trees and calculate average max depth/height of the trees
     */
    //Initialize variable for sum of depths and maxDepth to be used later.
    int depthSum = 0;
    int maxDepth = 0;

    vector<int> randomVec;
    //populate vector in order
    for(int i = 1; i<=100; i++){
        randomVec.push_back(i);
    }
    //first randomization:
    unsigned seedRand1 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand1));

    //Create first BST
    BinarySearchTree<int> randBSTHeight1;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight1.add(randomVec[i]);
    }

    //find max depth in this tree:
    for(int i = 1; i<=100;i++){
        randBSTHeight1.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Second randomization:
    unsigned seedRand2 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand2));

    //Create BST
    BinarySearchTree<int> randBSTHeight2;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight2.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight2.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Third randomization:
    unsigned seedRand3 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand3));

    //Create BST
    BinarySearchTree<int> randBSTHeight3;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight3.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight3.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Fourth randomization:
    unsigned seedRand4 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand4));

    //Create BST
    BinarySearchTree<int> randBSTHeight4;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight4.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight4.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Fifth randomization:
    unsigned seedRand5 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand5));

    //Create BST
    BinarySearchTree<int> randBSTHeight5;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight5.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight5.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Sixth randomization:
    unsigned seedRand6 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand6));

    //Create BST
    BinarySearchTree<int> randBSTHeight6;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight6.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight6.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Seventh randomization:
    unsigned seedRand7 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand7));

    //Create BST
    BinarySearchTree<int> randBSTHeight7;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight7.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight7.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Eighth randomization:
    unsigned seedRand8 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand8));

    //Create BST
    BinarySearchTree<int> randBSTHeight8;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight8.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight8.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Ninth randomization:
    unsigned seedRand9 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand9));

    //Create BST
    BinarySearchTree<int> randBSTHeight9;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight9.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight9.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Tenth randomization:
    unsigned seedRand10 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVec.begin(), randomVec.end(), default_random_engine(seedRand10));

    //Create BST
    BinarySearchTree<int> randBSTHeight10;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randBSTHeight10.add(randomVec[i]);
    }

    //find max depth in this tree:
    maxDepth = 0;
    for(int i = 1; i<=100;i++){
        randBSTHeight10.find(i, depth);
        if(depth > maxDepth){
            maxDepth = depth;
        }
    }
    depthSum += maxDepth;

    //Calculate average depths:
    double avDepth = (double)depthSum/10;
    cout<<"The average heights for ten randomized BSTs of integers 1-100 was: "<<avDepth<<endl;

    //AVL tree average depth
    //Initialize variable for sum of depths and maxDepth to be used later.
    int depthSumAVL = 0;
    int maxDepthAVL = 0;

    vector<int> randomVecAVL;
    //populate vector in order
    for(int i = 1; i<=100; i++){
        randomVecAVL.push_back(i);
    }
    //first randomization:
    unsigned seedRandAVL1 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL1));

    //Create first AVL
    AVLTree<int> randAVLHeight1;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight1.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    for(int i = 1; i<=100;i++){
        randAVLHeight1.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Second randomization:
    unsigned seedRandAVL2 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL2));

    //Create AVL
    AVLTree<int> randAVLHeight2;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight2.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight2.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Third randomization:
    unsigned seedRandAVL3 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL3));

    //Create BST
    AVLTree<int> randAVLHeight3;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight3.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight3.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Fourth randomization:
    unsigned seedRandAVL4 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL4));

    //Create AVL
    AVLTree<int> randAVLHeight4;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight4.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight4.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Fifth randomization:
    unsigned seedRandAVL5 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL5));

    //Create AVL
    AVLTree<int> randAVLHeight5;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight5.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight5.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Sixth randomization:
    unsigned seedRandAVL6 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL6));

    //Create AVL
    AVLTree<int> randAVLHeight6;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight6.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight6.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Seventh randomization:
    unsigned seedRandAVL7 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL7));

    //Create AVL
    AVLTree<int> randAVLHeight7;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight7.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight7.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Eighth randomization:
    unsigned seedRandAVL8 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL8));

    //Create AVL
    AVLTree<int> randAVLHeight8;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight8.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight8.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Ninth randomization:
    unsigned seedRandAVL9 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL9));

    //Create AVL
    AVLTree<int> randAVLHeight9;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight9.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight9.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Tenth randomization:
    unsigned seedRandAVL10 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecAVL.begin(), randomVecAVL.end(), default_random_engine(seedRandAVL10));

    //Create BST
    AVLTree<int> randAVLHeight10;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randAVLHeight10.add(randomVecAVL[i]);
    }

    //find max depth in this tree:
    maxDepthAVL = 0;
    for(int i = 1; i<=100;i++){
        randAVLHeight10.find(i, depth);
        if(depth > maxDepthAVL){
            maxDepthAVL = depth;
        }
    }
    depthSumAVL += maxDepthAVL;

    //Calculate average depths:
    double avDepthAVL = (double)depthSumAVL/10;
    cout<<"The average heights for ten randomized AVLs of integers 1-100 was: "<<avDepthAVL<<endl;


    //Splay tree average depth

    //Initialize variable for sum of depths and maxDepth to be used later.
    int depthSumSplay = 0;
    int maxDepthSplay = 0;

    vector<int> randomVecSplay;
    //populate vector in order
    for(int i = 1; i<=100; i++){
        randomVecSplay.push_back(i);
    }
    //first randomization:
    unsigned seedRandSplay1 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay1));

    //Create first Splay
    SplayTree<int> randSplayHeight1;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight1.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    for(int i = 1; i<=100;i++){
        randSplayHeight1.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Second randomization:
    unsigned seedRandSplay2 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay2));

    //Create BST
    SplayTree<int> randSplayHeight2;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight2.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight2.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Third randomization:
    unsigned seedRandSplay3 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay3));

    //Create Splay
    SplayTree<int> randSplayHeight3;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight3.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight3.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Fourth randomization:
    unsigned seedRandSplay4 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay4));

    //Create Splay
    SplayTree<int> randSplayHeight4;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight4.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight4.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Fifth randomization:
    unsigned seedRandSplay5 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay5));

    //Create Splay
    SplayTree<int> randSplayHeight5;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight5.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight5.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Sixth randomization:
    unsigned seedRandSplay6 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay6));

    //Create BST
    SplayTree<int> randSplayHeight6;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight6.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight6.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Seventh randomization:
    unsigned seedRandSplay7 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay7));

    //Create Splay
    BinarySearchTree<int> randSplayHeight7;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight7.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight7.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Eighth randomization:
    unsigned seedRandSplay8 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay8));

    //Create BST
    SplayTree<int> randSplayHeight8;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight8.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight8.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Ninth randomization:
    unsigned seedRandSplay9 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay9));

    //Create Splay
    SplayTree<int> randSplayHeight9;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight9.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight9.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Tenth randomization:
    unsigned seedRandSplay10 = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    shuffle (randomVecSplay.begin(), randomVecSplay.end(), default_random_engine(seedRandSplay10));

    //Create Splay
    SplayTree<int> randSplayHeight10;
    //Find max height using loop.
    for(int i = 0; i<100; i++){
        randSplayHeight10.add(randomVecSplay[i]);
    }

    //find max depth in this tree:
    maxDepthSplay = 0;
    for(int i = 1; i<=100;i++){
        randSplayHeight10.find(i, depth);
        if(depth > maxDepthSplay){
            maxDepthSplay = depth;
        }
    }
    depthSumSplay += maxDepthSplay;

    //Calculate average depths:
    double avDepthSplay = (double)depthSumSplay/10;
    cout<<"The average heights for ten randomized Splay trees of integers 1-100 was: "<<avDepthSplay<<endl;



    return 0;
}