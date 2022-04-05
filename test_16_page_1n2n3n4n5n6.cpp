#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>

using namespace std;


class Employee
{
	protected:
		int jobType, id, exp, age, d, year, start_work_year;
		string name, dob, contact_num, edu_level;
		float initial_salary, base_salary, rough_salary, nett_salary, epf_socso;
		
	public:
		Employee()
		{
			age = 0;
			year = 2022;
			start_work_year = 2022;
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
			cout << " Enter First Work Year\t: ";
			cin >> start_work_year;	
		}
		
		void calAge()
		{
			switch(dob.length())
			{
				case 8:
					age = year - stoi(dob.substr(4));
					break;
				
				case 9:
					age = year - stoi(dob.substr(5));
					break;
					
				case 10:
					age = year - stoi(dob.substr(6));
					break; 
			}
		}
		
		void calcExp()
		{
			exp = year - start_work_year;
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
		
		void setStartWork(int &set_start_work)
		{
			start_work_year = set_start_work;
		}
		
		void setYear(int &set_year)
		{
			year = set_year;
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
			cout << " Start Work Year: " << start_work_year << endl;
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
		
		int getStartWork()
		{
			return start_work_year;
		}
		
	friend void writeData(Employee *);
};


class Executive : public Employee
{
	private:
		float bonus;
	
	public:
		Executive()
		{
			initial_salary = 2000; // bachelor initial salary
 			d = 300;			   // bachelor difference
			base_salary = 0;
			rough_salary = 0;
			nett_salary = 0;
			epf_socso = 0;
			bonus = 0;	
		}	
		
		void calcBaseSalary()
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
			calcBaseSalary();
			cout << fixed;
			cout << " Base Salary\t: RM " << setprecision(2) << base_salary << endl;
			cout << " " << endl;
			cout << " " << endl;
		}
		
		void setBonus()
		{
			cout << " Enter Bonus\t: RM ";
			cin >> bonus;
		}
		
		void calcRoughSalary()
		{
			rough_salary = base_salary + bonus;
		}
		
		void EPF_Socso()
		{
			epf_socso = rough_salary*(0.09);
		}
		
		void calcNett()
		{
			nett_salary = rough_salary - epf_socso;
		}
		
		float get_RoughSalary()
		{
			return rough_salary;
		}
		
		float get_BaseSalary()
		{
			return base_salary;
		}
		
		float get_EpfSocso()
		{
			return epf_socso;
		}
		
		float get_NettSalary()
		{
			return nett_salary;
		}
};


class BlueCollar : public Employee
{
	private:
		float OT_rate, OT_pay;
		int OT_hours;
		
	public:
		BlueCollar()
		{
			OT_rate = 2.0;
			initial_salary = 1400;
			d = 50;
			base_salary = 0;
			nett_salary = 0;
			OT_hours = 0;
		}
		
		void calcBaseSalary()
		{
			base_salary = initial_salary + ((exp)*(d));
		}
		
		void display_base_salary()
		{
			calcBaseSalary();
			cout << fixed;
			cout << " Base Salary\t: RM " << setprecision(2) << base_salary << endl;
			cout << " " << endl;
			cout << " " << endl;
		}
		
		void set_OtHours()
		{
			cout << " Enter OT Hours\t: ";
			cin >> OT_hours;
		}
		
		void calcOtPay()
		{
			OT_pay = (OT_hours*2)*(base_salary / (26*8));
		}
		
		void calcRoughSalary()
		{
			rough_salary = base_salary + OT_pay;
		}
		
		void ERF_Socso()
		{
			epf_socso = rough_salary*(0.09);
		}
		
		void calcNett()
		{
			nett_salary = rough_salary - epf_socso;
		}
		
		float get_RoughSalary()
		{
			return rough_salary;
		}
		
		float get_BaseSalary()
		{
			return base_salary;
		}
		
		float get_EpfSocso()
		{
			return epf_socso;
		}
		
		float get_NettSalary()
		{
			return nett_salary;
		}
		
		float get_OtPay()
		{
			return OT_pay;
		}
};


class Page
{
	private:
		
		int menu, num_of_lines, compare_id, compare_year, compare_month;
		int round, *fired_ID;
		char repeat_register;
		string which_file, line;
		
		Employee *Emp;
		Executive *Exec;
		BlueCollar *Blue;
		
