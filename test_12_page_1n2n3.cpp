#include<iostream>
#include<iomanip>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;


class Employee
{
	protected:
		int jobType, id, exp, age, d;
		string name, dob, contact_num, edu_level, date_in;
		float initial_salary, base_salary, nett_salary;
		
	public:
		Employee()
		{
			age = 0;
		}
		
		void setDetails()
		{		
			cout << " Enter Job Type\t\t: ";
			cin >> jobType;
			cout << " Enter ID\t\t: ";
			cin >> id;
			
			cin.ignore();
			
			cout << " Enter Name\t\t: ";
			getline(cin,name);
			cout << " Enter D.O.B\t\t: ";
			getline(cin,dob);
			cout << " Enter Contact Number\t: ";
			getline(cin,contact_num);
			cout << " Enter Education Level\t: ";
			getline(cin,edu_level);
			cout << " Enter Years of Exp\t: ";
			cin >> exp;
			
			cin.ignore();
			
			cout << " Enter Date-In\t\t: ";
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
		
		void setJobType(int &set_jobType)
		{
			jobType = set_jobType;
		}
		
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
		
		int getJobType()
		{
			return jobType;
		}
		
		int getId()
		{
			return id;	
		}
		
		int getAge()
		{
			return age;
		}
		
		string getName()
		{
			return name;
		}
		
		string getContact()
		{
			return contact_num;
		}		
		
		string getDOB()
		{
			return dob;
		}
		
		string getEdu()
		{
			return edu_level;
		}
		
		int getExp()
		{
			return exp;
		}
		
		string getDateIn()
		{
			return date_in;
		}
		
	friend void writeData(Employee *);
};


class Executive : public Employee
{
	private:
		int bonus;
	
	public:
		Executive()
		{
			initial_salary = 2000; // bachelor initial salary
 			d = 300;			   // bachelor difference
			base_salary = 0;
			nett_salary = 0;	
		}	
		
		void A_P_calculation()
		{
			
			if(edu_level.find("Diploma") == 0)
			{
				initial_salary = 1700;
				d = 200;
			}
			
			base_salary = initial_salary + ((exp)*(d));
		}
		
		void display_base_salary()
		{
			A_P_calculation();
			cout << fixed;
			cout << " Base Salary\t: RM " << setprecision(2) << base_salary << endl;
			cout << " " << endl;
			cout << " " << endl;
		}
};


class BlueCollar : public Employee
{
	private:
		float OT_rate;
		
	public:
		BlueCollar()
		{
			OT_rate = 2.0;
			initial_salary = 1400;
			d = 50;
			base_salary = 0;
			nett_salary = 0;
		}
		
		void A_P_calculation()
		{
			base_salary = initial_salary + ((exp)*(d));
		}
		
		void display_base_salary()
		{
			A_P_calculation();
			cout << fixed;
			cout << " Base Salary\t: RM " << setprecision(2) << base_salary << endl;
			cout << " " << endl;
			cout << " " << endl;
		}
		
		
};

class Page
{
	private:
		
		int menu, num_of_lines;
		char repeat_register;
		string which_file, line;;
		Employee *Emp;
		Executive *Exec;
		BlueCollar *Blue;
		
		// Troublesome parts !!!!
		int emp_jobType, emp_id, emp_exp, emp_age, compare_id;
		string emp_name, emp_dob, emp_contact, emp_edu, emp_date_in;
		
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
				
				cout << " [1] Executive" << endl;
				cout << " [2] Blue Collar" << endl;
				cout << " " << endl;
				
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
				cout << " Enter ID : ";
				cin >> compare_id;
				
				if(compare_id<2000)
				{
					which_file = "Exe_Data.txt";
				
					numOfLines(which_file);
					Exec = new Executive[num_of_lines];
					
					ifstream myfile(which_file);
					
					if(myfile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							myfile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
						    emp_contact >> emp_edu >> emp_exp >> emp_date_in;
						    
						    if(compare_id == emp_id)
						    {
						    	Exec[i].setId(emp_id);
						    	Exec[i].setName(emp_name);
						    	Exec[i].setAge(emp_age);
						    	Exec[i].setDOB(emp_dob);
						    	Exec[i].setContact(emp_contact);
						    	Exec[i].setEdu(emp_edu);
						    	Exec[i].setExp(emp_exp);
						    	Exec[i].setDateIn(emp_date_in);
						    	Exec[i].display();
						    	Exec[i].display_base_salary();
						    	
						    	compare_id = 0;
							}
						}
						delete [] Exec;
						myfile.close();					
					}
				
