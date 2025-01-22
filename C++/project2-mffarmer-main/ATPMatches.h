/**
 * Michael Farmer
 * CS 124
 * Section A
 */



#ifndef ATPMATCH_H
#define ATPMATCH_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

//define class
class ATPMatch {

    /**
     * Class representing ATP tennis matches from the calendar year 2022 (as of 9/11/2022).
     *
     * Fields (naming follows abbreviations from csv file):
     *      rowID**: unique number for every ATP match found in the dataset.
     *      tourneyDate: date of the first Monday of the tournament week, in the form YYYYMMDD
     *      minutes: duration of the match in minutes
     *      wAce: number of aces by the winner
     *      w1stIn: number of 1st-serves made by the winner
     *      w1stWon: number of 1st-serve points won by the winner
     *      wBpSaved: number of break points saved by the winner
     *      wBpFaced: number of break points faced by the winner
     *      lAce: number of aces by the loser
     *      l1stIn: numer of 1st-serve points made by the loser
     *      l1stWon: number of 1st-serve points won by the loser
     *      lBpSaved: number of break points saved by the loser
     *      lBpFaced: number of break points faced by the loser
     *      tourneyName: the name of the tournament
     *      winnerName: the winner's name
     *      loserName: the loser's name
     *      score: the score of the match, represented by a string.
     *
     *      **Note: rowID was not in the original csv file, but is created in the loadFromFile function to
     *      have an attribute that is unique for every ATPMatch object.
     */

private:
    int rowID, tourneyDate, minutes, wAce, w1stIn, w1stWon, wBpSaved, wBpFaced, lAce,
            l1stIn, l1stWon, lBpSaved, lBpFaced;
    std::string tourneyName, winnerName, loserName, score;

public:
    //constructors.
    ATPMatch() {
        //Add hard coded field values.
        rowID = -1;
        tourneyDate = -1;
        minutes = -1;
        wAce = -1;
        w1stIn = -1;
        w1stWon = -1;
        wBpSaved = -1;
        wBpFaced = -1;
        lAce = -1;
        l1stIn = -1;
        l1stWon = -1;
        lBpSaved = -1;
        lBpFaced = -1;
        tourneyName = "INVALID";
        winnerName = "INVALID";
        loserName = "INVALID";
        score = "INVALID";
    }

    ATPMatch(int rowID,
             int tourneyDate,
             int minutes,
             int wAce,
             int w1stIn,
             int w1stWon,
             int wBpSaved,
             int wBpFaced,
             int lAce,
             int l1stIn,
             int l1stWon,
             int lBpSaved,
             int lBpFaced,
             std::string tourneyName,
             std::string winnerName,
             std::string loserName,
             std::string score) {

        this->rowID = rowID;
        this->tourneyDate = tourneyDate;
        this->minutes = minutes;
        this->wAce = wAce;
        this->w1stIn = w1stIn;
        this->w1stWon = w1stWon;
        this->wBpSaved = wBpSaved;
        this->wBpFaced = wBpFaced;
        this->lAce = lAce;
        this->l1stIn = l1stIn;
        this->l1stWon = l1stWon;
        this->lBpSaved = lBpSaved;
        this->lBpFaced = lBpFaced;
        this->tourneyName = tourneyName;
        this->winnerName = winnerName;
        this->loserName = loserName;
        this->score = score;
    }

    //Getters
    int getRowId() const {
        return rowID;
    }

    int getTourneyDate() const {
        return tourneyDate;
    }

    int getMinutes() const {
        return minutes;
    }

    int getWAce() const {
        return wAce;
    }

    int getW1stIn() const {
        return w1stIn;
    }

    int getW1stWon() const {
        return w1stWon;
    }

    int getWBpSaved() const {
        return wBpSaved;
    }

    int getWBpFaced() const {
        return wBpFaced;
    }

    int getLAce() const {
        return lAce;
    }

    int getL1stIn() const {
        return l1stIn;
    }