		// Troublesome parts !!!!
		int emp_jobType, emp_id, emp_exp, emp_age, emp_start_work;
		string emp_name, emp_dob, emp_contact, emp_edu;
		
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
					Emp->calcExp();
					
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
						    emp_contact >> emp_edu >> emp_exp >> emp_start_work;
						    
						    if(compare_id == emp_id)
						    {
						    	Exec[i].setId(emp_id);
						    	Exec[i].setName(emp_name);
						    	Exec[i].setAge(emp_age);
						    	Exec[i].setDOB(emp_dob);
						    	Exec[i].setContact(emp_contact);
						    	Exec[i].setEdu(emp_edu);
						    	Exec[i].setExp(emp_exp);
						    	Exec[i].setStartWork(emp_start_work);
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
						    emp_contact >> emp_edu >> emp_exp >> emp_start_work;
						    
						    if(compare_id == emp_id)
						    {
						    	Blue[i].setId(emp_id);
						    	Blue[i].setName(emp_name);
						    	Blue[i].setAge(emp_age);
						    	Blue[i].setDOB(emp_dob);
						    	Blue[i].setContact(emp_contact);
						    	Blue[i].setEdu(emp_edu);
						    	Blue[i].setExp(emp_exp);
						    	Blue[i].setStartWork(emp_start_work);
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
				}
				else
				{
					which_file = "Blue_Data.txt";
				}
				
				numOfLines(which_file);
				Emp = new Employee[num_of_lines];
				
				// Read Data From a File and Store It
				ifstream infile(which_file);
				
				if(infile.is_open())
				{
					for(int i=0; i<num_of_lines; i++)
					{
						infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
					    emp_contact >> emp_edu >> emp_exp >> emp_start_work;
					    
					    Emp[i].setJobType(emp_jobType);
					    Emp[i].setId(emp_id);
				    	Emp[i].setName(emp_name);
				    	Emp[i].setAge(emp_age);
				    	Emp[i].setDOB(emp_dob);
				    	Emp[i].setContact(emp_contact);
				    	Emp[i].setEdu(emp_edu);
				    	Emp[i].setExp(emp_exp);
				    	Emp[i].setStartWork(emp_start_work);
				    	
				    	// Search Data
				    	if(compare_id == Emp[i].getId())
				    	{
				    		cout << " Name\t\t: " << Emp[i].getName() << endl;
				    		cout << " Age\t\t: " << Emp[i].getAge() << endl;
				    		cout << " Contact Number\t: " << Emp[i].getContact() << endl;
				    		
				    		cout << " " << endl;
				    		cout << " New Contact Number : ";
				    		cin >> emp_contact;
				    		Emp[i].setContact(emp_contact);
				    		
				    		cout << " " << endl;
				    		
				    		compare_id = 0;
						}
						// End -- Search Data
					}
				}
				
				infile.close();
				// End -- Read Data From a File and Store It
				
				
				// Write new update Data to the file
				ofstream outfile(which_file);
				
				if(outfile.is_open())
				{
					for(int i=0; i<num_of_lines; i++)
					{
						outfile <<Emp[i].getJobType() << " "<< Emp[i].getId() << " " << Emp[i].getName() << " "
						<< Emp[i].getDOB() << " " << Emp[i].getAge() << " " << Emp[i].getContact() << " " 
						<< Emp[i].getEdu() << " " << Emp[i].getExp() << " " << Emp[i].getStartWork() << "\n";
					}
				}
				
				outfile.close();
				delete [] Emp;
				// End -- Write new update Data to the file
			}
			
			else if(menu == 4)
			{	
				cout << " " << endl;
				cout << "\t\t Update Employees' Details" << endl;
				cout << " ******************************************************" << endl;
				cout << " This Program will automatically update the Employees'" << endl;
				cout << " based on their D.O.B and their Start Work Year." << endl;
				cout << " " << endl;
				cout << " Enter Year\t: ";
				cin >> compare_year;
				
				round = 2;
				
				for(int j=0; j<round; j++)
				{
					if(j==0)
					{
						which_file = "Exe_Data.txt";
					}
					else if(j==1)
					{
						which_file = "Blue_Data.txt";
					}
					
					numOfLines(which_file);
					Emp = new Employee[num_of_lines];
					ifstream infile(which_file);
					if(infile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
							emp_contact >> emp_edu >> emp_exp >> emp_start_work; 
							
							Emp[i].setJobType(emp_jobType);
						    Emp[i].setId(emp_id);
					    	Emp[i].setName(emp_name);
					    	Emp[i].setAge(emp_age);
					    	Emp[i].setDOB(emp_dob);
					    	Emp[i].setContact(emp_contact);
					    	Emp[i].setEdu(emp_edu);
					    	Emp[i].setExp(emp_exp);
					    	Emp[i].setStartWork(emp_start_work);
					    	Emp[i].setYear(compare_year);
					    	Emp[i].calAge();
					    	Emp[i].calcExp();
						}
					}
					infile.close();
					
					
					ofstream outfile(which_file);
					if(outfile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							outfile << Emp[i].getJobType() << " "<< Emp[i].getId() << " " << Emp[i].getName() << " "
							<< Emp[i].getDOB() << " " << Emp[i].getAge() << " " << Emp[i].getContact() << " " 
							<< Emp[i].getEdu() << " " << Emp[i].getExp() << " " << Emp[i].getStartWork() << "\n";
						}
					}
					outfile.close();
					num_of_lines = 0;
					delete [] Emp;
				}
				
