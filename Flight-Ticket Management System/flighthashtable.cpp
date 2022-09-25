#include "flighthashtable.h"

//HashFunctions #1
//FlightHASHTABLE::FlightHASHTABLE() {
//    buckets = new list<HashNode>[24851];	  //Array of a list/chain
//    this->capacity = 24851;
//    this->size = 0;
//}
//
//unsigned long FlightHASHTABLE::hashCode(string &key)
//{
//    int m = key.length();
//    unsigned int h = 0;
//    for (int i = 0; i < m; i++)
//    {
//        h = (h << 5) | (h >> 27);
//        h += (unsigned int) key[i];
//    }
//    return h % capacity;// make sure that the hashcode is in the range 0 - N-1;
//}
//

////HashFunction #2
//unsigned long hashCode(const string key)//Create Hashcode for key
//{
//    unsigned long int word = 0;
//    for (int i =0; i < key.size(); i++){
//        word += int(key[i])*pow(151,i);
//    }
//    return (word%capacity);
//}
//

//HashFunction #3
//unsigned long hashCode(const string key)//Create Hashcode for key
//{
//    unsigned long int word = 0;
//    for (int i =0; i < key.size(); i++){
//        word += int(key[i])*pow(5,i); // hash code formula
//    }
//    return (word%capacity);
//}


FlightHASHTABLE::FlightHASHTABLE() {
    buckets = new list<HashNode>[24851];	  //Array of a list/chain
    this->capacity = 24851;
    this->size = 0;
}

FlightHASHTABLE::~FlightHASHTABLE() {
    delete []buckets;
}
//Imports a CSV file //Invokes a function with the following header:
int FlightHASHTABLE::importCSV(string &path) { 
    std::ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        return -1;  //The function either returns the number of flight-tickets read from the file as integer or returns -1, if a bad path is provided.
    } else {
        int count = 0;
        string line;
        getline(fin, line, '\n');
        while (fin.good()) { //This function takes the path as an argument and loads all the flight-tickets from the CSV file into the Hash Table.
            string companyName;
            int flightNumber;
            string _flightNumber;
            string country_of_origin;
            string country_of_destination;
            string stopOver;
            string price;
            string time_of_departure;
            string time_of_arrival;
            string date;
            getline(fin, companyName, ',');
            getline(fin, _flightNumber, ',');
            getline(fin, country_of_origin, ',');
            getline(fin, country_of_destination, ',');
            getline(fin, stopOver, ',');
            getline(fin, price, ',');
            getline(fin, time_of_departure, ',');
            getline(fin, time_of_arrival, ',');
            getline(fin, date, '\r');
            getline(fin, line, '\n');
            if (companyName.size() == 0 && _flightNumber.size() == 0) {
                break;
            }
            flightNumber = stoi(_flightNumber);
            Flight_Ticket *data = new Flight_Ticket(companyName, flightNumber, country_of_origin, country_of_destination,
                                                    stopOver, price, time_of_departure, time_of_arrival, date);
            string key = companyName + to_string(flightNumber);
            int index = hashCode(key);
            buckets[index].push_back(HashNode(key, *data));
            count++; size++;
        }
        return count; //The function either returns the number of flight-tickets read from the file as integer or returns -1, if a bad path is provided.
    }
}

//Exports a CSV file/ Invokes a function with the following header:
int FlightHASHTABLE::exportCSV(string &path) {
    std::ofstream ref_file;
    ref_file.open(path);
    if (!ref_file.is_open()) { //This function takes the path as an argument and writes all the flight-tickets from the Hash Table to a CSV file.
        return -1;     //The function either returns the number of flight-tickets written to the file as integer or returns -1, if file cannot be created
    } else {
        int count = 0;
        ref_file << "companyName,flightNumber,country-of-origin,country-of-destination,stopver,price,time-of-departure,time-of-arrival,date" << endl;
        for (size_t i = 0; i < capacity; i++) {
            for(list<HashNode>::iterator it = buckets[i].begin(); it != buckets[i].end(); ++it) {
                    ref_file << it->value.companyName << ',' << it->value.flightNumber << ',' << it->value.country_of_origin
                             << ',' << it->value.country_of_destination << ',' << it->value.stopOver << ',' << it->value.price << ','
                             << it->value.time_of_departure << ',' << it->value.time_of_arrival << ',' << it->value.date << endl;
                count++;
            }
        }
        ref_file.close();
        return count; //The function either returns the number of flight-tickets written to the file as integer or returns -1, if file cannot be created
    }
}

