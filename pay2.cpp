// Bijaya Shrestha
// section 2


#include "person2.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

using namespace std;

void readData(vector<Person> &employees);
void getCompanies (vector<Person> &employees, vector<string> &companyName);
void printHighestPaid (vector<Person> &employees);
void separateAndSave (vector<Person> &employees, vector<string> &companyName);

int main(){
  vector<Person> employees;
  vector<string> companyNames;
  readData(employees);
  getCompanies (employees,companyNames);
  printHighestPaid(employees);
  separateAndSave(employees,companyNames);
  cin.get();
  return 0;
  }
//------------------------------------------------------------------------------------readData
void readData(vector<Person>&employees)
{
string fName;
string lName;
int id;
string cName;
float hours;
float rate;
Person a;
ifstream inputfile;
inputfile.open("input2.txt");
if(inputfile.is_open())
  {
      while (inputfile>>fName>>lName>>id>>cName>>hours>>rate)
      {
        a.setFirstName(fName);
        a.setLastName(lName);
        a.setEmployeeId (id);
        a.setCompanyName(cName);
        a.setHoursWorked (hours);
        a.setPayRate (rate);

        employees.push_back(a);
      }
        inputfile.close();
    }
   else{
     cout << "sorry, cannot open the file."<< endl;
   }
}


// ---------------------------------------------------------------company name
void getCompanies (vector<Person> &employees, vector<string> &companyName)
{
  string comName;
  for(int i= 0; i<employees.size(); i++)
  {
      comName = employees.at(i).getCompanyName();
          if(count (companyName.begin(), companyName.end(),comName) == 0)
          {
              companyName.push_back(comName);
          }
  }
}

//----------------------------------------------------------------- highestpaid
void printHighestPaid(vector<Person> &employees)
{
  float highest;
  int count;
  for (int i = 0; i<employees.size(); i++)
  {
    if (employees.at(i).totalPay()> highest)
    {
          highest = employees.at(i).totalPay();
          count = i;
    }
  }
    cout << "Highest paid : " << employees.at(count).fullName() << endl;
    cout << "Employee ID : "<< employees.at(count).getEmployeeId()<< endl;
    cout << "Employer : "<< employees.at(count).getCompanyName()<<endl;
    cout << "Total Pay : $"<<setprecision(2)<<fixed<< employees.at(count).totalPay()<< endl;
}

//---------------------------------------------------------------------
void separateAndSave(vector<Person>& employees, vector<string>&companyName)
{
float total;
for(int i= 0; i< companyName.size(); i++)
  {
      ofstream output;
      string comp= companyName[i]+ ".txt";
      output.open(comp);
      output << "----------------------------------------------------------"<< endl;
        for(int j =0; j<employees.size()-1; j++)
        {
         if(employees.at(j).getCompanyName()== companyName.at(i))
            {
                total += employees.at(j).totalPay();
                output<<setw(10)<<left<<employees[j].fullName()<<"  "<<
                employees[j].getEmployeeId()<< "  "<< employees[j].getCompanyName() << " "<< "$" <<employees[j].totalPay()<<endl;
            }
        }
       output<<fixed<< setprecision(2)<<"Total " << " " <<" $"<< total << endl;
       output.close();
  }
}
