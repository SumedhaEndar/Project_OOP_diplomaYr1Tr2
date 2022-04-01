#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>

using namespace std;

class Employee
{
	private:
		int Id;
		string Name;
		
	public:
		void setDetails(int &id, string &name)
		{
			Id = id;
			Name = name;
		}
		
		void display()
		{
			cout << " Name  : " << Name << endl;
			cout << " ID    : " << Id << endl;
		}
};




int main()
{
	Employee *Emp;
	
	ifstream myfile ("testing_file_2.txt");
	
	Emp = new Employee[2];
	int id;
	string name;
	
	if (myfile.is_open())
	{
		for(int i=0; i<2; i++)
		{
			myfile >> id >> name;
			Emp[i].setDetails(id,name);
		}
		
		myfile.close();
	}
	
	for(int i=0; i<2; i++)
	{
		Emp[i].display();
	}
}


