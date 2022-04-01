#include<iostream>
#include<iomanip>
#include <fstream>

using namespace std;

class Employee
{
	private:
		int jobType, id, exp, age;
		string name, dob, contact_num, edu_level, date_in;
		
	public:		
		void setId(int &set_id)
		{
			id = set_id;
		}
		
		void setName(string &set_name)
		{
			name = set_name;
		}
		
		void setAge(int &set_age)
		{
			age = set_age;
		}
		
		void setContact(string &set_contact)
		{
			contact_num = set_contact;
		}
		
		void setDOB(string &set_dob)
		{
			dob = set_dob;
		}
		
		void setEdu(string &set_edu)
		{
			edu_level = set_edu;
		}
		
		void setExp(int &set_exp)
		{
			exp = set_exp;
		}
		
		void setDateIn(string &set_date_in)
		{
			date_in = set_date_in;
		}
		
		void display()
		{
			cout << " " << endl;
			cout << " Name\t\t: " << name << endl;
			cout << " Age\t\t: " << age << endl;
			cout << " Contact Number\t: " << contact_num << endl;
			cout << " D.O.B\t\t: " << dob << endl;
			cout << " Education Level: " << edu_level << endl;
			cout << " Years of Exp\t: " << exp << endl;
			cout << " Date-In\t: " << date_in << endl;
			cout << " " << endl;
		}
		
		int getId()
		{
			return id;	
		}
};


int num_of_lines_Blue()
{
	int count = 0;
	string line;
	ifstream myfile ("Blue_Data.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			count = count + 1;
		}
		myfile.close();		
	}
	
	else 
	{
		cout << "Unable to open file"; 
		count = 0;
	}
	
	return count;
}	


int main()
{
	Employee *Emp;
	
	ifstream myfile("Blue_Data.txt");
	
	// TroubleSome !!!!!!!!!
	int jobType, id, exp, age, compare_id;
	string name, dob, contact_num, edu_level, date_in;
	// End of TroubleSome
	
	int num_of_lines = num_of_lines_Blue();
	Emp = new Employee[num_of_lines];
 
 	cout << " Enter ID : ";
 	cin >> compare_id;
	
	if(myfile.is_open())
	{
		for(int i=0; i<num_of_lines; i++)
		{
			myfile >> jobType >> id >> name >> dob >> age >> 
		    contact_num >> edu_level >> exp >> date_in;
		    
		    if(compare_id == id)
		    {
		    	Emp[i].setId(id);
		    	Emp[i].setName(name);
		    	Emp[i].setAge(age);
		    	Emp[i].setDOB(dob);
		    	Emp[i].setContact(contact_num);
		    	Emp[i].setEdu(edu_level);
		    	Emp[i].setExp(exp);
		    	Emp[i].setDateIn(date_in);
		    	Emp[i].display();
			}
		}
		
		myfile.close();
	}
	
	else
	{
		cout << " Unable to Open File " << endl;
	}
	
	
	return 0;
}