    int getL1stWon() const {
        return l1stWon;
    }

    int getLBpSaved() const {
        return lBpSaved;
    }

    int getLBpFaced() const {
        return lBpFaced;
    }

    std::string getTourneyName() const {
        return tourneyName;
    }

    std::string getWinnerName() const {
        return winnerName;
    }

    std::string getLoserName() const {
        return loserName;
    }

    std::string getScore() const {
        return score;
    }

    //Setters
    void setRowId(int rowID) {
        this->rowID = rowID;
    }

    void setTourneyDate(int tourneyDate) {
        this->tourneyDate = tourneyDate;
    }

    void setMinutes(int minutes) {
        this->minutes = minutes;
    }

    void setWAce(int wAce) {
        this->wAce = wAce;
    }

    void setW1stIn(int w1stIn) {
        this->w1stIn = w1stIn;
    }

    void setW1stWon(int w1stWon) {
        this->w1stWon = w1stWon;
    }

    void setWBpSaved(int wBpSaved) {
        this->wBpSaved = wBpSaved;
    }

    void setWBpFaced(int wBpFaced) {
        this->wBpFaced = wBpFaced;
    }

    void setLAce(int lAce) {
        this->lAce = lAce;
    }

    void setL1stIn(int l1stIn) {
        this->l1stIn = l1stIn;
    }

    void setL1stWon(int l1stWon){
        this-> l1stWon = l1stWon;
    }

    void setLBpSaved(int lBpSaved) {
        this->lBpSaved = lBpSaved;
    }

    void setLBpFaced(int lBpFaced) {
        this->lBpFaced = lBpFaced;
    }

    void setTourneyName(std::string tourneyName) {
        this->tourneyName = tourneyName;
    }

    void setWinnerName(std::string winnerName) {
        this->winnerName = winnerName;
    }

    void setLoserName(std::string loserName) {
        this->loserName = loserName;
    }

    void setScore(std::string score) {
        this->score = score;
    }

    /**
     * Overloaded << operator for formatted printing.  Too many attributes, so it is arranged as a
     * "stats box" for each ATP match object
     */

    friend std::ostream& operator << (std::ostream& outs, const ATPMatch& aObj){
        outs << std::fixed
             << std::left
             << std::string(70, '-')
             << std::endl
             << std::setw(10) << "RowID"
             << std::setw(20) << "Tourney Date"
             << std::setw(20) << "Tourney Name"
             << std::setw(20) << "Minutes Played"
             << std::endl
             << std::setw(10) << aObj.getRowId()
             << std::setw(20) << aObj.getTourneyDate()
             << std::setw(20) << aObj.getTourneyName()
             << std::setw(8) << aObj.getMinutes()
             << std::endl
             << std::endl
             << std::setw(30) << "Winner Name"
             << std::setw(8) << "Aces"
             << std::setw(8) << "1stIn"
             << std::setw(8) << "1stWon"
             << std::setw(8) << "BPSaved"
             << std::setw(8) << "BPFaced"
             << std::endl
             << std::setw(30) << aObj.getWinnerName()
             << std::setw(8) << aObj.getWAce()
             << std::setw(8) << aObj.getW1stIn()
             << std::setw(8) << aObj.getW1stWon()
             << std::setw(8) << aObj.getWBpSaved()
             << std::setw(8) << aObj.getWBpFaced()
             << std::endl
             << std::endl
             << std::setw(30) << "Loser Name"
             << std::setw(8) << "Aces"
             << std::setw(8) << "1stIn"
             << std::setw(8) << "1stWon"
             << std::setw(8) << "BPSaved"
             << std::setw(8) << "BPFaced"
             << std::endl
             << std::setw(30) << aObj.getLoserName()
             << std::setw(8) << aObj.getLAce()
             << std::setw(8) << aObj.getL1stIn()
             << std::setw(8) << aObj.getL1stWon()
             << std::setw(8) << aObj.getLBpSaved()
             << std::setw(8) << aObj.getLBpFaced()
             << std::endl
             << std::string(70, '-')
             << std::endl;

         return outs;
    }

