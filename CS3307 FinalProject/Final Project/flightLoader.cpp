#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <QDate>
#include "flightLoader.h"
#include "flight.h"


using namespace std;

// comparing which flight as earlier landing time
bool sortPred(flight d1, flight d2){
    return d1.getLandTimeMins() < d2.getLandTimeMins();
}

// the constructor for the flight loader
flightLoader::flightLoader(){
        // assume that the airport that is using this system is London, Ontario
        const string AIRPORT_CODE = "YXU";

	string line;
	
        ifstream infile (FLIGHTDATA.c_str());

	if (infile.is_open()){
		while ( infile.good() ){
			if(infile.eof()) break;
			getline (infile,line);

                        string _flightID, _airCraftID, _airLineID, _sCode, _source, _dCode, _destination, _gateTime, _landTime, _delay, _scheduleType, _date, _dayOfWeek;
                        int fID, acID, gTime, lTime, del, schedule, dOfWeek;
			istringstream iss(line);
                        getline(iss, _flightID, '_');   // flight id
                        getline(iss, _airCraftID, '_'); // aircraft id
                        getline(iss, _airLineID, '_');  // airline id
                        getline(iss, _sCode, '_');      // source id code
                        getline(iss, _source, '_');     // source in long form
                        getline(iss, _dCode, '_');      // destination code
                        getline(iss, _destination, '_');// destination in long form
                        getline(iss, _gateTime, '_');   // the gate time
                        getline(iss, _landTime, '_');   // the land time
                        getline(iss, _delay, '_');      // how long the delay is
                        getline(iss, _scheduleType, '_');// 0=one time; 1=daily; 2=weekly
                        getline(iss, _date, '_');       // the date of the flight if one time flight
                        getline(iss, _dayOfWeek, '_');  // the day of the week if it is weekly

                        istringstream (_flightID) >> fID;       // convert flightID to int
                        istringstream (_airCraftID) >> acID;    // convert aircraft ID to int

                        istringstream (_gateTime) >> gTime;     // convert gate time to int
                        istringstream (_landTime) >> lTime;     // convert land time to int
                        istringstream (_delay) >> del;          // convert the delay to int

                        istringstream (_scheduleType) >> schedule;  // convert schedule to int
                        istringstream (_dayOfWeek) >> dOfWeek;      // convert day of week to int

                        // create an QDate object
                        QDate dateObj = QDate::fromString(QString::fromStdString(_date),"yyyyMMdd");

                        // create an flight object and stick that into a vector
                        flight f = flight(fID,acID,_airLineID,_sCode,_source,_dCode,_destination,gTime,lTime,del,schedule,dateObj,dOfWeek);
                        if (!(f.getDestinationCode().compare(AIRPORT_CODE))){
                            arrivalVector.push_back(f);

                        }else if(!(f.getSourceCode().compare(AIRPORT_CODE))){
                            departureVector.push_back(f);
                        }


		}
		infile.close();
                sort(arrivalVector.begin(), arrivalVector.end(),sortPred);
                sort(departureVector.begin(), departureVector.end(),sortPred);

	}else cout << "Unable to open file"; 
}

flightLoader::~flightLoader(void){}

// returns the arrival flight vector
vector<flight> *flightLoader::getArrival(){
        return &arrivalVector;
}

// returns the departure flight vector
vector<flight> *flightLoader::getDeparture(){
        return &departureVector;
}

void flightLoader::writeFile(){
    writeFile(FLIGHTDATA);
}

// write to file
void flightLoader::writeFile(std::string filename){
        vector<flight> vf, av = arrivalVector, dv = departureVector;
        av.insert( av.end(), dv.begin(), dv.end() );
        vf = av;
        ofstream ofile (filename.c_str());
	if (ofile.is_open()){
		unsigned int i;

		for (i=0; i< vf.size(); i++){
			flight f = vf.at(i);
                        ofile << f.getFlightID() << "_"             // refer the variable names on the top
				  << f.getAircraftID() << "_"
				  << f.getAirline() << "_"
				  << f.getSourceCode() << "_"
				  << f.getSource() << "_"
				  << f.getDestinationCode() << "_"
				  << f.getDestination() << "_"
                                  << f.getGateTimeMins() << "_"
                                  << f.getLandTimeMins() << "_"
                                  << f.getDelay() << "_"
                                  << f.getScheduleType() << "_"
                                  << f.getDate().toString(QString::fromStdString("yyyyMMdd")).toStdString() << "_"
                                  << f.getDayOfWeek();

			if(i<vf.size()-1) ofile << endl;

		}
		ofile.close();
	}else cout << "Unable to open file";


}

// find flight by the id, input the id and returns the flight object corresponding to that object
flight * flightLoader::findByFlightID(int id){

    vector<flight> *arriveVec = getArrival();
    vector<flight> *departVec = getDeparture();
    flight *returnF = new flight();

    for(unsigned int i = 0; i < arriveVec->size(); ++i){
        if (arriveVec->at(i).getFlightID() == id) returnF = &arriveVec->at(i);
    }

    for(unsigned int i = 0; i < departVec->size(); ++i){
        if (departVec->at(i).getFlightID() == id) returnF = &departVec->at(i);

    }
    return returnF;
}

