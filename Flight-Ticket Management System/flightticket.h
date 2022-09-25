#ifndef HASHTABLE_FLIGHTTICKET_H
#define HASHTABLE_FLIGHTTICKET_H

#include<iostream>
using namespace std;

class Flight_Ticket
{
private:
    string companyName;
    int flightNumber;
    string country_of_origin;
    string country_of_destination;
    string stopOver;
    string price;
    string time_of_departure;
    string time_of_arrival;
    string date;

public:
    friend class FlightHASHTABLE;
    Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination,
                  string stopOver, string price, string time_of_departure, string time_of_arrival, string date);
    Flight_Ticket();
    // Please add additional methods, contructor if needed
};

#endif //HASHTABLE_FLIGHTTICKET_H