    /**This function overloads the less than operator to compare two ATPMatch objects based on rowID
     *
     * @param atpLHS is an ATPMatch object
     * @param atpRHS is an ATPMatch object
     * @return a boolean true or false depending on the comparison between each object's rowID value
     */
    friend bool operator < (const ATPMatch& atpLHS, const ATPMatch& atpRHS){
        return atpLHS.getRowId() < atpRHS.getRowId();
    }

    /**This function overloads the greater than operator to compare two ATPMatch objects based on rowID
     *
     * @param atpLHS is an ATPMatch object
     * @param atpRHS is an ATPMatch object
     * @return a boolean true or false depending on the comparison between each object's rowID value
     */
    friend bool operator > (const ATPMatch& atpLHS, const ATPMatch& atpRHS){
        return atpLHS.getRowId() > atpRHS.getRowId();
    }

    /**This function overloads the less than or equal to operator to compare two ATPMatch objects
     * based on rowID
     *
     * @param atpLHS is an ATPMatch object
     * @param atpRHS is an ATPMatch object
     * @return a boolean true or false depending on the comparison between each object's rowID value
     */
    friend bool operator <= (const ATPMatch& atpLHS, const ATPMatch& atpRHS){
        return atpLHS.getRowId() <= atpRHS.getRowId();
    }

    /**This function overloads the greater than or equal to operator to compare two ATPMatch objects
     * based on rowID
     *
     * @param atpLHS is an ATPMatch object
     * @param atpRHS is an ATPMatch object
     * @return a boolean true or false depending on the comparison between each object's rowID value
     */
    friend bool operator >= (const ATPMatch& atpLHS, const ATPMatch& atpRHS){
        return atpLHS.getRowId() >= atpRHS.getRowId();
    }

    /**This function overloads the equal to operator to compare two ATPMatch objects based on rowID
     *
     * @param atpLHS is an ATPMatch object
     * @param atpRHS is an ATPMatch object
     * @return a boolean true or false depending on the comparison between each object's rowID value
     */
    friend bool operator == (const ATPMatch& atpLHS, const ATPMatch& atpRHS){
        return atpLHS.getRowId() == atpRHS.getRowId();
    }
};

/** This function takes in values for a fileName (a string) and a reference to a vector of ATPMatches
 * and loads the data from the file provided into the vector.
 *
 * @param fileName is a string for the name of the file.
 * @param objs is a reference to a vector of ATPMatch objects
 * @return true or false depending on whether the file was read into the vector or not.
 */
