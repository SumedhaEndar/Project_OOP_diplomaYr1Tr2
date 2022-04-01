#include<iostream>
#include<iomanip>
#include <conio.h>
#include <fstream>
#include <string>

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
					break;
				
				case 9:
					age = 2022 - stoi(dob.substr(5));
					break;
					
				case 10:
					age = 2022 - stoi(dob.substr(6));
					break; 
			}
		}
		
	friend void writeData(Employee *);
};


class Page
{
	private:
		int menu;
		char repeat_register;
		Employee *Emp;
		
	public:
		Page()
		{
			repeat_register = 'Y';
			
			cout << " " << endl;
			cout << "\t\t TL3L Group 4 Sdn Bhd" << endl;
			cout << " ******************************************************" << endl;
			cout << " [1] Register New Employee(s) " << endl;
			cout << " [2] Search Employee Details " << endl;
			cout << " [3] Update Contact Number " << endl;
			cout << " [4] Update Employees' Details " << endl;
			cout << " [5] Calculate Employees' Salary " << endl;
			cout << " [6] Fire Employees' Salary " << endl;
			cout << " [7] End Program " << endl;
			cout << " ******************************************************" << endl;
		}
		
		void setMenu(int &m)    // pass by reference using reference arguments
		{
			menu = m;
		}
		
		void display()
		{
			if(menu == 1)
			{
				cout << " " << endl;
				cout << "\t\t Register New Employee(s)" << endl;
				cout << " ******************************************************" << endl;
				
				do
				{
					Emp = new Employee;
					Emp->setDetails();
					Emp->calAge();
					
					writeData(Emp);
					
					delete Emp;
					
					cout << " " << endl;
					cout << " Continue Registering a New Employee ? : ";
					cin >> repeat_register;
					cout << " " << endl;
					
				} while(repeat_register == 'Y');
			}
			
			else if(menu == 2)
			{
				cout << " " << endl;
				cout << "\t\t Search Employee's Details" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 3)
			{
				cout << " " << endl;
				cout << "\t\t Update Contact Number" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 4)
			{
				cout << " " << endl;
				cout << "\t\t Update Employees' Details" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 5)
			{
				cout << " " << endl;
				cout << "\t\t Calculate Employees' Salary" << endl;
				cout << " ******************************************************" << endl;
			}
			
			else if(menu == 6)
			{
				cout << " " << endl;
				cout << "\t\t Fire Employee(s)" << endl;
				cout << " ******************************************************" << endl;
			}
		}
};


void writeData(Employee *Emp)
{
	ofstream Exe_Data, Blue_Data;
	
	if(Emp->jobType == 1)
	{
		Exe_Data.open("Exe_Data.txt",std::ios_base::app); // append write in -- won't clear the previous one
		if(Exe_Data.is_open())
		{
			Exe_Data << Emp->jobType << " " << Emp->id << " " << Emp->name <<" " <<
						Emp->dob << " " << Emp->age << " " << Emp->contact_num << " " <<
						Emp->edu_level << " " << Emp->exp << " " << Emp->date_in << "\n";
			Exe_Data.close();
		}
		
		else
		{
			cout << " Unable to Open File " << endl;	
		}
	}
	else
	{
		Blue_Data.open("Blue_Data.txt",std::ios_base::app); // append write in -- won't clear the previous one
		if(Blue_Data.is_open())
		{
			Blue_Data << Emp->jobType << " " << Emp->id << " " << Emp->name <<" " <<
						Emp->dob << " " << Emp->age << " " << Emp->contact_num << " " <<
						Emp->edu_level << " " << Emp->exp << " " << Emp->date_in << "\n";
			Blue_Data.close();
		}
		
		else
		{
			cout << " Unable to Open File " << endl;	
		}
	}
}


int main()
{
	Page *page;
	
	
	int menu_selection = 0;
	
	do
	{
		page = new Page;
		
		cout << " Enter Menu Selection : ";
		cin >> menu_selection;
		
		system("cls");
		page->setMenu(menu_selection);
		page->display();
		
		
		
		if(menu_selection == 7)
		{
			cout << " Thank you for using this Program"; 
		}
		else
		{
			cout << " Press Space to the Home Page";
		}
		
		getch();
		system("cls");
		
		delete page;
			
	} while(menu_selection != 7);	
	
	
	return 0;
}
