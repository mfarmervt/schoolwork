#ifndef HASHING_OPENADDRESSING_H
#define HASHING_OPENADDRESSING_H

#include <functional>
#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <vector>
using std::cout, std::endl, std::function, std::nullopt, std::optional, std::string, std::vector, std::fstream;

template<typename Keyable>
class ExponentialProbing {
private:
    enum state {EMPTY, FILLED, REMOVED};
    struct hashable {
        Keyable item;
        state status;
    };
    vector<hashable> table;
    unsigned long tableSize;
    function<string(Keyable)> getKey;
    unsigned long numItems;

    unsigned long hornerHash(string key) const {
        unsigned long hashVal = 0;
        for (char letter : key) {
            hashVal = hashVal * 37 + letter;
        }
        return hashVal % tableSize;
    }

    // Find the next prime number
    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

    void rehash(int& reads) {
        // Store a copy of the hash table
        vector<hashable> oldTable = table;
        tableSize = nextPrime(tableSize * 2);
        // Empty the table
        table.clear();
        numItems = 0;

        table.resize(tableSize);

        // Reinsert all FILLED items
        for (int i = 0; i < oldTable.size(); ++i) {
            if (oldTable[i].status == FILLED) {
                insert(oldTable[i].item, reads);
            }
        }

    }

public:
    // Constructor
    ExponentialProbing(unsigned long tableSize, function<string(Keyable)> getKey) {
        // This will fill the table with default Keyables and EMPTY statuses
        this->tableSize = nextPrime(tableSize);
        table.resize(this->tableSize);
        this->getKey = getKey;
        numItems = 0;
    }

    // Insert
    void insert(Keyable item, int& reads) {
        int twoPowers = 2;
        reads = 0;
        // Get the key from the item
        string key = getKey(item);
        if (!find(key, reads)) {
            // Hash the key to get an index
            unsigned long index = hornerHash(key);
            // Probe until we find a non-filled index
            while (table[index].status == FILLED) {
                //
                index += twoPowers;
                index %= tableSize;
                twoPowers *=2;

            }
            table[index].item = item;
            if (table[index].status == EMPTY) {
                ++numItems;
                table[index].status = FILLED;
                // Rehash when more than half the table is filled
                if (numItems > tableSize/2) {
                    rehash(reads);
                }
            } else {
                table[index].status = FILLED;
            }
        }
    }


    // Find
    optional<Keyable> find(string key, int& reads) const {
        int twoPowers = 2;
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        while (table[index].status != EMPTY) {
            // Check the index to see if the key matches
            reads++;
            if (table[index].status == FILLED && getKey(table[index].item) == key) {
                // We found the item
                reads++;
                return table[index].item;
            }
            // Double the index for exponential probing
            index += twoPowers;
            index %= tableSize;
            twoPowers *= 2;
        }
        // We didn't find the item
        return nullopt;
    }

    // Remove
    bool remove(string key, int& reads) {
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        while (table[index].status != EMPTY) {
            // Check the index to see if the key matches
            if (table[index].status == FILLED && getKey(table[index].item) == key) {
                // We found the item
                // Remove it
                table[index].status = REMOVED;
                table[index].item = Keyable();
                return true;
            }
            // Double the index for exponential probing
            index *= 2;
            index %= tableSize;
        }
        // We didn't find the item
        return false;
    }

    // Print the table
    void printTable() const {
        cout << "Beginning of table" << endl;
        for (unsigned long i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            if (table[i].status == FILLED) {
                cout << table[i].item;
            } else if (table[i].status == REMOVED) {
                cout << "X";
            }
            cout << endl;
        }
        cout << "End of table" << endl;
    }

    int getTableSize(){
        return tableSize;
    }

    //Calculate average reads
    double calculateAverageReads(string fileName, int inputSize){
        int sum = 0;
        int line;
        fstream newFile;
        newFile.open(fileName);
        if(!newFile.is_open()){
            cout<<"Could not open file"<<endl;
        }

        while(!newFile.eof()){
            newFile >> line;
            sum += line;
        }

        return (double)sum/inputSize;

    }
};


#endif
