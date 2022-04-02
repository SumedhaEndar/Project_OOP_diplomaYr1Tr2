#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>

using namespace std;

class Employee
{
	private:
		int Id;
		string Name, Contact;
		
	public:
		void setDetails(int &id, string &name, string &contact)
		{
			Id = id;
			Name = name;
			Contact = contact;
		}
		
		void setContact(string &contact)
		{
			Contact = contact;
		}
		
		void display()
		{
			cout << " Name  : " << Name << endl;
			cout << " Contact : " << Contact << endl;
			cout << " " << endl;
		}
		
		int getId()
		{
			return Id;
		}
		
		string getName()
		{
			return Name;
		}
		
		string getContact()
		{
			return Contact;
		}
};




int main()
{
	Employee *Emp;
	Emp = new Employee[2];
	
	int id, compare_id;
	int count;
	string name;
	string contact;
	
	// Read Data from a File and store it
	ifstream infile ("testing_file_2.txt");
	
	if (infile.is_open())
	{
		count = 0;
		
		while(infile >> id >> name >> contact)
		{
			Emp[count].setDetails(id,name, contact);
			count = count + 1;
		}
	}
	
	else
	{
		cout << " Unable to Open File " << endl;
	}
	
	infile.close();
	
	
	// Search Data
	cout << " Enter ID : ";
	cin >> compare_id;
	cout << " " << endl;
	
	for(int i=0; i<count; i++)
	{
		if(compare_id == Emp[i].getId())
		{
			Emp[i].display();
			
			cout << " New Contact Number : ";
			cin >> contact;
			Emp[i].setContact(contact);
		}
	}
	
	
	// Write new update Data to the file
	ofstream outfile;
	
	outfile.open("update_testing_file_2.txt");
	
	if(outfile.is_open())
	{
		for(int i=0; i<count; i++)
		{
			outfile << Emp[i].getId() << " " << Emp[i].getName() << " " << Emp[i].getContact() << "\n";
		}
		
	}
	
	else
	{
		cout << " Unable to Open File " << endl;
	}
	
	outfile.close();
}

