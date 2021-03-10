// Andrew Logue and Victoria (Vicky) Lopez 
//FINAL PROJECT

//include hpp files
#include "linkedList.hpp"
#include "BST.hpp"
#include "hash_C.hpp"
#include "hash_LP.hpp"
#include "hash_QP.hpp"
#include "hash_DH.hpp"
//include other
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono> 
#include <algorithm> 
#include <ctime>
using namespace std::chrono;
using namespace std; 

//initialize functions
void getTimeDataLL(float insert[], float search[], int testData[]);
void getTimeDataBST(float insert[], float search[], int testData[]);
void getTimeDataHashTableLP(float insert[], float search[], int testData[]);
void getTimeDataHashTableQP(float insert[], float search[], int testData[]);
void getTimeDataHashTableChaining(float insert[], float search[], int testData[]);
void getTimeDataHashTableDH(float insert[], float search[], int testData[]);
void readCSV(int testData[]);
void createCSV(string fileName, float insert[], float search[]);

int main() {
    //seed time
    srand(time(NULL));
    // Variable declaration:
    // int type array to store data 
    int *testData = new int[40000];
    // two float type arrays to record the time measurements 
    float *insert = new float[400];
    float *search = new float[400];
   
    //fill testData array with csv reader
    readCSV(testData);

    //check if all data points imported
    cout << "first value: " << testData[0] << " last value: " << testData[39999] << endl;

    //run getTimeData functions to fill insert and search[] arrays
    //with time to execute data
    //Linked List
    getTimeDataLL(insert, search, testData);

    //create csv file with time to execute data to be graphed in MatLab
    createCSV("TimeData_LL.csv", insert, search);

    //Binary Search Tree
    getTimeDataBST(insert, search, testData);

    //create csv file with time to execute data to be graphed in MatLab
    createCSV("TimeData_BST.csv", insert, search);

    //Hash Table - linear probing
    getTimeDataHashTableLP(insert, search, testData);

    //create csv file with time to execute data to be graphed in MatLab
    createCSV("TimeData_HTLinear.csv", insert, search);

    //Hash Table - quadratic probing
    getTimeDataHashTableQP(insert, search, testData);

    //create csv file with time to execute data to be graphed in MatLab
    createCSV("TimeData_HTQuadratic.csv", insert, search);

    //Hash Table - chaining
    getTimeDataHashTableChaining(insert, search, testData);

    //create csv file with time to execute data to be graphed in MatLab
    createCSV("TimeData_HTChaining.csv", insert, search);

    //Hash Table - double hashing
    getTimeDataHashTableDH(insert, search, testData);

    //create csv file with time to execute data to be graphed in MatLab
    createCSV("TimeData_HTDH.csv", insert, search);
    
    return 0;

}

