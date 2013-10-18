/*
 * File:   flight.cpp
 * Version: 1.0
 * Author: ericrobinson (adapted by matt green)
 * 
 * Created on March 5, 2011, 10:17 AM
 * Modify log:	March 12, 2011 by MNK
 *              March 14, 2011 by AC
 */
#include "flight.h"
#include <sstream>
#include <QDate>

using namespace std;

// initialize an empty flight object
flight::flight(): _flightID (0),_aircraftID(0),_airline(""),_sCode(""),_source(""),_dCode(""),_destination(""),_gTime(0),_lTime(0),_delay(0) {}

// contructor for the flight object
flight::flight(int flightID, int aircraftID, string airline, string sCode, string source, string dCode, string destination, int gTime, int lTime, int delay, int scheduleType, QDate date, int dayOfWeek)
                           : _flightID (flightID),_aircraftID( aircraftID),_airline( airline),_sCode( sCode),_source( source),_dCode( dCode),_destination( destination),_gTime( gTime),_lTime( lTime),_delay( delay), _scheduleType( scheduleType), _date(date), _dayOfWeek( dayOfWeek){}

// deconstructor
flight::~flight() {
}

// set the flight ID
void flight::setFlightID(int flightID) {
    this->_flightID = flightID;
}

// get the flight ID
int flight::getFlightID() {
    return _flightID;
}

// set the aircraft ID
void flight::setAircraftID(int aircraftID) {
    this->_aircraftID = aircraftID;
}

// get the aircraft ID
int flight::getAircraftID() {
    return _aircraftID;
}

// set the airline
void flight::setAirline(string airline) {
    this->_airline = airline;
}

// get the airline
string flight::getAirline() {
    return _airline;
}

// set the source city code
void flight::setSourceCode(string sCode) {
    this->_sCode = sCode;
}

// get the source city code
string flight::getSourceCode() {
    return _sCode;
}

// get the source city long form
string flight::getSource() {
    return _source;
}

// set the destination city code
void flight::setDestinationCode(string dCode) {
    this->_dCode = dCode;
}

// get the desintation code
string flight::getDestinationCode() {
    return _dCode;
}

// get the destination long form
string flight::getDestination() {
    return _destination;
}

// set the gate time
void flight::setGateTime(int gTime){
	
    this->_gTime = gTime;
}

// get the gate time
string flight::getGateTime(){
        return convertTime(_gTime+_delay);
}

// get the gate time in mins
int flight::getGateTimeMins(){
        return _gTime;
}

// set the land time
void flight::setLandTime(int lTime){
    this->_lTime = lTime;
}

// get the land time
string flight::getLandTime(){
        return convertTime(_lTime+_delay);
}    

// get the land time in minutes
int flight::getLandTimeMins(){
        return _lTime;
}

// set the delay
void flight::setDelay (int time){
    if(time==0)
	_delay=0;
    else	
    	_delay = _delay+time;
}

// set the delay
int flight::getDelay(){
    return _delay;
}

//  if the flight is delayed
bool flight::isDelayed (){
    if (_delay == 0) return false;
    else return true;
}

// shows the status of the flight
// -1 = cancelled
// 0 = on time
// 1 = delayed
string flight::showStatus(){
        string status;
        if  (_delay == -1) status = "CANCELLED";
	else if (_delay ==  0) status = "ON TIME";
	else 				   status = "DELAYED";
	return status;
}

// convert time from total minutes to string
string flight::convertTime(int totalmins){
    stringstream out;
    out << totalmins/60 << ":" << totalmins % 60;

    return QTime::fromString(QString::fromStdString(out.str()),QString::fromStdString("hh:m")).toString(QString::fromStdString("hh:mm")).toStdString();
}

// set the schedule type
void flight::setScheduleType(int type){
    this->_scheduleType = type;
}

// get the schedule type
int flight::getScheduleType(){
    return _scheduleType;
}

// set the date
void flight::setDate(QDate date){
    this->_date = date;
}

// get the date
QDate flight::getDate(){
    return _date;
}

// set the day of the week
void flight::setDayOfWeek(int day){
    this->_dayOfWeek = day;
}

// get the day of the week
int flight::getDayOfWeek(){
    return _dayOfWeek;
}