unsigned long FlightHASHTABLE::hashCode(string &key) {
    int m = key.length();
    unsigned int h = 0;
    for (int i = 0; i < m; i++)
    {
        h = (h << 5) | (h >> 27);
        h += (unsigned int) key[i];
    }
    return h % capacity;// make sure that the hashcode is in the range 0 - N-1;
}
//searching for duplicate records
bool FlightHASHTABLE::search_duplicate(list <HashNode> &p, HashNode *new_record) {
    for (list <HashNode>::iterator it = p.begin(); it != p.end(); it++) {
        if (it->value.companyName == new_record->value.companyName &&
            it->value.flightNumber == new_record->value.flightNumber &&
            it->value.country_of_origin == new_record->value.country_of_origin &&
            it->value.country_of_destination == new_record->value.country_of_destination &&
            it->value.stopOver == new_record->value.stopOver &&
            it->value.price == new_record->value.price &&
            it->value.time_of_departure == new_record->value.time_of_departure &&
            it->value.time_of_arrival == new_record->value.time_of_arrival &&
            it->value.date == new_record->value.date) {
            return false;
        }
    }
    return true;
}
//Adds a new flight record.
int FlightHASHTABLE::add(Flight_Ticket* data) {
    cout << "Please enter the details if the flight-ticket: " << endl;
    cout << "Company Name: "; getline(cin, data->companyName);
    cin.clear();
    cout << "Flight Number: "; cin >> data->flightNumber;
    cout << "Country of Origin: "; cin >> data ->country_of_origin;
    cout << "Country of Destination: "; cin >> data->country_of_destination;  //If the element already exists, no entry will be added, but a warning message will be issued stating that the record already exists the system.
    cout << "Stopover: "; cin >> data->stopOver;
    cout << "Price: "; cin >> data->price;
    cout << "Time of Departure: "; cin >> data->time_of_departure;
    cout << "Time of Arrival: "; cin >> data->time_of_arrival;
    cout << "Date: "; cin >> data->date;
    string key = data->companyName + to_string(data->flightNumber);
    HashNode *new_record = new HashNode(key, *data);
    int index = hashCode(key); //Find the bucket index where the new node will fall, make sure that the index is within the bounds of array
    if (search_duplicate(buckets[index], new_record)) {
        buckets[index].push_back(*new_record);
        this->size++; //Increate number of elements in the array
        cout << "Flight-ticket has been successfully added!" << endl;
        return 1;  //This function takes a pointer to a FlightInfo object as an argument. The function returns 1 if the record has been successfully added or -1 otherwise.
    } else {
        cout << "This record already exists in the system!" << endl;
        return -1; //This function takes a pointer to a FlightInfo object as an argument. The function returns 1 if the record has been successfully added or -1 otherwise.
    }
}
//Returns the number of collisions caused by a hash function.
int FlightHASHTABLE::count_collisions() {
    int count = 0;  //Thisfunctiondoesn’tacceptanyparameters.Itshouldoperatebasedontheexistinghash table.
    for (size_t i = 0; i < capacity; i++) {
        if (buckets[i].size() > 1) {
            count += buckets[i].size() - 1;
        }
    }
    return count/10;  //This method returns the number of collisions in the hash table.
}
//Deletesaflight-ticketrecordbasedontheenteredkey<companyName,flightNumber>.
void FlightHASHTABLE::removeRecord (string &companyName, int flightNumber) {
    string key = companyName + to_string(flightNumber);
    int index = hashCode(key);
    if (buckets[index].empty()) {
        cout << "No flight record found" << endl;  //If no such entry exists, a warning message to the standard error is printed out.
        return;
    }
    cout << buckets[index].size() << " records found: " << endl;
    size_t count = 1;
    for(list <HashNode>::iterator it = buckets[index].begin(); it != buckets[index].end(); ++it) {
        if (it->value.companyName == companyName && it->value.flightNumber == flightNumber) {
            cout << count << ". " << it->value.companyName << "," << it->value.flightNumber << ","
                 << it->value.country_of_origin
                 << "," << it->value.country_of_destination << "," << it->value.stopOver << "," << it->value.price
                 << ","
                 << it->value.time_of_departure << "," << it->value.time_of_arrival << "," << it->value.date << " "
                 << endl;
            count++;
        }
    } cout << endl;
    int key_menu;
    cout << "Please select the record you want to delete: " << endl;
    cin >> key_menu;
    while (key_menu < 1 || key_menu > count) {
        cin >> key_menu;
    }
    list <HashNode>::iterator it = buckets[index].begin();
    key_menu--;
    while (key_menu) {
        if (it->value.companyName == companyName && it->value.flightNumber == flightNumber) {
            key_menu--;
        }
        it++;
    }
    buckets[index].erase(it);
    cout << "The flight-ticket record has been successfully deleted!" << endl; // It prints confirmation message if the record has been successfully added or failure message otherwise.
}
//Searchesforaflight-ticketrecordoftheenteredkey<companyName,flightNumber>.
void FlightHASHTABLE::find(string &companyName, int flightNumber) { 
    clock_t start = clock();
    string key = companyName + to_string(flightNumber);
    int index = hashCode(key);
    if (buckets[index].empty()) {
        cout << "Not found" << endl;  //This function takes a key (i.e., companyName and flightNumber) as an argument and displays the entire records that match the entered key or displays “Not Found!” message otherwise.
        return;
    }
    cout << buckets[index].size() << " records found: " << endl;
    size_t count = 1;
    for(list <HashNode>::iterator it = buckets[index].begin(); it != buckets[index].end(); ++it) {
        if (it->value.companyName == companyName && it->value.flightNumber == flightNumber) {
            cout << endl << count << ". ";
            cout << "   Company Name: " << it->value.companyName << endl;
            cout << "   Flight Number: " << it->value.flightNumber << endl;
            cout << "   Country of Origin: " << it->value.country_of_origin << endl;
            cout << "   Country of Destination: " << it->value.country_of_destination << endl;
            cout << "   Stopover: " << it->value.stopOver << endl;
            cout << "   Price: " << it->value.price << endl;
            cout << "   Time of Departure: " << it->value.time_of_departure << endl;
            cout << "   Time of Arrival: " << it->value.time_of_arrival << endl;
            cout << "   Date: " << it->value.date << endl;
            count++;
        }
    } cout << endl;
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time Taken: " << seconds << "seconds" << endl; // It also prints out the actual time taken by the find execution.
}

