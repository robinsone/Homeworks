/* 
 * File:   employee.cpp
 * Author: ericrobinson
 * 
 * Created on January 24, 2011, 7:56 PM
 */

#include "employee.h"
#include <string>
#include <vector>

using namespace std;

employee::employee() {
}

employee::employee(const employee& orig) {
}

employee::~employee() {
}

void employee::setEmployeeId(int employeeid) {
    this->_employeeid = employeeid;
}

int employee::getEmployeeId() {
    return _employeeid;
}

string employee::getFirstName() {
    return _firstName;
}

void employee::setFirstName(string _firstName) {
    this->_firstName = _firstName;
}

string employee::getLastName() {
    return _lastName;
}

void employee::setLastName(string _lastName) {
    this->_lastName = _lastName;
}

void employee::setPunchIn(string time){
    this->punchin.push_back(time);
}
vector<string> employee::getPunchIn(){
    return this->punchin;
}
void employee::setPunchOut(string time){
    this->punchout.push_back(time);
}
vector<string> employee::getPunchOut(){
    return this->punchout;
}

