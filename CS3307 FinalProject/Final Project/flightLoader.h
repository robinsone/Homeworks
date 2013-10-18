#ifndef flightLoader_H
#define flightLoader_H
#include <vector>
#include "flight.h"

static const std::string FLIGHTDATA = "flightData.txt";

class flightLoader{
private:

        std::vector<flight> arrivalVector;
        std::vector<flight> departureVector;
	std::string filename;

public:
	flightLoader(void);

	~flightLoader(void);
        std::vector<flight> * getArrival(void);
        std::vector<flight> * getDeparture(void);

        void writeFile(std::string);
        void writeFile();
        flight * findByFlightID(int id);

};


#endif