//SearchesforalltheFlight-ticketsforaspecifieddate.
void FlightHASHTABLE::allinday(string &date) {
    size_t count = 1; //This function takes a specific date as an argument and prints out all the flight-tickets available for that date or display “Not Found!” message otherwise.
    for (size_t i = 0; i < capacity; i++) {
            for (list <HashNode>::iterator it = buckets[i].begin(); it != buckets[i].end(); ++it) {
                if (it->value.date == date) {
                    cout << count << ". " << it->value.companyName << "," << it->value.flightNumber << "," << it->value.country_of_origin
                         << "," << it->value.country_of_destination << "," << it->value.stopOver << "," << it->value.price << ","
                         << it->value.time_of_departure << "," << it->value.time_of_arrival << "," << it->value.date
                         << endl;
                    count++;
                }
            }
    }
}
//Displays in an ascending order (based on the flight destination country) all flight-tickets having the same key entered by the user <companyName,flightNumber>.
void FlightHASHTABLE::printASC(string &companyName, int flightNumber) {
    vector <Flight_Ticket> buckets_key;
    string key = companyName + to_string(flightNumber);
    int index = hashCode(key);
    for (list <HashNode>::iterator it = buckets[index].begin(); it != buckets[index].end(); ++it) {
        if (it->value.companyName == companyName && it->value.flightNumber == flightNumber) {
            buckets_key.push_back(it->value);
        }
    } //Displays in an ascending order (based on the flight destination country) all flight-tickets having the same key entered by the user <companyName,flightNumber>.
    for (size_t i = 0 ; i + 1 < buckets_key.size(); i++) {
        for (size_t j = 0; j + 1 + i < buckets_key.size(); j++) {
            if (buckets_key[j].country_of_destination > buckets_key[j + 1].country_of_destination) {
                Flight_Ticket temp = buckets_key[j];
                buckets_key[j] = buckets_key[j + 1];
                buckets_key[j + 1] = temp;
            }
        }
    }
    cout << buckets_key.size() << " records found:" << endl;
    for (size_t i = 0; i < buckets_key.size(); i++) {
        cout << i + 1 << ". " << buckets_key[i].companyName << "," << buckets_key[i].flightNumber << "," << buckets_key[i].country_of_origin
             << "," << buckets_key[i].country_of_destination << "," << buckets_key[i].stopOver << "," << buckets_key[i].price << ","
             << buckets_key[i].time_of_departure << "," << buckets_key[i].time_of_arrival << "," << buckets_key[i].date << endl;
    }
}