				cout << " " << endl;
				cout << " " << endl;
				cout << " Finish Update " << endl;
				cout << " " << endl;
				cout << " " << endl;
			}
			
			else if(menu == 5)
			{
				cout << " " << endl;
				cout << "\t\t Calculate Employees' Salary" << endl;
				cout << " ******************************************************" << endl;
				
				ofstream outfile("Salary.txt");
				
				round = 2;
				
				for(int j=0; j<round; j++)
				{
					if(j==0)
					{
						num_of_lines = 0;
						
						which_file = "Exe_Data.txt";
						numOfLines(which_file);
						
						Exec = new Executive[num_of_lines];
						
						ifstream infile(which_file);
						if(infile.is_open())
						{
							for(int i=0; i<num_of_lines; i++)
							{
								infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
								emp_contact >> emp_edu >> emp_exp >> emp_start_work;
								
								Exec[i].setJobType(emp_jobType);
								Exec[i].setId(emp_id);
								Exec[i].setName(emp_name);
						    	Exec[i].setAge(emp_age);
						    	Exec[i].setExp(emp_exp);
								Exec[i].calcBaseSalary();

								cout << fixed;
								
								cout << " Job Type\t: " << Exec[i].getJobType() << endl;
								cout << " ID\t\t: " << Exec[i].getId() << endl;
								cout << " Name\t\t: " << Exec[i].getName() << endl;
								cout << " Base Salary\t: RM" << setw(8) << setprecision(2) << Exec[i].get_BaseSalary() << endl;
								Exec[i].setBonus();
								
								Exec[i].calcRoughSalary();
								Exec[i].EPF_Socso();
								Exec[i].calcNett();
								
								cout << " Rough Salary\t: RM" << setw(8) << setprecision(2) << Exec[i].get_RoughSalary() << endl;
								cout << " EPF Socso (9%)\t: RM" << setw(8) << setprecision(2) << Exec[i].get_EpfSocso() << endl;
								cout << " Nett Salary\t: RM" << setw(8) << setprecision(2) << Exec[i].get_NettSalary() << endl;
								
								cout << " " << endl;
								cout << " " << endl;
							}
						}
						infile.close();
						
						if(outfile.is_open())
						{
							for(int i=0; i<num_of_lines; i++)
							{
								outfile << fixed;
								outfile << setw(3) << Exec[i].getJobType() << setw(6) << Exec[i].getId() 
										<< setw(10) << Exec[i].getName()
										<<setw(8) << setprecision(2) << "RM" << Exec[i].get_EpfSocso()
									    << setw(10) << setprecision(2) << "RM" << Exec[i].get_NettSalary() << "\n"; 
							}
						}
						delete [] Exec;
					}
					
					else
					{
						num_of_lines = 0;
						
						which_file = "Blue_Data.txt";
						numOfLines(which_file);
						
						Blue = new BlueCollar[num_of_lines];
						
						ifstream infile(which_file);
						if(infile.is_open())
						{
							for(int i=0; i<num_of_lines; i++)
							{
								infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
								emp_contact >> emp_edu >> emp_exp >> emp_start_work;
								
								Blue[i].setJobType(emp_jobType);
								Blue[i].setId(emp_id);
								Blue[i].setName(emp_name);
								Blue[i].setAge(emp_age);
						    	Blue[i].setExp(emp_exp);
						    	Blue[i].calcBaseSalary();
						    	
						    	cout << fixed;
						    	
						    	cout << " Job Type\t: " << Blue[i].getJobType() << endl;
								cout << " ID\t\t: " << Blue[i].getId() << endl;
								cout << " Name\t\t: " << Blue[i].getName() << endl;
								cout << " Base Salary\t: RM" << setw(8) << setprecision(2) << Blue[i].get_BaseSalary() << endl;
								Blue[i].set_OtHours();
								
								Blue[i].calcOtPay();
								Blue[i].calcRoughSalary();
								Blue[i].ERF_Socso();
								Blue[i].calcNett();
								
								cout << " Total OT Pay\t: RM" << setw(8) << setprecision(2) << Blue[i].get_OtPay() << endl;
								cout << " Rough Salary\t: RM" << setw(8) << setprecision(2) << Blue[i].get_RoughSalary() << endl;
								cout << " EPF Socso (9%)\t: RM" << setw(8) << setprecision(2) << Blue[i].get_EpfSocso() << endl;
								cout << " Nett Salary\t: RM" << setw(8) << setprecision(2) << Blue[i].get_NettSalary() << endl;
								
								cout << " " << endl;
								cout << " " << endl;
							}
							
						}
						infile.close();
						
						if(outfile.is_open())
						{
							for(int i=0; i<num_of_lines; i++)
							{
								outfile << fixed;
								outfile << setw(3) << Blue[i].getJobType() << setw(6) << Blue[i].getId() 
										<< setw(10) << Blue[i].getName()
										<<setw(8) << setprecision(2) << "RM" << Blue[i].get_EpfSocso()
									    << setw(10) << setprecision(2) << "RM" << Blue[i].get_NettSalary() << "\n"; 
							}
						}
						delete [] Blue;
					}
				}
				outfile.close();
			}
			
			else if(menu == 6)
			{
				cout << " " << endl;
				cout << "\t\t Fire Employee(s)" << endl;
				cout << " ******************************************************" << endl;
				cout << " How many Employee to be Fired ? : ";
				cin >> round;
				cout << " " << endl;
				
				fired_ID = new int[round];
				
				for(int j=0; j<round; j++)
				{
					cout << " # Fire --- " << j+1 << endl;
					cout << " Enter ID\t: ";
					cin >> fired_ID[j];
					
					if(fired_ID[j] < 2000)
					{
						which_file = "Exe_Data.txt";
					}
					else
					{
						which_file = "Blue_Data.txt";
					}
					
					numOfLines(which_file);
					Emp = new Employee[num_of_lines];
					
					// Read Data From a File and Store It
					ifstream infile(which_file);
					
					if(infile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							infile >> emp_jobType >> emp_id >> emp_name >> emp_dob >> emp_age >> 
						    emp_contact >> emp_edu >> emp_exp >> emp_start_work;
						    
						    Emp[i].setJobType(emp_jobType);
					    	Emp[i].setId(emp_id);
					    	Emp[i].setName(emp_name);
					    	Emp[i].setAge(emp_age);
					    	Emp[i].setDOB(emp_dob);
					    	Emp[i].setContact(emp_contact);
					    	Emp[i].setEdu(emp_edu);
					    	Emp[i].setExp(emp_exp);
					    	Emp[i].setStartWork(emp_start_work);
					    	
					    	if(fired_ID[j] == Emp[i].getId())
					    	{
					    		cout << " Name\t\t: " << Emp[i].getName() << endl;
					    		
					    		cout << " " << endl;
							}
						}
					}
					infile.close();
					
					ofstream outfile(which_file);
					
					if(outfile.is_open())
					{
						for(int i=0; i<num_of_lines; i++)
						{
							if(fired_ID[j] != Emp[i].getId())
							{
								outfile <<Emp[i].getJobType() << " "<< Emp[i].getId() << " " << Emp[i].getName() << " "
								<< Emp[i].getDOB() << " " << Emp[i].getAge() << " " << Emp[i].getContact() << " " 
								<< Emp[i].getEdu() << " " << Emp[i].getExp() << " " << Emp[i].getStartWork() << "\n";
							}
						}
					}
					num_of_lines = 0;
					outfile.close();
					delete [] Emp;
				}
								
				delete [] fired_ID;
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
						Emp->edu_level << " " << Emp->exp << " " << Emp->start_work_year << "\n";
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
						Emp->edu_level << " " << Emp->exp << " " << Emp->start_work_year << "\n";
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
	
	string space;
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
			cout << " Press Enter to the Home Page";
		}
		
		cin.ignore();
		getline(cin,space);
		
		system("cls");
		
		delete page;
			
	} while(menu_selection != 7);	
	
	
	return 0;
}