bool loadFromFile(std::string fileName, std::vector<ATPMatch>& objs) {

    std::ifstream fin;
    fin.open(fileName);

    //if file can't be opened
    if(!fin){
        return false;
        std::cout<<"File unable to be read";
    }

    //If file is good.

    //Remove header
    std::string header = "";
    getline(fin, header);

    //while loop to loop through the file and populate vector of ATPMatches
    int counter = 0;  //will be used to create rowID.
    while(fin && fin.peek() != EOF){
        //Sentinel values to be used if file contains empty cells for attributes
        int rowID = -1;
        int tourneyDate = -1;
        int minutes = -1;
        int wAce = -1;
        int w1stIn = -1;
        int w1stWon = -1;
        int wBpSaved = -1;
        int wBpFaced = -1;
        int lAce = -1;
        int l1stIn = -1;
        int l1stWon = -1;
        int lBpSaved = -1;
        int lBpFaced = -1;
        std::string tourneyName = "INVALID";
        std::string winnerName = "INVALID";
        std::string loserName = "INVALID";
        std::string score = "INVALID";
        char comma = ',';

        //need a variable to handle garbage variables.
        std::string garbage = "";

        //using counter to create rowID attribute
        rowID = counter;


        //Garbage attributes
        getline(fin, garbage, comma);  //Tourney ID


        //tourney name
        getline(fin, tourneyName, comma); //tourneyName

        //Garbage
        getline(fin, garbage, comma); //surface
        getline(fin, garbage, comma); //drawSize
        getline(fin, garbage, comma); //tourneyLevel

        //tourney Date
        fin>>tourneyDate;
        fin>>comma;

        //Garbage attributes
        getline(fin, garbage, comma); //matchnum
        getline(fin, garbage, comma); //winnerid
        getline(fin, garbage, comma); //winnerseed
        getline(fin, garbage, comma); //winnerentry

        //Winner name
        getline(fin, winnerName, comma);

        //Garbage attributes
        getline(fin, garbage, comma); //winner hand
        getline(fin, garbage, comma); //winner ht
        getline(fin, garbage, comma); //winner ioc
        getline(fin, garbage, comma); //winner age
        getline(fin, garbage, comma); //loser id
        getline(fin, garbage, comma); //loser seed
        getline(fin, garbage, comma); //loser entry

        //Loser Name
        getline(fin, loserName, comma);

        //Garbage attributes
        getline(fin, garbage, comma); //loser hand
        getline(fin, garbage, comma); //loser ht
        getline(fin, garbage, comma); //loser ioc
        getline(fin, garbage, comma); //loser age

        //Score
        getline(fin, score, comma);

        //Garbage attributes
        getline(fin, garbage, comma); //best of
        getline(fin, garbage, comma); //round

        //Minutes
        fin>>minutes;
        if(!fin){
            minutes = -1;

            //clear stream
            fin.clear();
        }
        fin>>comma;

        //Winner aces
        fin>>wAce;
        if(!fin){
            wAce = -1;

            //clear stream
            fin.clear();
        }
        fin>>comma;

        //Garbage
        getline(fin, garbage, comma); //wdf
        getline(fin, garbage, comma); //wsvpt


        //Winner 1st
        fin>>w1stIn;
        if(!fin){
            w1stIn = -1;
            fin.clear();
        }
        fin>>comma;

        //Winner 1st won
        fin>>w1stWon;
        if(!fin){
            w1stWon = -1;
            fin.clear();
        }
        fin>>comma;

        //Garbage
        getline(fin, garbage, comma);
        getline(fin, garbage, comma);


        //Winner BP saved
        fin>>wBpSaved;
        if(!fin){
            wBpSaved = -1;
            fin.clear();
        }
        fin>>comma;

        //Winner BP faced
        fin>>wBpFaced;
        if(!fin){
            wBpFaced = -1;
            fin.clear();
        }
        fin>>comma;

        //Loser Ace
        fin>>lAce;
        if(!fin){
            lAce = -1;
            fin.clear();
        }
        fin>>comma;

        //Garbage
        getline(fin, garbage, comma);
        getline(fin, garbage, comma);

        //Loser 1st In
        fin>>l1stIn;
        if(!fin){
            l1stIn = -1;
            fin.clear();
        }
        fin>>comma;

        //Loser 1st Won
        fin>>l1stWon;
        if(!fin){
            l1stWon = -1;
            fin.clear();
        }
        fin>>comma;

        //Garbage
        getline(fin, garbage, comma);
        getline(fin, garbage, comma);

        //Loser BP Saved
        fin>>lBpSaved;
        if(!fin){
            lBpSaved = -1;
            fin.clear();
        }
        fin>>comma;

        //Loser BP faced
        fin>>lBpFaced;
        if(!fin){
            lBpFaced = -1;
            fin.clear();
        }
        fin>>comma;

        //Garbage
        getline(fin, garbage, comma);
        getline(fin, garbage, comma);
        getline(fin, garbage, comma);

        if (fin.peek() != '\r' && fin.peek() != '\n') {
            getline(fin, garbage, '\n');
        }


        //Create ATPMatch object using given field data
        ATPMatch match(rowID,
                       tourneyDate,
                       minutes,
                       wAce,
                       w1stIn,
                       w1stWon,
                       wBpSaved,
                       wBpFaced,
                       lAce,
                       l1stIn,
                       l1stWon,
                       lBpSaved,
                       lBpFaced,
                       tourneyName,
                       winnerName,
                       loserName,
                       score);

        //populate vector<ATPMatch> with match object
        objs.push_back(match);
        //iterate counter
        counter++;
    }
    return true;
    //close file
    fin.close();
}



