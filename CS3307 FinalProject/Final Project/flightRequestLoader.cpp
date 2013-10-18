#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "flightRequestLoader.h"
#include "flight.h"

using namespace std;

flightRequestLoader::flightRequestLoader(){
        const string AIRPORT_CODE = "YXU";

        string line;

        ifstream infile (FLIGHTREQUESTDATA.c_str());

        if (infile.is_open()){
                while ( infile.good() ){
                        if(infile.eof()) break;
                        getline (infile,line);

                        string _flightID, _airCraftID, _airLineID, _sCode, _source, _dCode, _destination, _gateTime, _landTime, _delay, _scheduleType, _date, _dayOfWeek;
                        int fID, acID, gTime, lTime, del, schedule, dOfWeek;
                        istringstream iss(line);
                        getline(iss, _flightID, '_');
                        getline(iss, _airCraftID, '_');
                        getline(iss, _airLineID, '_');
                        getline(iss, _sCode, '_');
                        getline(iss, _source, '_');
                        getline(iss, _dCode, '_');
                        getline(iss, _destination, '_');
                        getline(iss, _gateTime, '_');
                        getline(iss, _landTime, '_');
                        getline(iss, _delay, '_');
                        getline(iss, _scheduleType, '_');
                        getline(iss, _date, '_');
                        getline(iss, _dayOfWeek, '_');

                        istringstream (_flightID) >> fID;
                        istringstream (_airCraftID) >> acID;

                        istringstream (_gateTime) >> gTime;
                        istringstream (_landTime) >> lTime;
                        istringstream (_delay) >> del;

                        istringstream (_scheduleType) >> schedule;
                        istringstream (_dayOfWeek) >> dOfWeek;

                        QDate dateObj = QDate::fromString(QString::fromStdString(_date),"yyyyMMdd");

                        flight f = flight(fID,acID,_airLineID,_sCode,_source,_dCode,_destination,gTime,lTime,del,schedule,dateObj,dOfWeek);
                        flightRequests.push_back(f);

                }
                infile.close();

        }else cout << "Unable to open file";
}

flightRequestLoader::~flightRequestLoader(void){}

vector<flight> *flightRequestLoader::getFlights(){
        return &flightRequests;
}

void flightRequestLoader::writeFile(){
    writeFile(FLIGHTREQUESTDATA);
}

void flightRequestLoader::writeFile(std::string filename){
        vector<flight> vf = flightRequests;
        ofstream ofile (filename.c_str());
        if (ofile.is_open()){
                unsigned int i;

                for (i=0; i< vf.size(); i++){
                        flight f = vf.at(i);
                        ofile << f.getFlightID() << "_"
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
