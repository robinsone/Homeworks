/* 
 * File:   flight.h
 * Version: 1.0
 * Author: ericrobinson
 *
 * Created on March 5, 2011, 10:17 AM
 * Modify log:	March ? , 2011 by matt green
                March 12, 2011 by MNK
 *              March 14, 2011 by AC
 */

#ifndef FLIGHT_H
#define	FLIGHT_H
#include <iostream>
#include <string>
#include <QDate>

class flight {

public:
    //constructors
    flight();

        flight(int flightID, int aircraftID, std::string airline, std::string sCode, std::string source, std::string dCode, std::string destination, int gTime, int lTime, int delay, int schedule, QDate date, int dayOfWeek);
    
	virtual ~flight();
	

    //public methods
    void setFlightID(int);
    int getFlightID();
    void setAircraftID(int);
    int getAircraftID();
    void setAirline(std::string);
    std::string getAirline();
    void setSourceCode(std::string);
    std::string getSourceCode();
    std::string getSource();
    void setDestinationCode(std::string);
    std::string getDestinationCode();
    std::string getDestination();
    void setGateTime(int);
    std::string getGateTime();
    int getGateTimeMins();
    void setLandTime(int);
    std::string getLandTime();
    int getLandTimeMins();
    void setDelay(int);
    int getDelay();
    bool isDelayed();
    std::string showStatus();
    void setScheduleType(int);
    int getScheduleType();
    void setDate(QDate);
    QDate getDate();
    void setDayOfWeek(int);
    int getDayOfWeek();

private:

    int _flightID;
    int _aircraftID;
    std::string _airline;
    std::string _sCode;
    std::string _source;
    std::string _dCode;
    std::string _destination;
    int _gTime;
    int _lTime;
    int _delay;
    int _scheduleType;
    QDate _date;
    int _dayOfWeek;
    std::string convertTime(int totalmins);

};

#endif	/* FLIGHT_H */
