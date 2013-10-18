#ifndef FLIGHTREQUESTLOADER_H
#define FLIGHTREQUESTLOADER_H

#include <vector>
#include "flight.h"

// default file name
static const std::string FLIGHTREQUESTDATA = "flightrequestData.txt";

class flightRequestLoader{
private:

        std::vector<flight> flightRequests;
        std::string filename;
public:
        flightRequestLoader(void);

        ~flightRequestLoader(void);
        std::vector<flight> * getFlights(void);

        void writeFile(std::string);
        void writeFile();

};

#endif // FLIGHTREQUESTLOADER_H
