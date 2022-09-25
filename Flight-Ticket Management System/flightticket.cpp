#include "flightticket.h"

Flight_Ticket::Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination,
        string stopOver, string price, string time_of_departure, string time_of_arrival, string date) :
        companyName(companyName), flightNumber(flightNumber), country_of_origin(country_of_origin),
        country_of_destination(country_of_destination), stopOver(stopOver), price(price),
        time_of_departure(time_of_departure), time_of_arrival(time_of_arrival), date(date) {}

Flight_Ticket::Flight_Ticket() {}