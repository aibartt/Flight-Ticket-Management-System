#ifndef HASHTABLE_FLIGHTHASHTABLE_H
#define HASHTABLE_FLIGHTHASHTABLE_H

#include <iostream>
#include "flightticket.h"
#include <fstream>
#include <sstream>
#include <time.h>
#include <math.h>

#include <vector>
#include <list>
// include additional header files if needed
using namespace std;

class HashNode
{
private:
    string key; // key = companyName+flightNumber
    Flight_Ticket value;
public:
    HashNode(string &key, Flight_Ticket &value) : key(key), value(value) {}
    friend class FlightHASHTABLE;
};

//=============================================================================
class FlightHASHTABLE
{
private:
    list <HashNode> *buckets;				//List of Buckets, Please create your own List Class called MyList
    int size;					    //Current Size of HashTable
    int capacity;				    // Total Capacity of HashTable
    // add more attributes needed
public:
    FlightHASHTABLE();						//constructor
    ~FlightHASHTABLE();						//destructor
    long hashCode(); 						//implement and test different hash functions
    int importCSV(string &path); 			//Load all the flight-tickets from the CSV file to the HashTable
    int exportCSV(string &path); 			//Export all the flight-tickets from the HashTable to a CSV file in an ascending order
    int count_collisions();  //return the number of collisions on the HashTable
    bool search_duplicate(list <HashNode> &p, HashNode *new_record);
    int add(Flight_Ticket* data);			//add new flight to the HashTable
    void removeRecord (string &companyName, int flightNumber);	//Delete a record with key from the hashtable
    void find(string &companyName, int flightNumber);		//Find and Display records with same key entered
    void allinday(string &date);  					//Find and Display records with same day entered
    void printASC(string &companyName, int flightNumber);  		//display the collisions for the entered key in an ascending order
    unsigned long hashCode(string &key); //Add more methods and contructors, destructors if needed
};


#endif //HASHTABLE_FLIGHTHASHTABLE_H
