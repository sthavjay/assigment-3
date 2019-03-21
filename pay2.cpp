#include "person2.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void readData(vector<Person> & employees);
void getCompanies (vector<Person> &employees, vector<string> &companyName);
// void printHighestPaid (vector<Person> &employees);
// void seperateAndSave (vector<person> &employees, vector<string> &companyName);

int main(){
  vector<Person> employees;
  vector<string> companyName;
  readData(employees);
  getCompanies (employees,companyName);
  // printHighestPaid(employees);
  // seperateAndSave(employees,companyName);
  return 0;
  }
//------------------------------------------------------------------------------------readData
void readData(vector<Person> &employees)
{
string fName;
string lName;
int id;
string cName;
float hours;
float rate;
Person a;
fstream inputfile;
inputfile.open("input2.txt");
while (!inputfile.eof){
 inputfile>>fName>>lName>>id>>cName>>hours>>rate
  a.setFirstName(fName);
  a.setLastName(lName);
  a.setEmployeeId (id);
  a.setHoursWorked (hours);
  a.setPayRate (rate);

  employees.push_back(a);
}
infile.close();
}


// ---------------------------------------------------------------company name
void getCompanies (vector<Person> &employees, vector<string> &companyName){
string comName;
for(int i= 0; i<employees.size();i++){
  comName = employees[i].getCompanyName();

  if(count (companyName.begin(), companyName.end(),comName) == 0){
    companyName.push_back(comName);
  }
}
}

//----------------------------------------------------------------- highestpaid
// void printHighestPaid (vector<Person> &employees){
// float highest = 0.0;
// int count ;
//   for (int i =0; i<employees.size(); i++) {
//     if (employees.at(i).totalPay()> highest)
//     highest = employees.at(i).totalPay();
//     count = i;
//     }
//     cout << "Highest paid : "<< employees.at(count).fullName<< endl;
//       cout << "Employee ID : "<< employees.at(count).getEmployeeId<< endl;
//         cout << "Employer : "<< employees.at(count).getCompanyName<<endl;
//           cout << "Total Pay : $"<< employees.at(count).totalPay > endl;
//
// }
//
// //---------------------------------------------------------------------
// void seperateAndSave(vector<Person>& employees, vector<string>&companyName) {
//
// float total= 0.0;
// for(int i= 0; i< companyName.size(); i++){
// ofstream outputfile;
// string filename = companyName.at(i)+".txt";
// outputfile.open(filename + ".txt");
// outputfile<< "Company name:"<<filename<<endl;
//     for(int j =0; j<employees.size()-1; j++){
//      if(filename == employees.at(j).getCompanyName()){
//        total += employees.at(j).totalPay();
//        outputfile<<setw(10)<<left<<employees.at((j).fullName()<<"  "<<
//         employees.at(j).getEmployeeId()<< "  "<< employees.at(j).getCompanyName() << " "<< "$" <<employees.at(j).totalPay()<<endl;
// }
// }
//        outputfile<< "Total :" << " " <<" $"<< total<<endl;
//     outputfile.close();
// }
// }