/** This function takes in a reference to a vector of ATPMatches as a parameter and computes the averages
 *  for all player numerical data (data for aces, 1st serves, and break points for the winner and loser).
 *
 * @param objs is a reference to a vector of ATPMatches
 */
void calculateAverages(std::vector<ATPMatch> & objs){

    //Doubles to store the averages.
    double wAvAces,
           lAvAces,
           wAv1stIn,
           lAv1stIn,
           wAv1stWon,
           lAv1stWon,
           wAvBPSaved,
           lAvBPSaved,
           wAvBPFaced,
           lAvBPFaced;

    //Ints for the sums of all of the attributes
    int totalWAces,
        totalW1stIn,
        totalW1stWon,
        totalWBPSaved,
        totalWBPFaced,
        totalLAces,
        totalL1stIn,
        totalL1stWon,
        totalLBPSaved,
        totalLBPFaced;

    //Counter variables for averages, since we can't have a single counter for every average computation.
    //Have to have individual counters because of cells in the dataset that might be invalid (-1).
    int wAceCt,
        w1stInCt,
        w1stWonCt,
        wBPSavedCt,
        wBPFAcedCt,
        lAceCt,
        l1stInCt,
        l1stWonCt,
        lBPSavedCt,
        lBPFacedCt;

        //Initialize everything to zero.
        wAvAces =
        lAvAces =
        wAv1stIn =
        lAv1stIn =
        wAv1stWon =
        lAv1stWon =
        wAvBPSaved =
        lAvBPSaved =
        wAvBPFaced =
        lAvBPFaced = 0.0;

        totalWAces =
        totalW1stIn =
        totalW1stWon =
        totalWBPSaved =
        totalWBPFaced =
        totalLAces =
        totalL1stIn =
        totalL1stWon =
        totalLBPSaved =
        totalLBPFaced = 0;

        wAceCt =
        w1stInCt =
        w1stWonCt =
        wBPSavedCt =
        wBPFAcedCt =
        lAceCt =
        l1stInCt =
        l1stWonCt =
        lBPSavedCt =
        lBPFacedCt = 0;

    //Iterate through length of the vector
    for(int i=0; i < objs.size(); i++){

        //winner attributes, ignoring -1 value
        if(objs[i].getWAce() != -1){
            totalWAces += objs[i].getWAce();
            wAceCt++;
        }
        if(objs[i].getW1stIn() != -1){
            totalW1stIn += objs[i].getW1stIn();
            w1stInCt++;
        }
        if(objs[i].getW1stWon() != -1){
            totalW1stWon += objs[i].getW1stWon();
            w1stWonCt++;
        }
        if(objs[i].getWBpSaved() != -1){
            totalWBPSaved += objs[i].getWBpSaved();
            wBPSavedCt++;
        }
        if(objs[i].getWBpFaced() != -1){
            totalWBPFaced += objs[i].getWBpFaced();
            wBPFAcedCt++;
        }

        //loser attributes, ignoring -1 values
        if(objs[i].getLAce() != -1){
            totalLAces += objs[i].getLAce();
            lAceCt++;
        }
        if(objs[i].getL1stIn() != -1){
            totalL1stIn += objs[i].getL1stIn();
            l1stInCt++;
        }
        if(objs[i].getL1stWon() != -1){
            totalL1stWon += objs[i].getL1stWon();
            l1stWonCt++;
        }
        if(objs[i].getLBpSaved() != -1){
            totalLBPSaved += objs[i].getLBpSaved();
            lBPSavedCt++;
        }
        if(objs[i].getLBpFaced() != -1){
            totalLBPFaced += objs[i].getLBpFaced();
            lBPFacedCt++;
        }
    }

    //Calculate averages
    wAvAces = (double)totalWAces / wAceCt;
    wAv1stIn = (double)totalW1stIn / w1stInCt;
    wAv1stWon = (double)totalW1stWon / w1stWonCt;
    wAvBPSaved = (double)totalWBPSaved / wBPSavedCt;
    wAvBPFaced = (double)totalWBPFaced / wBPFAcedCt;
    lAvAces = (double)totalLAces / lAceCt;
    lAv1stIn = (double)totalL1stIn / l1stInCt;
    lAv1stWon = (double)totalL1stWon / l1stWonCt;
    lAvBPSaved = (double)totalLBPSaved / lBPSavedCt;
    lAvBPFaced = (double)totalLBPFaced / lBPFacedCt;

    //Display averages in a small table.
    std::cout<< std::right
             << std::setprecision(2)
             << std::setw(20) << "Aces"
             << std::setw(10) << "1stIn"
             << std::setw(10) << "1stWon"
             << std::setw(10) << "BPSaved"
             << std::setw(10) << "BPFaced"
             << std::endl
             << std::setw(10) << "Winner"
             << std::setw(10) << wAvAces
             << std::setw(10) << wAv1stIn
             << std::setw(10) << wAv1stWon
             << std::setw(10) << wAvBPSaved
             << std::setw(10) << wAvBPFaced
             << std::endl
            << std::setw(10) << "Loser"
            << std::setw(10) << lAvAces
            << std::setw(10) << lAv1stIn
            << std::setw(10) << lAv1stWon
            << std::setw(10) << lAvBPSaved
            << std::setw(10) << lAvBPFaced;

}

