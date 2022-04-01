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
		
	friend void writeData(Employee *);
		
};


void writeData(Employee *Emp)
{
	ofstream outData;
	outData.open("testing_file_3.txt",std::ios_base::app);
	if(outData.is_open())
	{
		outData << Emp->jobType << " " << Emp->id << " " << Emp->name <<" " <<
					Emp->dob << " " << Emp->age << " " << Emp->contact_num << " " <<
					Emp->edu_level << " " << Emp->exp << " " << Emp->date_in << "\n";
		outData.close();
	}
	
	else
	{
		cout << " Unable to Open File " << endl;	
	}
}

int main()
{
	Employee *Emp;
	ofstream outData;
	
	char repeat = 'Y';
	
	do
	{
		Emp = new Employee;
	
		Emp->setDetails();
		Emp->calAge();
	
		writeData(Emp);
		
		delete Emp;
		
		cout << " Continue Registering a New Employee ? : ";
		cin >> repeat;
	} while(repeat == 'Y');
	
	
	
	return 0;
}
