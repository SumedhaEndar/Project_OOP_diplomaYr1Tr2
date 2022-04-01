#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

class Employee
{
	private:
		int jobType, id, exp, age;
		string name, dob, contact_num, edu_level, date_in;
		
	public:
		void setDetails()
		{		
			cout << " Enter Job Type\t: ";
			cin >> jobType;
			cout << " Enter ID\t: ";
			cin >> id;
			
			cin.ignore();
			
			cout << " Enter Name\t: ";
			getline(cin,name);
			cout << " Enter D.O.B\t: ";
			getline(cin,dob);
			cout << " Enter Contact Number\t: ";
			getline(cin,contact_num);
			cout << " Enter Education Level\t: ";
			getline(cin,edu_level);
			cout << " Enter Years of Experience\t: ";
			cin >> exp;
			
			cin.ignore();
			
			cout << " Enter Date-In\t: ";
			getline(cin,date_in);	
		}
		
		void calAge()
		{
			switch(dob.length())
			{
				case 8:
					age = 2022 - stoi(dob.substr(4));
					cout << " Age \t: " << age <<endl;
					break;
				
				case 9:
					age = 2022 - stoi(dob.substr(5));
					cout << " Age \t: " << age <<endl;
					break;
					
				case 10:
					age = 2022 - stoi(dob.substr(6));
					cout << " Age \t: " << age <<endl;
					break; 
			}
		}
		
};

int main()
{
	Employee *Emp;
	
	Emp = new Employee;
	
	Emp->setDetails();
	Emp->calAge();
	
	delete Emp;
	
	return 0;
}
