/* 
 * File:   employee.h
 * Author: ericrobinson
 *
 * Created on January 24, 2011, 7:56 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <string>
#include <vector>

using namespace std;

class employee {
public:
    employee();
    employee(const employee& orig);
    virtual ~employee();
    void setEmployeeId(int);
    int getEmployeeId();
    string getFirstName();
    void setFirstName(string);
    string getLastName();
    void setLastName(string);
    void setPunchIn(string);
    vector<string> getPunchIn();
    void setPunchOut(string);
    vector<string> getPunchOut();
    
private:
    int _employeeid;
    string _firstName;
    string _lastName;
    vector<string> punchin;
    vector<string> punchout;

};

#endif	/* EMPLOYEE_H */
