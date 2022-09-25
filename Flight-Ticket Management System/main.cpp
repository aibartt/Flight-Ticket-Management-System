
//=================================================================================
// Name         : DS Assignment#4 
// Author       : Aibar Talip
// Version      : 1.0
// Date Created : 00-00-2022
// Date Modified: 
// Description  : Starter Code for Contact Travel Management System using HASH TABLE in C++
//=================================================================================
#include<iostream>
#include<cstdlib>
#include<sstream>

#include "flightticket.h"
#include "flighthashtable.h"
//Through its prompt, the program is expected to accept several commands that we outline next;
//==========================================================
void listCommands()
{
	cout<<"\n----------------------------------"<<endl;
	cout<<"import <path>      	:Import flight-tickets from a CSV file"<<endl 
		<<"export <path>      	:Export flight-tickets to a CSV file"<<endl
		<<"count_collisions   	:Print Number of Collisions"<<endl
		<<"add                	:Add a new flight-ticket"<<endl
		<<"delete <key>       	:Delete a flight-ticket"<<endl
		<<"find <key>         	:Find a flight-ticket's details"<<endl
		<<"allinday <date>    	:Display all flight-tickets in a day"<<endl
		<<"printASC <key>     	:Print flight-tickets in ascending order"<<endl
		<<"exit               	:Exit the program"<<endl;
}
//==========================================================

bool search_for_errors(const string &str) {
    if (str.empty()) {
        cout << "Error key!!!" << endl;
        return false;
    }
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            cout << "Error key!!!" << endl;
            return false;
        }
    }
    return true;
}
//Through its prompt, the program is expected to accept several commands that we outline next;
//==========================================================
int main(void) {
	FlightHASHTABLE myFlightHASHTABLE;
    string user_input;
    string command;
    string key;
	while(true) {
        string p = "\r"; //these commands accept as operand a string that provides a flight-ticket’s data, or the combination of companyName and flightNumber used as the key to look up records.
        listCommands();
        cout << ">";
        getline(cin,user_input);
        stringstream sstr(user_input);
        getline(sstr,command,' ');
        getline(sstr,key);
        if (command == "import") {
            cout << myFlightHASHTABLE.importCSV(key) << " imported!" << endl; //The application interacts with the user using a command line (terminal based) interface as shown below:
        } else if (command == "export") {
            cout << myFlightHASHTABLE.exportCSV(key) << " exported!" << endl;
        } else if (command == "count_collisions") {
            cout << "Total Number of collisions: " << myFlightHASHTABLE.count_collisions() << endl;
        } else if (command == "add") {
            myFlightHASHTABLE.add(new Flight_Ticket());
        } else if (command == "delete") {
            string companyName;
            string _flightNumber;
            int flightNumber;
            size_t i = 0;
            while (i < key.size() && key[i] != ',') {
                companyName.push_back(key[i]);
                i++;
            } i++;
            while (i < key.size()) {
                _flightNumber.push_back(key[i]);
                i++;
            }
            if (search_for_errors(_flightNumber)) {
                flightNumber = stoi(_flightNumber);
                myFlightHASHTABLE.removeRecord(companyName, flightNumber);
            }
        } else if (command == "find") {
            string companyName;
            string _flightNumber;
            int flightNumber;
            size_t i = 0;
            while (i < key.size() && key[i] != ',') {
                companyName.push_back(key[i]);
                i++;
            } i++;
            while (i < key.size()) {
                _flightNumber.push_back(key[i]);
                i++;
            }
            if (search_for_errors(_flightNumber)) {
                flightNumber = stoi(_flightNumber);
                myFlightHASHTABLE.find(companyName, flightNumber);
            }
        } else if (command == "allinday") {
            myFlightHASHTABLE.allinday(key);
        } else if (command == "printASC") {
            string companyName;
            string _flightNumber;
            int flightNumber;
            size_t i = 0;
            while (i < key.size() && key[i] != ',') {
                companyName.push_back(key[i]);
                i++;
            } i++;
            while (i < key.size()) {
                _flightNumber.push_back(key[i]);
                i++;
            }
            if (search_for_errors(_flightNumber)) {
                flightNumber = stoi(_flightNumber);
                myFlightHASHTABLE.printASC(companyName, flightNumber);
            }
        } else if (command == "exit") {
            break;
        }
    }
	return 0;
}