//calculate the amount of time it takes to insert items with a HashTable with double hashing
void getTimeDataHashTableDH(float insert[], float search[], int testData[]) {
    //store time data
    float timeAVG = 0;
    //counter variable
    int counter = 0;
    //create new Hash Table class
    DoubleHash* table = new DoubleHash();
	cout << "\nGetting Hash Table with double hashing execution time data:" << endl;

    //insert the first 400 data points from testData
    for (int i = 0; i < 40000; i++) {
        //start time counter
        auto start = high_resolution_clock::now();
        table->insertDH(testData[i]);
        //stop time counter
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 
        //cout << "insertion " << testData[i] << " complete" << endl;
        //add time taken to insert data point to timeAVG
        timeAVG += duration.count();

        //every 100 insertions calculate time data
        if ((i + 1) % 100 == 0) {
            //calculate time data for Binary Search Tree insertions
            insert[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            
            //perform 100 Binary Search Tree searches
            for (int j = 0; j < 100; j++) {
                //get random index
                int index = rand() % (100 * (counter + 1));

                //search for data point given random index
                auto start = high_resolution_clock::now();
                //cout << "searching for " << testData[index] << " - " << endl;
                //cout << table->search(testData[index])->key << endl;
                table->searchDH(testData[index]);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                //add time taken to insert data point to timeAVG
                timeAVG += duration.count();

            }

            //calculate time data for Binary Search Tree searches
            search[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            counter++;
            //cout << "COUNTER" << counter << endl;

        }

    }
    cout << "DONE!" << endl;
    //table->printHashTable();
    return;
}

//calculate the amount of time it takes to insert items with a HashTable with chaining
void getTimeDataHashTableLP(float insert[], float search[], int testData[]) {
    //store time data
    float timeAVG = 0;
    //counter variable
    int counter = 0;
    //create new Hash Table class
    hashTable* table = new hashTable();
	cout << "\nGetting Hash Table with linear probing execution time data:" << endl;

    //insert the first 400 data points from testData
    for (int i = 0; i < 40000; i++) {
        //start time counter
        auto start = high_resolution_clock::now();
        table->insert(testData[i]);
        //stop time counter
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 
        //cout << "insertion " << testData[i] << " complete" << endl;
        //add time taken to insert data point to timeAVG
        timeAVG += duration.count();

        //every 100 insertions calculate time data
        if ((i + 1) % 100 == 0) {
            //calculate time data for Binary Search Tree insertions
            insert[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            
            //perform 100 Binary Search Tree searches
            for (int j = 0; j < 100; j++) {
                //get random index
                int index = rand() % (100 * (counter + 1));

                //search for data point given random index
                auto start = high_resolution_clock::now();
                //cout << "searching for " << testData[index] << " - " << endl;
                //cout << table->search(testData[index])->key << endl;
                table->search(testData[index]);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                //add time taken to insert data point to timeAVG
                timeAVG += duration.count();

            }

            //calculate time data for Binary Search Tree searches
            search[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            counter++;
            //cout << "COUNTER" << counter << endl;

        }

    }
    cout << "DONE!" << endl;
    //table->printHashTable();
    return;
}

//calculate the amount of time it takes to insert items with a HashTable with chaining
void getTimeDataHashTableQP(float insert[], float search[], int testData[]) {
    //store time data
    float timeAVG = 0;
    //counter variable
    int counter = 0;
    //create new Hash Table class
    HTable* table = new HTable();
	cout << "\nGetting Hash Table with quadratic probing execution time data:" << endl;

    //insert the first 400 data points from testData
    for (int i = 0; i < 40000; i++) {
        //start time counter
        auto start = high_resolution_clock::now();
        table->insertID(testData[i]);
        //stop time counter
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 
        //cout << "insertion " << testData[i] << " complete" << endl;
        //add time taken to insert data point to timeAVG
        timeAVG += duration.count();

        //every 100 insertions calculate time data
        if ((i + 1) % 100 == 0) {
            //calculate time data for Binary Search Tree insertions
            insert[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            
            //perform 100 Binary Search Tree searches
            for (int j = 0; j < 100; j++) {
                //get random index
                int index = rand() % (100 * (counter + 1));

                //search for data point given random index
                auto start = high_resolution_clock::now();
                //cout << "searching for " << testData[index] << " - ";
                //cout << table->searchItem(testData[index])->key << endl;
                table->searchID(testData[index]);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                //add time taken to insert data point to timeAVG
                timeAVG += duration.count();

            }

            //calculate time data for Binary Search Tree searches
            search[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            counter++;
            //cout << "COUNTER" << counter << endl;

        }

    }
    cout << "DONE!" << endl;
    //table->printHTable();
    return;
}

//calculate the amount of time it takes to insert items with a HashTable with chaining
void getTimeDataHashTableChaining(float insert[], float search[], int testData[]) {
    //store time data
    float timeAVG = 0;
    //counter variable
    int counter = 0;
    //create new Hash Table class
    HashTable* table = new HashTable();
	cout << "\nGetting Hash Table with chaining execution time data:" << endl;

    //insert the first 400 data points from testData
    for (int i = 0; i < 40000; i++) {
        //start time counter
        auto start = high_resolution_clock::now();
        table->insertItem(testData[i]);
        //stop time counter
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 
        //cout << "insertion " << testData[i] << " complete" << endl;
        //add time taken to insert data point to timeAVG
        timeAVG += duration.count();

        //every 100 insertions calculate time data
        if ((i + 1) % 100 == 0) {
            //calculate time data for Binary Search Tree insertions
            insert[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            
            //perform 100 Binary Search Tree searches
            for (int j = 0; j < 100; j++) {
                //get random index
                int index = rand() % (100 * (counter + 1));

                //search for data point given random index
                auto start = high_resolution_clock::now();
                //cout << "searching for " << testData[index] << " - ";
                //cout << table->searchItem(testData[index])->key << endl;
                table->searchItem(testData[index]);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                //add time taken to insert data point to timeAVG
                timeAVG += duration.count();

            }

            //calculate time data for Binary Search Tree searches
            search[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            counter++;
            //cout << "COUNTER" << counter << endl;

        }

    }
    //table->printTable();
    cout << "DONE!" << endl;
    return;
}

//calculate the amount of time it takes to insert items with a Linked List
void getTimeDataLL(float insert[], float search[], int testData[]) {
    //store time data
    float timeAVG = 0;
    //counter variable
    int counter = 0;
    //create new LinkList class LL
    LinkedList LL;
	cout << "\nGetting Linked List execution time data:" << endl;

    //insert the first 400 data points from testData
    for (int i = 0; i < 40000; i++) {

        //start time counter
        auto start = high_resolution_clock::now();
        LL.insertID(NULL, testData[i]);
        //stop time counter
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 
        //cout << "insertion " << testData[i] << " complete" << endl;
        //add time taken to insert data point to timeAVG
        timeAVG += duration.count();

        //every 100 insertions calculate time data
        if ((i + 1) % 100 == 0) {
            //calculate time data for Linked List insertions
            insert[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            
            //perform 100 Linked List searches
            for (int j = 0; j < 100; j++) {
                //get random index
                int index = rand() % (100 * (counter + 1));

                //search for data point given random index
                auto start = high_resolution_clock::now();
                //cout << "searching for " << testData[index] << " - ";
                //cout << LL.searchID(testData[index])->key << endl;
                LL.searchID(testData[index]);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                //add time taken to insert data point to timeAVG
                timeAVG += duration.count();

            }

            //calculate time data for Linked List searches
            search[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            counter++;
            //cout << "COUNTER" << counter << endl;

        }

    }
    cout << "DONE!" << endl;
    return;
}

//calculate the amount of time it takes to insert items with a Binary Search Tree
void getTimeDataBST(float insert[], float search[], int testData[]) {
    //store time data
    float timeAVG = 0;
    //counter variable
    int counter = 0;
    //create new Binary Search Tree class
    BST* tree = new BST();
	cout << "\nGetting Binary Search Tree execution time data:" << endl;

    //insert the first 400 data points from testData
    for (int i = 0; i < 40000; i++) {
        //start time counter
        auto start = high_resolution_clock::now();
        tree->insertID(testData[i]);
        //stop time counter
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 
        //cout << "insertion " << testData[i] << " complete" << endl;
        //add time taken to insert data point to timeAVG
        timeAVG += duration.count();

        //every 100 insertions calculate time data
        if ((i + 1) % 100 == 0) {
            //calculate time data for Binary Search Tree insertions
            insert[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            
            //perform 100 Binary Search Tree searches
            for (int j = 0; j < 100; j++) {
                //get random index
                int index = rand() % (100 * (counter + 1));

                //search for data point given random index
                auto start = high_resolution_clock::now();
                //cout << "searching for " << testData[index] << " - ";
                //cout << tree->searchTrackingID(testData[index])->key << endl;
                tree->searchTrackingID(testData[index]);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                //add time taken to insert data point to timeAVG
                timeAVG += duration.count();

            }

            //calculate time data for Binary Search Tree searches
            search[counter] = timeAVG / 100.0;
            timeAVG = 0.0;
            counter++;
            //cout << "COUNTER" << counter << endl;

        }

    }
    cout << "DONE!" << endl;
    return;
}

//read csv file
void readCSV(int testData[]) {
    //length : Number of items currently stored in the array
    int length = 0;
    //other variables
    string data;
    char seperator = ',';
    string fileName;
    ifstream inFile;

    cout << "Enter the name of the file to test: " << endl;
    cin >> fileName;
    inFile.open(fileName);

    //if file name not found terminate program
    if (!inFile) {
        cout << "failed to open the file" << endl;
        return;

    }

    while (getline(inFile, data, seperator)) {
        testData[length] = stoi(data);
        length++;
        
    }

    inFile.close();
    return;

}

//create csv file with time to execute data to be graphed in MatLab
void createCSV(string fileName, float insert[], float search[]) {
    ofstream outFile;
    outFile.open(fileName);
    outFile << "Insert,Search\n";

    //write data stored in search and insert arrays to time data cvs file
    for (int k = 0; k < 400; k++) {
        outFile << insert[k] << "," << search[k] << "\n";

    }

    outFile.close();
    return;

}
