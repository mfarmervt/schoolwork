//
// Created by Michael Farmer on 9/12/22.
///

#ifndef ATPMATCH_H
#define ATPMATCH_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

//define class
class ATPMatch {

    //Which attributes to include in vector?
        //winner name, loser name, tourney name, match date, score, wbpsaved, wbpfaced, lbpsaved, lbpfaced
        //w1stwon, l1stwon, wAce, lAce.

    //The rest should be filtered out and put into garbage variables. fsd

private:
    int rowID, tourneyDate, minutes, wAce, w1stIn, w1stWon, wBpSaved, wBpFaced, lAce,
        l1stIn, l1stWon, lBpSaved, lBpFaced;
    std::string tourneyName, winnerName, loserName, score;

public:
    //constructors.  Empty and with fields
    ATPMatch(){
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
             std::string score){

        this-> rowID = rowID;
        this-> tourneyDate = tourneyDate;
        this-> minutes = minutes;
        this-> wAce = wAce;
        this-> w1stIn = w1stIn;
        this-> w1stWon = w1stWon;
        this-> wBpSaved = wBpFaced;
        this-> wBpFaced = wBpFaced;
        this-> lAce = lAce;
        this-> l1stIn = l1stIn;
        this-> l1stWon = l1stWon;
        this-> lBpSaved = lBpSaved;
        this-> lBpFaced = lBpFaced;
        this-> tourneyName = tourneyName;
        this-> winnerName = winnerName;
        this-> loserName = loserName;
        this-> score = score;
    }

    //getters
    int getrowId() const{
        return rowID;
    }

    int getTourneyDate() const {
        return tourneyDate;
    }

    int getMinutes() const{
        return minutes;
    }

    int getWAce() const{
        return wAce;
    }

    int getW1stIn() const{
        return w1stIn;
    }

    int getW1stWon() const{
        return w1stWon;
    }

    int getWBpSaved() const{
        return wBpSaved;
    }

    int getWBpFaced() const{
        return wBpFaced;
    }

    int getLAce() const{
        return lAce;
    }

    int getL1stIn() const{
        return l1stIn;
    }

    int getL1stWon() const{
        return l1stWon;
    }

    int getLBpSaved() const{
        return lBpSaved;
    }

    int getLBpFaced() const{
        return lBpFaced;
    }

    std::string getTourneyName() const{
        return tourneyName;
    }

    std::string getWinnerName() const{
        return winnerName;
    }

    std::string getLoserName() const{
        return loserName;
    }

    std::string getScore() const{
        return score;
    }

    void setRowId(int rowId){
        this-> rowID = rowID;
    }

    void setTourneyDate(int tourneyDate){
        this-> tourneyDate = tourneyDate;
    }

    void setMinutes(int minutes){
        this-> minutes = minutes;
    }

    void setWAce(int wAce){
        this-> wAce = wAce;
    }

    void setW1stIn(int w1stIn){
        this-> w1stIn = w1stIn;
    }

    void setW1stWon(int w1stWon){
        this-> w1stWon = w1stWon;
    }

    void setWBpSaved(int wBpSaved){
        this-> wBpSaved = wBpSaved;
    }

    void setWBpFaced(int wBpFaced){
        this-> wBpFaced = wBpFaced;
    }

    void setLAce(int lAce){
        this-> lAce = lAce;
    }

    void setL1stIn(int l1stIn){
        this-> l1stIn = l1stIn;
    }

    void setLBpSaved(int lBpSaved){
        this-> lBpSaved = lBpSaved;
    }

    void setLBpFaced(int lBpFaced){
        this-> lBpFaced = lBpFaced;
    }

    void setTourneyName(std::string tourneyName){
        this-> tourneyName = tourneyName;
    }

    void setWinnerName(std::string winnerName){
        this-> winnerName = winnerName;
    }

    void setLoserName(std::string loserName){
        this-> loserName = loserName;
    }

    void setScore(std::string score) {
        this->score = score;
    }