					else
					{
						cout << " " << endl;
						cout << " Unable to Open File " << endl;
					}
				}
				
				else
				{
					which_file = "Blue_Data.txt";
				
					numOfLines(which_file);
					Blue = new BlueCollar[num_of_lines];
					
					ifstream myfile(which_file);
					
					if(myfile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							myfile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
						    emp_contact >> emp_edu >> emp_exp >> emp_date_in;
						    
						    if(compare_id == emp_id)
						    {
						    	Blue[i].setId(emp_id);
						    	Blue[i].setName(emp_name);
						    	Blue[i].setAge(emp_age);
						    	Blue[i].setDOB(emp_dob);
						    	Blue[i].setContact(emp_contact);
						    	Blue[i].setEdu(emp_edu);
						    	Blue[i].setExp(emp_exp);
						    	Blue[i].setDateIn(emp_date_in);
						    	Blue[i].display();
						    	Blue[i].display_base_salary();
						    	
						    	compare_id = 0;
							}
						}
						delete [] Blue;
						myfile.close();					
					}
				
					else
					{
						cout << " " << endl;
						cout << " Unable to Open File " << endl;
					}
				}
				
			}
			
			else if(menu == 3)
			{
				cout << " " << endl;
				cout << "\t\t Update Contact Number" << endl;
				cout << " ******************************************************" << endl;
				cout << " Enter ID : ";
				cin >> compare_id;
				cout << " " << endl;
				
				if(compare_id<2000)
				{
					which_file = "Exe_Data.txt";
				
					numOfLines(which_file);
					Exec = new Executive[num_of_lines];
					
					// Read Data From a File and Store It
					ifstream infile(which_file);
					
					if(infile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
						    emp_contact >> emp_edu >> emp_exp >> emp_date_in;
						    
						    Exec[i].setJobType(emp_jobType);
						    Exec[i].setId(emp_id);
					    	Exec[i].setName(emp_name);
					    	Exec[i].setAge(emp_age);
					    	Exec[i].setDOB(emp_dob);
					    	Exec[i].setContact(emp_contact);
					    	Exec[i].setEdu(emp_edu);
					    	Exec[i].setExp(emp_exp);
					    	Exec[i].setDateIn(emp_date_in);
					    	
					    	// Search Data
					    	if(compare_id == Exec[i].getId())
					    	{
					    		cout << " Name\t\t: " << Exec[i].getName() << endl;
					    		cout << " Age\t\t: " << Exec[i].getAge() << endl;
					    		cout << " Contact Number\t: " << Exec[i].getContact() << endl;
					    		
					    		cout << " " << endl;
					    		cout << " New Contact Number : ";
					    		cin >> emp_contact;
					    		Exec[i].setContact(emp_contact);
					    		
					    		cout << " " << endl;
					    		
					    		compare_id = 0;
							}
							// End -- Search Data
						}
					}
										
					else
					{
						cout << " Unable to Open File " << endl;
					}
					
					infile.close();
					// End -- Read Data From a File and Store It
					
					
					// Write new update Data to the file
					ofstream outfile("Exe_Data.txt");
					
					if(outfile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							outfile <<Exec[i].getJobType() << " "<< Exec[i].getId() << " " << Exec[i].getName() << " "
							<< Exec[i].getDOB() << " " << Exec[i].getAge() << " " << Exec[i].getContact() << " " 
							<< Exec[i].getEdu() << " " << Exec[i].getExp() << " " << Exec[i].getDateIn() << "\n";
						}
					}
					
					else
					{
						cout << " Unable to Open File " << endl;
					}
					
					outfile.close();
					
				}
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
		
		void numOfLines(string which_file)
		{
			ifstream myfile(which_file);
			
			if (myfile.is_open())
			{
				while (getline(myfile, line))
				{
					num_of_lines = num_of_lines + 1;
				}
				myfile.close();		
			}
			
			else 
			{
				cout << "Unable to open file"; 
				num_of_lines = 0;
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