/** This function takes in a reference to a vector of ATPMatches and determines which values
 *  for all attributes are invalid (-1 or "INVALID") at specific records in the dataset.
 *
 * @param objs is a reference to a vector of ATPMatches
 */
void verifyAllFieldsSet(std::vector<ATPMatch>& objs){

    int i = 0;
    for(ATPMatch& match: objs){
        if(match.getRowId() != i){
            std::cout<<"Bad rowID value at record: "<<i<<std::endl;
        }
        if(match.getTourneyDate() == -1){
            std::cout<<"Bad Tourney Date value at record: "<<i<<std::endl;
        }
        if(match.getMinutes() == -1){
            std::cout<<"Bad Minutes value at record: "<<i<<std::endl;
        }
        if(match.getWAce() == -1){
            std::cout<<"Bad wAce value at record: "<<i<<std::endl;
        }
        if(match.getW1stIn() == -1){
            std::cout<<"Bad w1stIn value at record: "<<i<<std::endl;
        }
        if(match.getW1stWon() == -1){
            std::cout<<"Bad w1stWon value at record: "<<i<<std::endl;
        }
        if(match.getWBpSaved() == -1){
            std::cout<<"Bad wBpSaved value at record: "<<i<<std::endl;
        }
        if(match.getWBpFaced() == -1){
            std::cout<<"Bad wBpFaced value at record: "<<i<<std::endl;
        }
        if(match.getLAce() == -1){
            std::cout<<"Bad lAce value at record: "<<i<<std::endl;
        }
        if(match.getL1stIn() == -1){
            std::cout<<"Bad l1stIn value at record: "<<i<<std::endl;
        }
        if(match.getL1stWon() == -1){
            std::cout<<"Bad l1stWon value at record: "<<i<<std::endl;
        }
        if(match.getLBpSaved() == -1){
            std::cout<<"Bad lBpSaved value at record: "<<i<<std::endl;
        }
        if(match.getLBpFaced() == -1){
            std::cout<<"Bad lBpFaced value at record: "<<i<<std::endl;
        }

        std::string tourneyName = match.getTourneyName();
        if(tourneyName.compare("INVALID") == 0){
            std::cout<<"Bad TourneyName value at record: "<<i<<std::endl;
        }

        std::string winnerName = match.getWinnerName();
        if(winnerName.compare("INVALID") == 0){
            std::cout<<"Bad WinnerName value at record: "<<i<<std::endl;
        }

        std::string loserName = match.getLoserName();
        if(loserName.compare("INVALID") == 0){
            std::cout<<"Bad LoserName value at record: "<<i<<std::endl;
        }

        std::string score = match.getScore();
        if(score.compare("INVALID") == 0){
            std::cout<<"Bad score value at record: "<<i<<std::endl;
        }

        i++;
    }
}

