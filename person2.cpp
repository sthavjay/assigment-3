#include "person2.h"
#include <iostream>
#include <string>


using namespace std;
Person::Person(){
  firstName = "";
  lastName = "";
  employeeID = 0;
  companyName = ""
  payRate = 0.0;
  hoursWorked = 0.0;
}

void person:: setFirstName(string fName){ firstName=fName; }
string getFirstName(){  return firstName;}

void   setLastName(string lName) {lastName = lName;}
string getLastName() { return lastName;}

void   setEmployeeId(int id) { employeeID = id; }
int    getEmployeeId(){return employeeID;}

void   setCompanyName(string coName); { companyName = coName;}
string getCompanyName() { return companyName;}

void   setPayRate(float rate) { payRate= rate;}
float  getPayRate(){ return payRate;}

void   setHoursWorked(float hours) { hoursWorked = hours;}
float  getHoursWorked() {retunr hoursWorked;}

float Person :: totalPay() {
total = payRate * hoursWorked ;
return total;
}

string Person:: fullName(){
  name = firstName + "" + lastName;
  return name;
}