    //load data from file into ATPMatch vector
    bool loadFromFile(std::string fileName, std::vector<ATPMatch> &objs) {

        std::ifstream fin;
        fin.open(fileName);

        //if file can't be opened
        if(!fin){
            return false;
        }

        //If file is good.

        //Remove header
        std::string header = "";
        getline(fin, header);

        //while loop to loop through the file and populate vector of ATPMatches
        int counter = 0;  //will be used to create rowID.
        while(fin && fin.peek() != EOF){

            char comma = ',';

            //need a variable to handle garbage variables.
            std::string garbage;

            //using counter to create rowID attribute
            rowID = counter;

            //Assign values to fields

            //NEED TO ADD CONDITIONALS FOR EVERY FIELD BECAUSE THERE ARE SECTIONS OF CODE THAT ARE BLANK

            //Garbage attributes
            getline(fin, garbage, comma); //tourneyID
            getline(fin, tourneyName, comma); //tourneyName
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
            fin>>comma;

            //Winner aces
            fin>>wAce;
            fin>>comma;

            //Garbage
            getline(fin, garbage, comma); //wdf update
            getline(fin, garbage, comma); //wsvpt

            //Winner 1st.
            fin>>w1stIn;
            fin>>comma;

            //Winner 1st won
            fin>>w1stWon;
            fin>>comma;

            //Garbage
            getline(fin, garbage, comma); //w2ndwon
            getline(fin, garbage, comma); //wsvgms

            //Winner BP saved
            fin>>wBpSaved;
            fin>>comma;

            //Winner BP faced
            fin>>wBpFaced;
            fin>>comma;

            //Loser Ace
            fin>>lAce;
            fin>>comma;

            //Garbage
            getline(fin, garbage, comma); //ldf
            getline(fin, garbage, comma); //lsvpt

            //Loser 1st In
            fin>>l1stIn;
            fin>>comma;

            //Loser 1st Won
            fin>>l1stWon;
            fin>>comma;

            //Garbage
            getline(fin, garbage, comma); //l2ndwon
            getline(fin, garbage, comma); //lsvgms

            //Loser BP Saved y
            fin>>lBpSaved;
            fin>>comma;

            //Loser BP faced
            fin>>lBpFaced;
            fin>>comma;

            //Garbage
            getline(fin, garbage, comma);
            getline(fin, garbage, comma);
            getline(fin, garbage, comma);
            getline(fin, garbage, comma);

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
            counter++;
        }
        return true;
        fin.close();
    }

    //Computation: difference in Winner BP save percentage to Loser BP save percentage
        //Would have to find average BP save percentage for both winners and loser
        //Loop through vector, average of getWBpSaved, average of getWBpFaced.  Find difference




    //an ATPMatch will have private fields for
    //unique_id, tourney_id, tourney_name, surface, draw_size, tourney_level, tourney_date match_num, winner_id, winner_seed
    //winner_entry, winner_name, winner_hand, winner_ht, winner_ioc, winner_age, loser_id, loser_seed, loser_entry,
    //loser_name, loser_hand, loser_ht, loser_ioc, loser_age, score, best_of, round, minutes, w_ace, w_df, w_svpt,
    //w_1stIn, w_1stWon, w_2ndWon, w_SvGms, w_bpSaved, w_bpFaced, l_ace, l_df, l_svpt, l_1stIn, l_1stWon, l_2ndWon,
    //l_SvGms, l_bpSaved, l_bpFaced, winner_rank, winner_rank_points, loser_rank, loser_rank_points
    //public constructors
    //empty ATPMatch(){}
    //ATPMatch containing all field values

    //getters for every field

    //setters for every field

    //bool function for loading file into vector<ATPMatch>
    //needs to open the file

    //check if the file is valid/can be opened

    //delete header
    //std::string header = "";
    //getline(fin, header);

    //read line by line (using while loop)
    //each attribute should be assigned to its respective field value in the constructor
};

#endif //ATPMATCH_H