/**
 * This function uses assertions to test the functionality of getters and setters. Will raise exceptions
 * in the event that an assertion fails.
 */
void atpMatchTest(){

    //default constructor
    ATPMatch testMatch = ATPMatch();
    testMatch.setRowId(1);
    assert (testMatch.getRowId() == 1);
    testMatch.setTourneyDate(1);
    assert (testMatch.getTourneyDate() == 1);
    testMatch.setMinutes(1);
    assert (testMatch.getMinutes() == 1);
    testMatch.setWAce(1);
    assert (testMatch.getWAce() == 1);
    testMatch.setW1stIn(1);
    assert (testMatch.getW1stIn() == 1);
    testMatch.setW1stWon(1);
    assert (testMatch.getW1stWon() == 1);
    testMatch.setWBpSaved(1);
    assert (testMatch.getWBpSaved() == 1);
    testMatch.setWBpFaced(1);
    assert (testMatch.getWBpFaced() == 1);
    testMatch.setLAce(1);
    assert (testMatch.getLAce() == 1);
    testMatch.setL1stIn(1);
    assert (testMatch.getL1stIn() == 1);
    testMatch.setL1stWon(1);
    assert (testMatch.getL1stWon() == 1);
    testMatch.setLBpSaved(1);
    assert (testMatch.getLBpSaved() == 1);
    testMatch.setLBpFaced(1);
    assert (testMatch.getLBpFaced() == 1);
    testMatch.setTourneyName("Burlington Tennis Tourney");
    assert (testMatch.getTourneyName() == "Burlington Tennis Tourney");
    testMatch.setWinnerName("Gagnant");
    assert (testMatch.getWinnerName() == "Gagnant");
    testMatch.setLoserName("Perdant");
    assert (testMatch.getLoserName() == "Perdant");
    testMatch.setScore("7-6 7-6 7-6");
    assert (testMatch.getScore() == "7-6 7-6 7-6");

    //Constructor
    ATPMatch testMatch2 = ATPMatch(2,
                                   2022,
                                   200,
                                   1,
                                   2,
                                   3,
                                   4,
                                   5,
                                   6,
                                   7,
                                   8,
                                   9,
                                   10,
                                   "Westford",
                                   "Michael",
                                   "Other",
                                   "7-6 7-6");
    assert (testMatch2.getRowId() == 2);
    assert (testMatch2.getTourneyDate() == 2022);
    assert (testMatch2.getMinutes() == 200);
    assert (testMatch2.getWAce() == 1);
    assert (testMatch2.getW1stIn() == 2);
    assert (testMatch2.getW1stWon() == 3);
    assert (testMatch2.getWBpSaved() == 4);
    assert (testMatch2.getWBpFaced() == 5);
    assert (testMatch2.getLAce() == 6);
    assert (testMatch2.getL1stIn() == 7);
    assert (testMatch2.getL1stWon() == 8);
    assert (testMatch2.getLBpSaved() == 9);
    assert (testMatch2.getLBpFaced() == 10);
    assert (testMatch2.getTourneyName() == "Westford");
    assert (testMatch2.getWinnerName() == "Michael");
    assert (testMatch2.getLoserName() == "Other");
    assert (testMatch2.getScore() == "7-6 7-6");

}


#endif //ATPMATCH_H

